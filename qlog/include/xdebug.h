/**
 * @file xdebug.h
 * @brief debug macros
 * @author chenzongzhi
 * @version 1.0.0
 * @date 2014-04-25
 */

#ifndef  __XDEBUG_H_
#define  __XDEBUG_H_


#ifdef __XDEBUG__
#define qf_debug(fmt, arg...) \
{ \
	fprintf(stderr, "[----------debug--------][%s:%d]" fmt "\n", __FILE__, __LINE__, ##arg); \
}
#define pint(x) qf_debug("%s = %d", #x, x)
#define pstr(x) qf_debug("%s = %s", #x, x)
// 如果A 不对, 那么就输出M
#define qf_check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; }

// 用来检测程序是否执行到这里
#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0;}

#define qf_bin_debug(buf, size) \
{ \
	fwrite(buf, 1, size, stderr); \
}

#define _debug_time_def timeval s, e;
#define _debug_getstart gettimeofday(&s, NULL)
#define _debug_getend gettimeofday(&e, NULL)
#define _debug_time ((int)(((e.tv_sec - s.tv_sec) * 1000 + (e.tv_usec - s.tv_usec) / 1000)))

#define clean_errno() (errno == 0 ? "None" : strerror(errno))
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#else
#define qf_debug(fmt, arg...) {}
#define pint(x) {}
#define pstr(x) {}
#define qf_bin_debug(buf, size) {}

#define _debug_time_def {}
#define _debug_getstart {}
#define _debug_getend {}
#define _debug_time 0

#endif

#define qf_error(fmt, arg...) \
{ \
	fprintf(stderr, "[%ld][%ld][%s:%d]" fmt "\n", (long)getpid(), (long)pthread_self(), __FILE__, __LINE__, ##arg); \
    fflush(stderr);\
}


#endif  //__XDEBUG_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
