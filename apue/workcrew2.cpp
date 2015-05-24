// g++ workcrew2.cpp -I/opt/local/include/thrift -L/opt/local/lib -lthrift -lpthread
#include <concurrency/ThreadManager.h>
#include <concurrency/Thread.h>
#include <concurrency/PosixThreadFactory.h>
#include <boost/shared_ptr.hpp>

using namespace boost;
using namespace apache::thrift::concurrency;

class Task : public Runnable {
public:
    Task(char c) : ch_(c) {}
    void run()
    {
        printf("task=%c, thread_id=%lu\n", ch_, (uint64_t)pthread_self());
    }
private:

    char ch_;
};

int main()
{
    shared_ptr<PosixThreadFactory> threadFactory(new PosixThreadFactory());
    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(30);
    threadManager->threadFactory(threadFactory);

    threadManager->start();

    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            continue;
        shared_ptr<Task> ptr(new Task(c));
        threadManager->add(ptr);
    }
    exit(0);
}
