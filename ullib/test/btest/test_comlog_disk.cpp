#include <com_log.h>
#include <ul_url.h>
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
 	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS_IN_PROC();
}

/**
 * @brief 
**/
class test_comlog_hostname_suite : public ::testing::Test{
    protected:
        test_comlog_hostname_suite(){};
        virtual ~test_comlog_hostname_suite(){};
        virtual void SetUp() {
        };
        virtual void TearDown() {
        };
};
 
TEST_F(test_comlog_hostname_suite, hostname)
{
	int ret;

	ret = com_loadlog("conf", "quota.conf");
	ASSERT_EQ(ret, 0);

	for (int i = 0; i < 10000000; i++) {
		ret = com_writelog(COMLOG_FATAL, "18da zhengxie");
		ret = com_writelog(COMLOG_DEBUG, "baidu browser 6000,0000 users");
		ret = com_writelog("bit", "bit teacher");
//		sleep(1);
	}
	ASSERT_EQ(ret, 0);

	ret = com_closelog();
	ASSERT_EQ(ret, 0);
}
