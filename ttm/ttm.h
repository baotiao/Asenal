#ifndef __TTM_H__
#define __TTM_H__

#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/proc_fs.h>
#include <linux/err.h>
#include <linux/kthread.h>
#include <linux/time.h>
#include <linux/skbuff.h>
#include <net/sock.h>
#include <net/inet_common.h>
#include <net/tcp.h>
#include <asm/uaccess.h>
#include <linux/netdevice.h>
#include <linux/kallsyms.h>

#define TTM_VERSION "1.0.0.0"

extern int debug_level;

#define TTM_DBG(level, msg...)			\
    do {						\
         if (level <= debug_level) { \
                    printk(KERN_DEBUG "[DEBUG] TTM: " msg);}                   \
    } while (0)

#define TTM_INFO(msg...)			\
     do { \
          if(net_ratelimit()) \
               printk(KERN_INFO "TTM: " msg);\
     } while(0)

#define TCPOPT_TTM  254

/* MUST be 4n !!!! */
#define TCPOLEN_TTM 8		/* |opcode|size|ip+port| = 1 + 1 + 6 */

/* MUST be 4 bytes alignment */
struct ttm_data {
	__u8 opcode;
	__u8 opsize;
	__u16 port;
	__u32 ip;
};

/* statistics about ttm in proc /proc/sys/ttm/ttm_stat */
#ifdef CONFIG_PROC_FS
enum {
	/* statistics for syn proxy */
	SYN_RECV_SOCK_TTM_CNT = 1,
	SYN_RECV_SOCK_NO_TTM_CNT,
	GETNAME_TTM_OK_CNT,
	GETNAME_TTM_MISMATCH_CNT,
	GETNAME_TTM_BYPASS_CNT,
	GETNAME_TTM_EMPTY_CNT,
	TTM_STAT_LAST
};

struct ttm_stats_entry {
	char *name;
	int entry;
};

#define TTM_STAT_ITEM(_name, _entry) { \
        .name = _name,            \
        .entry = _entry,          \
}

#define TTM_STAT_END {    \
        NULL,           \
        0,              \
}

struct ttm_stat_mib {
	unsigned long mibs[TTM_STAT_LAST];
};

#define DEFINE_TTM_STAT(type, name)       \
        __typeof__(type) *name
#define DECLARE_TTM_STAT(type, name)      \
        extern __typeof__(type) *name
#define TTM_INC_STATS(mib, field)         \
        (per_cpu_ptr(mib, smp_processor_id())->mibs[field]++)

extern struct ctl_table_header *sysctl_header;

#define NIPQUAD(addr) \
  ((unsigned char *)&addr)[0], \
  ((unsigned char *)&addr)[1], \
  ((unsigned char *)&addr)[2], \
  ((unsigned char *)&addr)[3]
#define NIPQUAD_FMT "%u.%u.%u.%u"

/*
static inline struct proc_dir_entry *
proc_ttm_fops_create(const char *name, mode_t mode, struct file_operations *fops)
{
	struct proc_dir_entry *res = create_proc_entry(name, mode, sysctl_header->ctl_table->de);
	if (res) {
		res->proc_fops = fops;
	}
	return res;
}

static inline void
proc_ttm_remove(const char *name)
{
	remove_proc_entry(name, sysctl_header->ctl_table->de);
}
*/
#endif				/* ifdef CONFIG_PROC_FS */
#endif
