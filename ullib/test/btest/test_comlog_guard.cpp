#include <com_log.h>
#include <ul_log.h>
#include <gtest/gtest.h>

void write_log() {
    static int cnt = 0;
    CFATAL_LOG("-----------the %d(th) call of write_log-----------------", ++cnt);

    CDEBUG_LOG("debug log");
    CTRACE_LOG("trace log");
    CNOTICE_LOG("notice log");
    CWARNING_LOG("warning log");
    CFATAL_LOG("fatal log");
}

int main(int argc, char **argv)
{
     testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS_IN_PROC();
}

/**
 * @brief 
**/
class test_comlog_guard_suite : public ::testing::Test{
    protected:
        test_comlog_guard_suite(){};
        virtual ~test_comlog_guard_suite(){};
        virtual void SetUp() {
        };
        virtual void TearDown() {
        };
};

TEST_F(test_comlog_guard_suite, guard)
{
    int ret;

    ret = com_loadlog("conf", "guard.conf");
    ASSERT_EQ(ret, 0);
    ASSERT_EQ(comlog_get_log_level(), 16);
    write_log();

    comlog_set_log_level(8);
    ASSERT_EQ(comlog_get_log_level(), 8);
    write_log();

    com_reglogstat("conf", "guard.new.conf");
    com_changelogstat();
    ASSERT_EQ(comlog_get_log_level(), 4);
    write_log();

    com_logstat_t logstat;
    logstat.sysevents = 2;
    logstat.userevents[0] = 0;
    com_changelogstat(&logstat);
    ASSERT_EQ(comlog_get_log_level(), 2);
    write_log();

    ret = com_closelog();
    ASSERT_EQ(ret, 0);
}
