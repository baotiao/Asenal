/***************************************************************************
 * 
 * Copyright (c) 2008 Baidu.com, Inc. All Rights Reserved
 * $Id: fileappender.cpp,v 1.3.2.2 2010/04/05 13:30:46 zhang_rui Exp $ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file fileappender.cpp
 * @author xiaowei(com@baidu.com)
 * @date 2008/03/18 22:29:12
 * @version $Revision: 1.3.2.2 $ 
 * @brief 
 *  
 **/

#include "fileappender.h"
#include "../xdebug.h"
#include "../xutils.h"
#include "../layout.h"
#include "../event.h"
#include "../namemg.h"
#include <stdint.h>

namespace comspace
{

int FileAppender::syncid(void *p)
{
	int ret = 0;
	char mvfile[1024];
	bool needdel = false;
	bool caseevt = false;

	pthread_mutex_lock(&_lock);
	//_com_debug("in syncid now with _id[%d]", _id);
	if (_id > 0) {
		//检查id跟文件名是否对应
		struct stat fst;
		ret = stat(_file, &fst);
		//文件不存在，open之
		if (ret != 0) {
			ret = open(p);
			goto end;
		}
		//_com_debug("%llu %llu", (unsigned long long)fst.st_ino, (unsigned long long)_stat.st_ino);
		//文件存在，但是已经跟当前句柄不符合
		if (fst.st_ino != _stat.st_ino) {
			_com_debug("st_info din't equl");
			ret = open(p);
			goto end;
		} else {
			//根据条件出发一些操作
			//如果日志长度超过指定长度直接回滚
			uint64_t nowsiz = ((uint64_t)_device.log_size) << 20;
			if ((uint64_t)fst.st_size >= nowsiz) {
				save_backup(_file, mvfile, sizeof(mvfile), _device.reserved1);
				if (_quota_filenum > 0) {
					check_quota(mvfile, false);
				}
				ret = open(p);
				caseevt = true;
				_lastcutime = time(0);
			}
			switch (_device.splite_type) {
				case COM_TRUNCT: 
					needdel = true;
					goto end;

				case COM_SIZECUT:
					goto end;

				case COM_DATECUT:
					{
						time_t now = time(0);
						//周期配置单位是分钟
						if (now - _lastcutime > _device.cuttime * 60) {
							save_backup(_file, mvfile, sizeof(mvfile), _device.reserved1);
							if (_quota_filenum > 0) {
								check_quota(mvfile ,false);
							}
							ret = open(p);
							_lastcutime = now;
						}
					}
					break;

				default:
					break;
			}
		}
	} else {
		ret = open(p);
		goto end;
	}
end:
	pthread_mutex_unlock(&_lock);

	if (caseevt && needdel) {
		remove(mvfile);
	}
	return ret;
}

int FileAppender::read_conf()
{
	/* 读取磁盘限额相关配置 */
	char name[WORD_SIZE];

	snprintf(name, sizeof(name), "%s_%s", _device.name, "QUOTA_SIZE");
	ul_getconfint(&(_device.reservedconf), name, &_quota_size);
	snprintf(name, sizeof(name), "%s_%s", _device.name, "QUOTA_DAY");
	ul_getconfint(&(_device.reservedconf), name, &_quota_day);
	snprintf(name, sizeof(name), "%s_%s", _device.name, "QUOTA_HOUR");
	ul_getconfint(&(_device.reservedconf), name, &_quota_hour);
	snprintf(name, sizeof(name), "%s_%s", _device.name, "QUOTA_MIN");
	ul_getconfint(&(_device.reservedconf), name, &_quota_min);

	if (_device.splite_type == COM_SIZECUT) {
		if (_quota_size > _device.log_size) {
			_quota_filenum = _quota_size / _device.log_size;
		}
	} else if (_device.splite_type == COM_DATECUT) {
		int total_min = _quota_day * 24 * 60 + _quota_hour * 60 + _quota_min;
		if (total_min > 0) {
			_quota_filenum = total_min / _device.cuttime;
		}
	}

	return 0;
}

int FileAppender::check_quota(const char *mvfile, bool first)
{
	if (first == true) {
		read_conf();

		if (_quota_filenum <= 0) {
			return 0;
		}

		if (check_quota_first() < 0) {
			_com_error("check quota first failed");
			return -1;
		}
	} else {
		if (_ftsize >= _quota_filenum) {
			unlink(_ft[_head].filepath);
		} else {
			_ftsize++;
		}

		strncpy(_ft[_head].filepath, mvfile, strlen(mvfile));
		_ft[_head].filepath[strlen(mvfile)] = 0;

		if (_head == 0) {
			_head = _quota_filenum - 1;
		} else {
			_head--;
		}
	}

	return 0;
}

int cmp(const void *a, const void *b)
{
	return (*(struct filetime *)a).time < (*(struct filetime *)b).time ? 1 : -1;
}

int FileAppender::check_quota_first()
{
	struct dirent *entry;
	DIR *dp;

	char file[256], filewf[256], filesf[256];
	int filelen = snprintf(file, 256, "%s.", _device.file);
	int filewflen = snprintf(filewf, 256, "%s.wf", _device.file);
	int filesflen = snprintf(filesf, 256, "%s.sf", _device.file);

	/* 扫描日志目录中的文件 */
	dp = opendir(_device.host);
	if (dp == NULL) {
		_com_error("open dir[%s] failed in check quota\n", _device.host);
		return -1;
	}
	int ftsize = 0;
	while ((entry = readdir(dp)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0 ||
			strcmp(entry->d_name, "..") == 0) {
			continue;
		}
		/* 考虑到ullog中有的日志名叫做log.wf.*和log.sf.* */
		if (strncmp(entry->d_name, filewf, filewflen) != 0 &&
			strncmp(entry->d_name, filesf, filesflen) != 0 &&
			strncmp(entry->d_name, file, filelen) == 0) {
			ftsize++;
		}
	}
	closedir(dp);

	if (ftsize < _quota_filenum) {
		ftsize = _quota_filenum;
	}

	_ft = (struct filetime *)malloc(sizeof(struct filetime) * ftsize);
	if (_ft == NULL) {
		_com_error("malloc filetime memory failed[%m]");
		return -1;
	}


	/* 扫描日志目录中的文件 */
	dp = opendir(_device.host);
	if (dp == NULL) {
		_com_error("open dir[%s] failed in check quota\n", _device.host);
		return -1;
	}
	while ((entry = readdir(dp)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0 ||
			strcmp(entry->d_name, "..") == 0) {
			continue;
		}
		/* 考虑到ullog中有的日志名叫做log.wf.*和log.sf.* */
		if (strncmp(entry->d_name, filewf, filewflen) != 0 &&
			strncmp(entry->d_name, filesf, filesflen) != 0 &&
			strncmp(entry->d_name, file, filelen) == 0) {
			snprintf(_ft[_ftsize].filepath, 256, "%s/%s", _device.host,
				entry->d_name);

			struct stat fstat;
			if (::stat(_ft[_ftsize].filepath, &fstat) < 0) {
				_com_error("stat failed[%m]");
				return -1;
			}
			_ft[_ftsize].time = fstat.st_mtime;
			_ftsize++;
		}
	}
	closedir(dp);

	_com_debug("ftsize=%d,  _quota_filenum=%d\n", _ftsize, _quota_filenum);

	qsort(_ft, _ftsize, sizeof(struct filetime), cmp);

	if (_ftsize > _quota_filenum) {
		for (int i = _quota_filenum; i < _ftsize; i++) {
			unlink(_ft[i].filepath);
		}
		_ftsize = _quota_filenum;
	}

	_head = _quota_filenum - 1;

	return 0;
}

int FileAppender::open(void *p)
{
	_com_debug("before close / open id[%d]", _id);
	close(p);
	snprintf(_file, sizeof(_file), "%s/%s", _device.host, _device.file);
	mkdir (_device.host, 0700);
	int fd = ::open(_file, O_CREAT | O_APPEND | O_RDWR, 0666);
	if (fd < 0) {
		_com_error("can't open %s", _file);
		return -1;
	}
	_id = fd;
	_com_debug("-----------open log %s id[%d]", _file, _id);
	return fstat(_id, &_stat);
}

int FileAppender::close(void *)
{
	if (_id < 0) return 0;
	::close(_id);
	_id = -1;
	return 0;
}

int FileAppender::print(Event *evt)
{
	//_com_debug("in find id[%d]", _id);
	if (unInMask(evt->_log_level)) {
		//_com_debug("can't suport this level, [%d][%llx]", evt->_log_level, _mask);
		return 0;
	}
	_layout->format(evt);
	if (syncid(NULL) != 0) {
		_com_error("%s", evt->_render_msgbuf);
                pthread_mutex_lock(&_lock);
		close(NULL);
                pthread_mutex_unlock(&_lock);
		return -1;
	}
	int ret = write(_id, evt->_render_msgbuf, evt->_render_msgbuf_len);
	if (ret != evt->_render_msgbuf_len) {
		_com_error("ret[%d] != len[%d] %m", ret, evt->_render_msgbuf_len);
                pthread_mutex_lock(&_lock);
		close(NULL);
                pthread_mutex_unlock(&_lock);
		return -1;
	}
	return 0;
}

int FileAppender::binprint(void *buf, int siz)
{
	if (syncid(NULL) != 0) {
		return -1;
	}
	int ret = write(_id, buf, siz);
	if (ret != siz) {
		return -1;
	}
	return 0;
}

int FileAppender::reset()
{
	_page = 0;
	_file[0] = 0;
	close(NULL);
	return 0;
}

FileAppender::FileAppender()
{
	_page = 0;
	_file[0] = 0;
	_lastcutime = time(0);
	_quota_size = 0;
	_quota_day = 0;
	_quota_hour = 0;
	_quota_min = 0;
	_quota_filenum = 0;
	_ft = NULL;
	_ftsize = 0;
}

FileAppender::~FileAppender(){
	close(NULL);
	if (_ft) {
		free(_ft);
		_ft = NULL;
	}
}

Appender * FileAppender::getAppender(com_device_t &dev)
{
	_com_debug("wanna get file appender");

	char name[1024];
	snprintf(name, sizeof(name), "FILE:%s/%s", dev.host, dev.file);
	Appender *app = (Appender *)comlog_get_nameMg()->get(type_appender, name);
	if (app == NULL) {
		app = new FileAppender;
		app->setDeviceInfo(dev);
		if (app->syncid(NULL) != 0) {
			_com_error("syncid log[%s] err %m", name);
			delete app;
			return NULL;
		}
		comlog_get_nameMg()->set(name, app);

		/* 第一次启动，读取配置，检查磁盘限额 */
		((FileAppender *)app)->check_quota(NULL, true);

	}
	_com_debug("get file appender");
	return app;
}

Appender * FileAppender::tryAppender(com_device_t &dev)
{
	_com_debug("wanna get file appender");

	char name[1024];
	snprintf(name, sizeof(name), "FILE:%s/%s", dev.host, dev.file);
	Appender *app = (Appender *)comlog_get_nameMg()->get(type_appender, name);
	return app;
}

}
/* vim: set ts=4 sw=4 sts=4 tw=100 */
