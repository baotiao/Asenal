#include <ul_net.h>
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
 	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS_IN_PROC();
}

/**
 * @brief 超时时间是15ms，应该是几乎不会超时，但是原来的代码因为有bug，
 * 会频繁超时
**/
class test_ulurl_write_suite : public ::testing::Test{
    protected:
        test_ulurl_write_suite(){};
        virtual ~test_ulurl_write_suite(){};
        virtual void SetUp() {
        };
        virtual void TearDown() {
        };
};
 
TEST_F(test_ulurl_write_suite, server)
{
	int fd = ul_tcplisten(9090, 5);
	if (fd < 0) {
		printf("tcp listion failed\n");
		return;
	}

	struct sockaddr sa;
	socklen_t salen = sizeof(sa);
	int connectfd = ul_accept(fd, &sa, &salen);
	if (connectfd < 0) {
		printf("connect failed\n");
		return;
	}

	int i = 1;
	do {
		char buf[1024*1024 + 1];
		int buf_size = 1024*1024;
		memset(buf, 0, buf_size + 1);
		int timeout = 15;
		int size = ul_sreado_ms_ex(connectfd, buf, buf_size, timeout);
		char res[1024*1024 + 1];
		memset(res, 'a', buf_size);
		res[buf_size] = 0;
		if (size != buf_size) {
			printf("read i=%d failed[size=%d]\n", i, size);
			perror(NULL);
		} else {
			EXPECT_STREQ(res, buf);
			return;
		}
		i++;
	} while (true);

}
