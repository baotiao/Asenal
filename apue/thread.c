#include<pthread.h>
#include<stdio.h>
void *msg(void *m)
{
    char *cp = (char *)m;
    int i;
    for(i=0; i<5; i++) {
        printf("%s", cp);
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,msg,(void *)"hello");

    printf("hhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n");
    //pthread_create(&t2,NULL,msg,(void *)"hello");
    pthread_join(t1,NULL);
    //pthread_join(t2,NULL);
    return 0;
}
