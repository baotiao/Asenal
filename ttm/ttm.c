#include "ttm.h"

int debug_level = 0;

//MODULE_AUTHOR("sTeeL <steel_mental@gmail.com>");
//MODULE_DESCRIPTION("Tunnel Though Module");
MODULE_LICENSE("GPL");
module_param(debug_level, int, S_IRUGO);
//MODULE_PARM_DESC(debug_level, "debug level");

/* unsigned long sk_data_ready_addr = 0; */

//struct proc_dir_entry *ttm_dir_entry = NULL, *ttm_stats_entry = NULL;

/*******************************************************
 * Statistics of ttm in proc /proc/sys/ttm/ttm_stats *
 *******************************************************/

struct ttm_stats_entry ttm_stats[] = {
	TTM_STAT_ITEM("recv_sock_ttm", SYN_RECV_SOCK_TTM_CNT),
	TTM_STAT_ITEM("recv_sock_no_ttm", SYN_RECV_SOCK_NO_TTM_CNT),
	TTM_STAT_ITEM("getname_ttm_ok", GETNAME_TTM_OK_CNT),
	TTM_STAT_ITEM("getname_ttm_mismatch", GETNAME_TTM_MISMATCH_CNT),
	TTM_STAT_ITEM("getname_ttm_bypass", GETNAME_TTM_BYPASS_CNT),
	TTM_STAT_ITEM("getname_ttm_empty", GETNAME_TTM_EMPTY_CNT),
	TTM_STAT_END
};

DEFINE_TTM_STAT(struct ttm_stat_mib, ext_stats);

#ifdef CONFIG_PROC_FS

#define CTL_TTM 10001
struct ctl_table_header *sysctl_header;
#endif

/* Parse TCP options in skb, try to get client ip, port
 * @param skb [in] received skb, it should be a ack/ack-get packet.
 * @return NULL if we don't get client ip/port;
 *         value of ttm_data in ret_ptr if we get client ip/port.
 */
static void * get_ttm_data(struct sk_buff *skb)
{
	struct tcphdr *th;
	int length;
	unsigned char *ptr;

	struct ttm_data tdata;

	void *ret_ptr = NULL;

	TTM_DBG(12, "get_ttm_data called\n");

	if (NULL != skb) {
		th =(struct tcphdr *)skb_transport_header(skb);
		length = (th->doff * 4) - sizeof (struct tcphdr);
		ptr = (unsigned char *) (th + 1);

		while (length > 0) {
			int opcode = *ptr++;
			int opsize;
			switch (opcode) {
			case TCPOPT_EOL:
				return NULL;
			case TCPOPT_NOP:	/* Ref: RFC 793 section 3.1 */
				length--;
				continue;
			default:
				opsize = *ptr++;
				if (opsize < 2)	/* "silly options" */
					return NULL;
				if (opsize > length)
					return NULL;	/* don't parse partial options */
				if (TCPOPT_TTM == opcode && TCPOLEN_TTM == opsize) {
					memcpy(&tdata, ptr - 2, sizeof (tdata));
					TTM_DBG(12, "find ttm data: ip = %u.%u.%u.%u, port = %u\n", NIPQUAD(tdata.ip),
						ntohs(tdata.port));
					memcpy(&ret_ptr, &tdata, sizeof (ret_ptr));
					TTM_DBG(12, "coded ttm data: %p\n", ret_ptr);
					return ret_ptr;
				}
				ptr += opsize - 2;
				length -= opsize;
			}
		}
	}
	return NULL;
}

/* get client ip from socket 
 * @param sock [in] the socket to getpeername() or getsockname()
 * @param uaddr [out] the place to put client ip, port
 * @param uaddr_len [out] lenth of @uaddr
 * @peer [in] if(peer), try to get remote address; if(!peer), try to get local address
 * @return return what the original inet_getname() returns.
 */
static int
inet_getname_ttm(struct socket *sock, struct sockaddr *uaddr, int *uaddr_len, int peer)
{
	int retval = 0;
	struct sock *sk = sock->sk;
	struct sockaddr_in *sin = (struct sockaddr_in *) uaddr;
	struct ttm_data tdata;

	TTM_DBG(12, "inet_getname_ttm called, sk->sk_user_data is %p\n", sk->sk_user_data);

	/* call orginal one */
	retval = inet_getname(sock, uaddr, uaddr_len, peer);

	/* set our value if need */
	if (retval == 0 && NULL != sk->sk_user_data && peer) {
		/* if (sk_data_ready_addr == (unsigned long) sk->sk_data_ready) { */
			memcpy(&tdata, &sk->sk_user_data, sizeof (tdata));
			if (TCPOPT_TTM == tdata.opcode && TCPOLEN_TTM == tdata.opsize) {
				TTM_INC_STATS(ext_stats, GETNAME_TTM_OK_CNT);
				TTM_DBG(12, "inet_getname_ttm: set new sockaddr, ip %u.%u.%u.%u -> %u.%u.%u.%u, port %u -> %u\n",
						NIPQUAD(sin->sin_addr.s_addr), NIPQUAD(tdata.ip), ntohs(sin->sin_port),
						ntohs(tdata.port));
				sin->sin_port = tdata.port;
				sin->sin_addr.s_addr = tdata.ip;
			} else { /* sk_user_data doesn't belong to us */
				TTM_INC_STATS(ext_stats, GETNAME_TTM_MISMATCH_CNT);
				TTM_DBG(12, "inet_getname_ttm: invalid ttm data, ip %u.%u.%u.%u port %u opcode %u opsize %u\n",
						NIPQUAD(tdata.ip), ntohs(tdata.port), tdata.opcode, tdata.opsize);
			}
		/* } else { */
		/*   TTM_INC_STATS(ext_stats, GETNAME_TTM_BYPASS_CNT); */
		/* } */
	} else { /* no need to get client ip */
		TTM_INC_STATS(ext_stats, GETNAME_TTM_EMPTY_CNT);
	}

	return retval;
}

