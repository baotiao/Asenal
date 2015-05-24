#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <event.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

void fifo_read(int fd, short event, void *arg)
{
    char buf[255];
    int len;
    struct event *ev = arg;
    int count = 0;

    /* Reschedule this event */
//    event_add(ev, NULL);

    fprintf(stderr, "fifo_read called with fd: %d, event: %d, arg: %p\n",
        fd, event, arg);
    if (++count == 20) {
        len = read(fd, buf, sizeof(buf) - 1);

        if (len == -1) {
            perror("read");
            return;
        } else if (len == 0) {
            fprintf(stderr, "Connection closed\n");
            return;
        }

        buf[len] = '\0';
        fprintf(stdout, "Read: %s\n", buf);
    }
    printf("over...\n");
}

int main()
{
    struct event evfifo;
    char* fifo = "event.fifo";

    unlink(fifo);
    if (mkfifo(fifo, 0777) == -1) {
        perror("mkfifo");
        exit(1);
    }

    int socket = open(fifo, O_RDWR , 0);
    if (socket == -1) {
        perror("open");
        exit(1);
    }

    fprintf(stderr, "Write data to %s\n", fifo);
    event_init();
    /* Initalize one event */
    event_set(&evfifo, socket, EV_READ , fifo_read, &evfifo);
    /* Add it to the active events, without a timeout */
    event_add(&evfifo, NULL);

    event_dispatch();

    return 0;
}

