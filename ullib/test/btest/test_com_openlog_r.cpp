#include <com_log.h>
#include <ub_log.h>
#include <gtest/gtest.h>
#include "plugin/plgcomlog.h"

int main(int argc, char **argv)
{
 	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS_IN_PROC();
}

/**
 * @brief 
**/
class test_com_openlog_r_suite : public ::testing::Test{
    protected:
        test_com_openlog_r_suite(){};
        virtual ~test_com_openlog_r_suite(){};
        virtual void SetUp() {
        };
        virtual void TearDown() {
        };
};
 
void *_start_thread1_(void *)
{
	int ret;
	ret = ub_log_initthread("thread1", NULL);
	EXPECT_EQ(ret, 0);

	ret = ul_writelog(4, "Thread1 NOTICE LOG");
	EXPECT_EQ(ret, 0);
	ret = ul_writelog(16, "Thread1 DEBUG LOG");
	EXPECT_EQ(ret, -3);

	EXPECT_COMLOG_INCLUDE("log/openlog.log", "Thread1 NOTICE LOG");
	EXPECT_COMLOG_EXCLUDE("log/openlog.log", "Thread1 DEBUG LOG");

	return NULL;
}

void *_start_thread2_(void *)
{
	int ret;
	ret = com_openlog_r();
	EXPECT_EQ(ret, 0);

	ul_writelog(4, "Thread2 NOTICE LOG");
	ul_writelog(16, "Thread2 DEBUG LOG");

	EXPECT_COMLOG_INCLUDE("log/openlog.log", "Thread2 NOTICE LOG");
	EXPECT_COMLOG_EXCLUDE("log/openlog.log", "Thread2 DEBUG LOG");

	return NULL;
}

TEST_F(test_com_openlog_r_suite, hostname)
{
	unlink("log/openlog.log");

	int ret;
	ret = ub_log_init("log", "openlog.", 2048, 4);
	ASSERT_EQ(ret, 0);

	ret = ul_writelog(4, "Main NOTICE LOG");
	ASSERT_EQ(ret, 0);
	ret = ul_writelog(16, "Main DEBUG LOG");
	EXPECT_EQ(ret, -3);

	EXPECT_COMLOG_INCLUDE("log/openlog.log", "Main NOTICE LOG");
	EXPECT_COMLOG_EXCLUDE("log/openlog.log", "Main DEBUG LOG");

	pthread_t pid;
	pthread_create(&pid, NULL, _start_thread1_, NULL);

	pthread_t pid2;
	pthread_create(&pid2, NULL, _start_thread2_, NULL);

	pthread_join(pid, NULL);
	pthread_join(pid2, NULL);
}
