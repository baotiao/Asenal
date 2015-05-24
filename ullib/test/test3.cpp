/***************************************************************************
 * 
 * Copyright (c) 2008 Baidu.com, Inc. All Rights Reserved
 * $Id: test3.cpp,v 1.2 2009/03/25 12:34:12 yingxiang Exp $ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file test3.cpp
 * @author yingxiang(com@baidu.com)
 * @date 2008/11/06 18:42:19
 * @version $Revision: 1.2 $ 
 * @brief i
 *  
 **/

#include <stdio.h>

#include <string.h>
#include "com_log.h"

void set(char *s, char *src){
	sprintf(s, "%s", src);
	s[strlen(src)] = 0;
}

int main(){
	com_device_t dev;
	set(dev.host, "log");
	set(dev.file, "test3");
	set(dev.type, "ULLOG");
	dev.log_size = 2048;
	dev.open = 1;
	dev.log_mask = (1<<16)-1;
	dev.layout = NULL;
	com_openlog("AAA", &dev, 1, NULL);

	return 0;
}



















/* vim: set ts=4 sw=4 sts=4 tw=100 */
