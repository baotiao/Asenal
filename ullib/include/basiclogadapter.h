/***************************************************************************
 * 
 * Copyright (c) 2009 Baidu.com, Inc. All Rights Reserved
 * $Id: basiclogadapter.h,v 1.4 2009/09/18 11:02:57 sun_xiao Exp $ 
 * 
 **************************************************************************/



/**
 * @file basiclogadapter.h
 * @author yingxiang(com@baidu.com)
 * @date 2009/03/05 16:46:36
 * @version $Revision: 1.4 $ 
 * @brief 
 *  
 **/


#ifndef  __BASICLOGADAPTER_H_
#define  __BASICLOGADAPTER_H_

#include "com_log.h"

//Ϊmask????һ????־?ȼ?,maskӦ????һ??uint32_t
#define COMLOG_MASK(mask, level) do{\
	(mask) |= (unsigned int)(1) << (level);\
}while(0)

//Ϊmask????5??Ĭ?ϵ?ϵͳ??־?ȼ?,mask??һ??uint32_t
#define COMLOG_DEFAULT_MASK(mask) do{\
	COMLOG_MASK(mask, COMLOG_FATAL);\
	COMLOG_MASK(mask, COMLOG_WARNING);\
	COMLOG_MASK(mask, COMLOG_NOTICE);\
	COMLOG_MASK(mask, COMLOG_TRACE);\
	COMLOG_MASK(mask, COMLOG_DEBUG);\
}while(0)

/**
 * @brief ??־?ӿڣ????µ???comlog????ullog??ӡ??־
 *        BasicLogAdapter?????ͷ??κ???Դ????��?Լ?????????Դ??
 *        һ??��˵??BasicLogAdapter????????????????????
 *        ??Ҫ?ͷţ?ֻ??ʹ??com_closelog()
 *
 * 		  ????Ĭ??ʹ??ullog??ӡ??־
 *        ??????setCategory, setDevice, setLayout?Ⱥ?????
 *        ???Զ??л???comlog?Ĺ???
 *
 *        setLevel???ܿؿ??أ???comlog/ullog????Ч?????Զ?????־????Լ????
 *
 *        ????Ҫ??ӡ?Զ????ȼ?????־????????ʽ????setLogStat??ʾ????
 *        BasicLogAdapter *p = new BasicLogAdapter();
 *        p->setDevice(xxx);//ע??Device
 *        comspace::LogStat lstat = comspace::LogStat::createLogStat();//??Ҫ??setDevice֮??????
 *        //??ΪcreateLogStat??????comlog????ʼ??֮???ſ???ʹ?ã????Ա?????ִ??setDevice????????????ʼ??
 *        uint32_t level = 0;
 *        COMLOG_DEFAULT_MASK(level);
 *        lstat.setLevel(level, "SelfName1, SelfName2"); //????SelfName1Ҳ??Ҫ???????ļ??е?selfdefine?ж???
 *        p->setLogStat(lstat);
 *        p->write("SelfName1", "This is a self level log...");
 *        //???ߣ?
 *        int self = comspace::getLogId("SelfName1");
 *        p->write(self, "This is also a self level log...");
 *        
 */
class BasicLogAdapter{
	protected:
		//ʵ?ʵ???־??ӡ????
		comspace :: Category * _cate;
		//ϵͳ??־?ȼ?
		int _level;
	public:
		BasicLogAdapter();
		/**
		 * @brief ֱ??????Category?????(comlog)
		 *
		 * @param [in] cate   : comspace::Category*
		 * @return  int 0?ɹ???????ʧ??
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 16:58:57
		**/
		int setCategory(comspace::Category * cate);
		/**
		 * @brief ????comlog???豸 
		 *
		 * @param [in] dev   : com_device_t* ?豸
		 * @param [in] num   : int ?豸??
		 * @return  int -1???���???򷵻سɹ????ӵ??豸??��
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:01:07
		**/
		int setDevice(com_device_t * dev, int num);
		/**
		 * @brief ʹ??logstat??????־?ȼ????ƣ?ֻ??comlog??Ч??
		 *
		 * @param [in] logstat   : comspace::LogStat*
		 * @return  int 0?ɹ???????ʧ??
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:04:07
		**/
		int setLogStat(comspace::LogStat * logstat);
		/**
		 * @brief ??????־??ӡ???ܿصȼ?????????comlog??ӡ????ullog??ӡ??????Ч??
		 *
		 * @param [in] level   : int
		 * @return  int 
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:05:03
		**/
		int setLevel(int level);
        /**
         * @brief ??ȡ??־?ȼ?
         *
         * @return  int 
         * @retval   
         * @author baonh
         * @date 2009/07/25 21:59:36
        **/
        int getLevel();
		/**
		 * @brief ??ӡ??־?ı?׼?ӿ?
		 *
		 * @param [in] level   : int ??־?ȼ?
		 * @param [in] fmt   : const char* ??־????
		 * @return  int 
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:06:03
		**/
		int write(int level, const char * fmt, ...) __attribute__ ((format (printf,3,4)));
		/**
		 * @brief ??ӡ?Զ??弶??????־
		 *
		 * @param [in] level   : const char* ??־?ȼ???
		 * @param [in] fmt   : const char* ??־????
		 * @return  int 
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:06:32
		**/
		int write(const char * level, const char * fmt, ...) __attribute__ ((format (printf,3,4)));
		//----- ???½ӿ??൱??write?İ?װ---
		/**
		 * @brief ??ӡfatal??־
		 *
		 * @param [in] fmt   : const char*
		 * @return  int 
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:08:29
		**/
		int fatal(const char * fmt, ...) __attribute__ ((format (printf,2,3)));
		/**
		 * @brief ??ӡwarning??־
		 *
		 * @param [in] fmt   : const char*
		 * @return  int 
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:08:49
		**/
		int warning(const char * fmt, ...) __attribute__ ((format (printf,2,3)));
		/**
		 * @brief ??ӡnotice??־
		 *
		 * @param [in] fmt   : const char*
		 * @return  int 
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:09:03
		**/
		int notice(const char * fmt, ...) __attribute__ ((format (printf,2,3)));
		/**
		 * @brief ??ӡtrace??־
		 *
		 * @param [in] fmt   : const char*
		 * @return  int 
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:09:14
		**/
		int trace(const char * fmt, ...) __attribute__ ((format (printf,2,3)));
		/**
		 * @brief ??ӡdebug??־
		 *
		 * @param [in] fmt   : const char*
		 * @return  int 
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:09:26
		**/
		int debug(const char * fmt, ...) __attribute__ ((format (printf,2,3)));
	protected:
		/**
		 * @brief ???????µ??õ???־?ӿڣ????ղ???Ϊ?Ѿ??????õ?va_list
		 *
		 * @param [in] level   : int
		 * @param [in] fmt   : const char*
		 * @param [in] args   : va_list
		 * @return  int 
		 * @retval   
		 * @see 
		 * @author yingxiang
		 * @date 2009/03/06 17:09:37
		**/
		int write_args(int level, const char * fmt, va_list args);
		comspace :: Category * tryCategory();
		static int _instance;
		static pthread_mutex_t _lock;
};

















#endif  //__BASICLOGADAPTER_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