/* The three way handshake has completed - we got a valid synack -
 * now create the new socket.
 * We need to save ttm data into the new socket.
 * @param sk [out]  the socket
 * @param skb [in] the ack/ack-get packet
 * @param req [in] the open request for this connection
 * @param dst [out] route cache entry
 * @return NULL if fail new socket if succeed.
 */

#if (LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,9))
static struct sock *
tcp_v4_syn_recv_sock_ttm(struct sock *sk, struct sk_buff *skb, struct open_request *req, struct dst_entry *dst)
#else
static struct sock *
tcp_v4_syn_recv_sock_ttm(struct sock *sk, struct sk_buff *skb, struct request_sock *req, struct dst_entry *dst)
#endif
{
	struct sock *newsock = NULL;

	TTM_DBG(12, "tcp_v4_syn_recv_sock_ttm called\n");

	/* call orginal one */
	newsock = tcp_v4_syn_recv_sock(sk, skb, req, dst);

	/* set our value if need */
	if (NULL != newsock && NULL == newsock->sk_user_data) {
		newsock->sk_user_data = get_ttm_data(skb);
		if (NULL != newsock->sk_user_data) {
			TTM_INC_STATS(ext_stats, SYN_RECV_SOCK_TTM_CNT);
		} else {
			TTM_INC_STATS(ext_stats, SYN_RECV_SOCK_NO_TTM_CNT);
		}
		TTM_DBG(12, "tcp_v4_syn_recv_sock_ttm: set sk->sk_user_data to %p\n", newsock->sk_user_data);
	}
	return newsock;
}

/************************
 * Module init and exit *
 ************************/
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,9))
extern struct tcp_func ipv4_specific;
#else
extern struct inet_connection_sock_af_ops ipv4_specific;
#endif

/* replace the functions with our functions */
static inline int
hook_ttm_functions(void)
{
	/* hook inet_getname */
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,9))
	inet_stream_ops.getname = inet_getname_ttm;
#else
	struct proto_ops * inet_stream_ops_p = &inet_stream_ops;
	inet_stream_ops_p->getname = inet_getname_ttm;
#endif
	TTM_INFO("CPU [%u] hooked inet_getname <%p> --> <%p>\n", smp_processor_id(), inet_getname,
		 inet_stream_ops.getname);

	/* hook tcp_v4_syn_recv_sock */
	ipv4_specific.syn_recv_sock = tcp_v4_syn_recv_sock_ttm;
	TTM_INFO("CPU [%u] hooked tcp_v4_syn_recv_sock <%p> --> <%p>\n", smp_processor_id(), tcp_v4_syn_recv_sock,
		 ipv4_specific.syn_recv_sock);
	return 0;
}

/* replace the functions to original ones */
static int
unhook_ttm_functions(void)
{
	/* unhook inet_getname */
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,9))
	inet_stream_ops.getname = inet_getname;
#else
	struct proto_ops * inet_stream_ops_p = &inet_stream_ops;
	inet_stream_ops_p->getname = inet_getname;
#endif

	TTM_INFO("CPU [%u] unhooked inet_getname\n", smp_processor_id());

	/* unhook tcp_v4_syn_recv_sock */
	ipv4_specific.syn_recv_sock = tcp_v4_syn_recv_sock;
	TTM_INFO("CPU [%u] unhooked tcp_v4_syn_recv_sock\n", smp_processor_id());
	return 0;
}

/* module init */
static int
ttm_init(void)
{
	int ret = 0;

	TTM_INFO("TTM " TTM_VERSION " by sTeeL<steel.mental@gmail.com>\n");

	/* alloc statistics array for ttm */
	if (NULL == (ext_stats = alloc_percpu(struct ttm_stat_mib)))
		goto proc_err;

	/* create proc entries */

	/* get the address of function sock_def_readable
	 * so later we can know whether the sock is for rpc, tux or others */
	/* sk_data_ready_addr = kallsyms_lookup_name("sock_def_readable"); */
	/* TTM_INFO("CPU [%u] sk_data_ready_addr = kallsyms_lookup_name(sock_def_readable) = %ld %p\n",  */
	/*    smp_processor_id(), sk_data_ready_addr, sk_data_ready_addr); */
	/* if(0 == sk_data_ready_addr) { */
	/*   TTM_INFO("cannot find sock_def_readable.\n"); */
	/*   goto proc_err; */
	/* } */

	hook_ttm_functions();
	TTM_INFO("ttm loaded\n");
	ret = 0;
	return ret;

proc_err:

	if (NULL != ext_stats) {
		free_percpu(ext_stats);
		ext_stats = NULL;
	}
	return ret;
}

/* module cleanup*/
static void
ttm_exit(void)
{
	unhook_ttm_functions();
	synchronize_net();

	/* remove proc entries */

	if (NULL != sysctl_header) {
		unregister_sysctl_table(sysctl_header);
		sysctl_header = NULL;
	}

	if (NULL != ext_stats) {
		free_percpu(ext_stats);
		ext_stats = NULL;
	}
	TTM_INFO("ttm unloaded\n");
}

module_init(ttm_init);
module_exit(ttm_exit);
