#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <event.h>
#include <unistd.h>

void keypadhandler(int fd, short event, void* arg) {
    fcntl(fd, F_SETFL, O_NONBLOCK);
    printf("i am here\n");
    struct event *ev = arg;
    printf("%d, %d, %d\n", fd, event, *(int *)arg);
    int ntowrite;
    char buf[3];
    //ntowrite = read(fd, buf, sizeof(buf));
    //struct input_event buff;
    //read(fd, &buff, sizeof(struct input_event));
    //printf("type %d, codd: %d, value %d\n", buff.type, buff.code, buff.value);
}

int main()
{
    struct event ev;
    int fd;
    fd = open("/dev/tty", O_RDONLY);
    //fd = open("/dev/tty", O_RDWR);

    if (fd < 0) {
        puts("can not open \n");
        return -1;
    }
    printf("fd is %d\n", fd);
    //fcntl(fd, F_SETFL, O_NONBLOCK);
    char buf[10];
    int n;

    //n = read(fd, buf, 10);

    printf("after read is come\n");
    event_init();

    event_set(&ev, fd, EV_READ, keypadhandler, &ev);
    printf("after event_set\n");
    event_add(&ev, NULL);
    event_dispatch();
    printf("after sidpatch\n");
    event_del(&ev);
    return 0;
}
