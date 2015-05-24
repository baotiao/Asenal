#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <event.h>

void signalhandler(int fd, short type, void *arg){
    struct event *signal_event = (struct event *)arg;
    static int count = 0;
    printf("in function signal_cb...\n");
    printf("handle signal: %d\n", EVENT_SIGNAL(signal_event));
    if (count >= 3)
        event_del(signal_event);
    count ++;
    struct event *ev = arg;
    printf("SIGINT triggered!!!\n");
}

int main (int argc, char * argv[]){
    struct event ev;

    event_init();

    event_set(&ev, SIGINT, EV_SIGNAL | EV_PERSIST, signalhandler, &ev);
    event_add(&ev, NULL);
    //event_del(&ev);
    event_dispatch();

    return 0;
}
