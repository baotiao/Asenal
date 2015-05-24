/***************************************************************************
 * 
 * Copyright (c) 2012 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file test6.cpp
 * @author wangshaoyan(sat@baidu.com)
 * @date 2012/04/28 14:22:54
 * @version
 * @brief Max device num and max self level name length
 *  
 **/

#include "com_log.h"

int main(int argc, char **argv)
{
	int ret = com_loadlog("./", "test6.conf");
	if (ret != 0) {
		fprintf(stderr, "load err\n");
		return -1;
	}

	int num = 1024000;
	char selflevel[64] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	for (int i = 0; i < num; i++) {
		com_writelog(COMLOG_NOTICE, "hello max %d", i);
	}

	sleep(2);
	com_closelog(600000);

	return 0;
}
