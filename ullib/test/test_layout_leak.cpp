/**
 * @file test_layout_leak.cpp
 * @author linjieqiong
 * @brief use valgrind to check whether memory leak exists with self-defined layout
 *  
 **/

#include "com_log.h"
#include "comlog/appender/fileappender.h"
#include "ul_log.h"
#include <unistd.h>

int main(){
	com_loadlog("./", "test_layout_leak.conf");
	com_closelog(0);
	return 0;
}
