#include <com_log.h>
#include <ul_log.h>
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
 	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS_IN_PROC();
}

/**
 * @brief 
**/
class test_comlog_level_suite : public ::testing::Test{
    protected:
        test_comlog_level_suite(){};
        virtual ~test_comlog_level_suite(){};
        virtual void SetUp() {
        };
        virtual void TearDown() {
        };
};

/* 没有初始化就调用 */
TEST_F(test_comlog_level_suite, exception)
{
	int ret;

	ret = com_log_enabled(COMLOG_TRACE);
	ASSERT_EQ(ret, 1);
	ret = com_log_enabled(COMLOG_DEBUG);
	ASSERT_EQ(ret, 1);

	ret = com_log_enabled("noexist");
	ASSERT_EQ(ret, 0);
}
 
TEST_F(test_comlog_level_suite, level)
{
	int ret;

	ret = com_loadlog("conf", "level.conf");
	ASSERT_EQ(ret, 0);

	ret = com_log_enabled(COMLOG_FATAL);
	ASSERT_EQ(ret, 1);

	ret = com_log_enabled(COMLOG_TRACE);
	ASSERT_EQ(ret, 1);

	ret = com_log_enabled(COMLOG_DEBUG);
	ASSERT_EQ(ret, 0);

	ret = com_log_enabled(7);
	ASSERT_EQ(ret, 0);

	/* 自定义日志 */
	ret = com_log_enabled("level1");
	ASSERT_EQ(ret, 1);

	ret = com_log_enabled("level2");
	ASSERT_EQ(ret, 0);

	/* ullog切换测试 */
	ret = ul_log_enabled(COMLOG_FATAL);
	ASSERT_EQ(ret, 1);

	ret = com_closelog();
	ASSERT_EQ(ret, 0);
}
