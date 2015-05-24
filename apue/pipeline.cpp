// g++ pipeline.cpp -I/opt/local/include/thrift -L/opt/local/lib -lthrift -lpthread -lsk_util
#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sankuai/timeused.h>
#include <sankuai/log.h>
#include <concurrency/Monitor.h>

using namespace apache::thrift::concurrency;

struct Stage {
    int32_t   id;
    pthread_t tid;
    int32_t   product;
    bool      bHaveWork;
    Monitor   monitor;// mutex, cond, lock, unlock, signal, wait
    Stage    *next;
};

void * do_stage(void *arg)
{
    Stage * stage = (Stage *)arg;

    (stage->monitor).lock();

    while (true) {
        // 等待任务到来
        while (!stage->bHaveWork) {
            INFO("stage %d wait for task\n", stage->id);
            (stage->monitor).wait();
        }

        // 开始工作
        INFO("stage %d received a work, product=%d\n", stage->id, stage->product);
        sleep(1);
        stage->product += 10;

        // 工作结束，移交工作
        (stage->next->monitor).lock();
        // 等待下一个stage结束工作
        while (stage->next->bHaveWork) {
            (stage->next->monitor).wait();
        }
        // 移交产品
        stage->next->product = stage->product;
        // 设置下一个stage的状态为有工作
        stage->next->bHaveWork = true;
        // 通知下一个stage有任务了
        (stage->next->monitor).notify();
        (stage->next->monitor).unlock();
        // 设置自己的状态为任务结束，即可接受新的任务
        stage->bHaveWork = false;
        // 通知等待我结束任务的上一级stage
        (stage->monitor).notify();
    }
}

void * final_stage(void * arg)
{
    Stage * stage = (Stage *)arg;

    (stage->monitor).lock();

    while (true) {
        TimeUsed_t tu;
        tu.start();
        while (!stage->bHaveWork) {
            (stage->monitor).wait();
        }
        tu.stop("wait_time");
        fprintf(stderr, "final_stage: product=%d, %s\n", stage->product, tu.string());
        stage->bHaveWork = false;
        (stage->monitor).notify();
    }
}
int main()
{
    log_open("pipe.log", (log_level_t)0, "pipeline", 0);
    Stage * stages[10];

    for (int i = 0; i < 10; i++) {
        stages[i] = new Stage;
    }
    for (int i = 0; i < 9; i++) {
        stages[i]->id = i;
        stages[i]->bHaveWork = false;
        stages[i]->next = stages[i+1];
        pthread_create(&(stages[i]->tid), NULL, do_stage, (void *)stages[i]);
    }
    pthread_create(&((stages[9])->tid), NULL, final_stage, stages[9]);

    for (int i = 0; i < 10; i++) {
        (stages[0]->monitor).lock();
        while (stages[0]->bHaveWork) {
            (stages[0]->monitor).wait();
        }
        stages[0]->product = i;
        stages[0]->bHaveWork = true;
        INFO("main: have set work %d\n", i);
        (stages[0]->monitor).notify();
        (stages[0]->monitor).unlock();
    }
    sleep(100);
}
