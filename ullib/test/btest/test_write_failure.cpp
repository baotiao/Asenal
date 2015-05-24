#include <com_log.h>
#include <ul_url.h>
#include <gtest/gtest.h>
#include <errno.h>
#include "common.h"
#include "fault.h"

int main(int argc, char **argv)
{
 	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS_IN_PROC();
}

/**
 * @brief 
**/
class test_comlog_write_failure_suite : public ::testing::Test{
    protected:
        test_comlog_write_failure_suite(){};
        virtual ~test_comlog_write_failure_suite(){};
        virtual void SetUp() {
        };
        virtual void TearDown() {
        };
};

ssize_t FAULT_(write)(int fd, const void *buf, size_t count)
{
    typedef ssize_t (*REALWRITE)(int,const void*,size_t);
    REALWRITE realwrite = (REALWRITE)get_real_func("write");
	if(NULL == realwrite){
        printf("realfun write error");
        return -1;
    }
	int err = 0;
   	int ret = fault_fail("write", &err);
	if(ret == 0) {
		errno = err;
		return -1;
	}
    return realwrite(fd,buf,count);
}


TEST_F(test_comlog_write_failure_suite, write_failure)
{
	int ret = com_loadlog("conf", "slave_log.conf");
	ASSERT_EQ(ret, 0);

	attach_func("write", (void *)FAULT_(write));
	fault_enable("write", 100, -1);

	for(int i=0; i<100; ++i){
		ret = com_writelog(COMLOG_FATAL, "write failure test");
		EXPECT_EQ(ret, 0);
	}

	ret = com_closelog();
	ASSERT_EQ(ret, 0);
}

