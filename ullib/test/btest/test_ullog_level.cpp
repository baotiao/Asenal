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
class test_ullog_level_suite : public ::testing::Test{
    protected:
        test_ullog_level_suite(){};
        virtual ~test_ullog_level_suite(){};
        virtual void SetUp() {
        };
        virtual void TearDown() {
        };
};

/* 没有初始化就调用 */
TEST_F(test_ullog_level_suite, exception)
{
	int ret;

	ret = ul_log_enabled(COMLOG_TRACE);
	ASSERT_EQ(ret, 1);
	ret = ul_log_enabled(0x101);
	ASSERT_EQ(ret, 0);
}
 
TEST_F(test_ullog_level_suite, level)
{
	int ret;

	ul_logstat_t l_stat;
	l_stat.events = 8;
	Ul_log_self self;
	strcpy(self.name[0], "selflog");
	self.flags[0] = 1;
	self.log_number = 1;

	ret = ul_openlog("log", "level", &l_stat, 2048, &self); 
	ASSERT_EQ(ret, 0);

	ret = ul_log_enabled(COMLOG_FATAL);
	ASSERT_EQ(ret, 1);

	ret = ul_log_enabled(COMLOG_TRACE);
	ASSERT_EQ(ret, 1);

	ret = ul_log_enabled(COMLOG_DEBUG);
	ASSERT_EQ(ret, 0);

	ret = com_log_enabled(COMLOG_DEBUG);
	ASSERT_EQ(ret, 0);

	/* 自定义日志 */
	ret = ul_log_enabled(0x100);
	ASSERT_EQ(ret, 1);

	ret = ul_log_enabled(0x101);
	ASSERT_EQ(ret, 0);

	ret = ul_closelog(0);
	ASSERT_EQ(ret, 0);
}
