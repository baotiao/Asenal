#include <ul_net.h>
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
 	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS_IN_PROC();
}

/**
 * @brief 在和server不同的机器上去跑，每隔5ms就发送1M的数据
**/
class test_ulurl_read_suite : public ::testing::Test{
    protected:
        test_ulurl_read_suite(){};
        virtual ~test_ulurl_read_suite(){};
        virtual void SetUp() {
        };
        virtual void TearDown() {
        };
};
 
TEST_F(test_ulurl_read_suite, client)
{
	int fd = ul_tcpconnect("10.81.39.181", 9090);
	if (fd < 0) {
		printf("tcp connect failed\n");
		return;
	}

	do {
		char buf[1024*1024 + 1];
		int buf_size = 1024*1024;
		int timeout = 500;
		memset(buf, 'a', buf_size);
		buf[buf_size] = 0;
		int size = ul_swriteo_ms_ex(fd, buf, buf_size, timeout);
		if (size != buf_size) {
			printf("write failed[size=%d]\n", size);
			perror(NULL);
			return;
		}
		usleep(5000);
	} while (true);
}
