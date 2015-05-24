#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_NUM 10
#define FILE_NUM 10000

pthread_t tid[THREAD_NUM];
int ans[FILE_NUM];
int buffer[FILE_NUM];
pthread_mutex_t ans_lock[FILE_NUM];
int file_num,thread_num,process_num;
void* thread_routine(void *arg)
{
    int i,j,file_number,num,mx,pid;
    int thread_id = (int)arg;
    struct timeval time1,time2;
    double cost_time = 0.0;
    MPI_Comm_rank(MPI_COMM_WORLD,&pid);
    FILE *fp;
    char file_name[15];
    char *p;
    file_name[0] = 'd';
    file_name[1] = 'a';
    file_name[2] = 't';
    file_name[3] = 'a';
    file_name[4] = '0';
    file_name[5] = '/';
    printf("pid: %d. thread_id: %d\n",pid,thread_id);
    for(j = pid; j < 4; j+=process_num)
    {
        p = file_name;
        p = p + 4;
        *p = j + '1'; 
        for(i = thread_id; i < file_num; i += thread_num)
        {
            mx = -1;
            file_number = 1900 + i;
            p = file_name;
            p = p + 6;
            *p = '0'+file_number/1000; p++; file_number = file_number % 1000;
            *p = '0'+file_number/100; p++; file_number = file_number % 100;
            *p = '0'+file_number/10; p++; file_number = file_number % 10;
            *p = '0'+file_number; p++; 
            *p = '.'; p++;
            *p = 't'; p++;
            *p = 'x'; p++;
            *p = 't'; p++;
            *p = 0;
            //printf("%s\n",file_name);
            fp = fopen(file_name,"r");
            if(fp == NULL)
            {
	        printf(" == !\n");
                printf("%s\n",file_name);
            }
            else{
                gettimeofday(&time1,NULL);
                while(fscanf(fp,"%d",&num)!=EOF)
                {
                    fscanf(fp,"%d",&num);
	            mx = num > mx ? num : mx;
                }
                gettimeofday(&time2,NULL);
                cost_time += (time2.tv_sec - time1.tv_sec) + (time2.tv_usec - time1.tv_usec)/1000000.0;
           }
	    ans[i] = ans[i] > mx ? ans[i] : mx;
        }
    }
    printf("pid: %d. thread_id: %d cost_time: %.6lf\n",pid,thread_id,cost_time);
    pthread_exit(NULL);
}

void calculate(int pid)
{
   int i;
   memset(ans,0,sizeof(ans));
   for(i = 0; i < thread_num; i++)
   {     
       pthread_create(&tid[i],NULL,thread_routine,(void *)i);
   }  
   for(i = 0; i < thread_num; i++)
   {
       pthread_join(tid[i],NULL);
   }
   return; 
}

int main(int argc,char **argv)
{
   int i,j,ret_level,mypid;
   MPI_Status status;
   if(argc != 3)
   {
       printf("USAGE: %s <thread_num> <file_num>\n",argv[0]);
       exit(1);
   }
   //MPI_Init_thread(&(argc),&(argv),MPI_THREAD_MULTIPLE,&ret_level);
   MPI_Init(&(argc),&(argv));
   MPI_Comm_rank(MPI_COMM_WORLD,&mypid);
   MPI_Comm_size(MPI_COMM_WORLD,&process_num);
   thread_num = atoi(argv[1]);
   file_num = atoi(argv[2]);   
   struct timeval time1,time2;
   //printf("%d %d %d\n",mypid,file_num,thread_num);
   //printf("= =!\n");
   gettimeofday(&time1,NULL);
   calculate(mypid);
   if(mypid == 0)
   {
      // calculate(mypid);
       for(i = 1; i < process_num; i++)
       {
           MPI_Recv(buffer,file_num,MPI_INT,i,0,MPI_COMM_WORLD,&status);
           for(j = 0; j < file_num; j++)
           {
               ans[j] = ans[j] > buffer[j] ? ans[j] : buffer[j];
           }
       }
       for(i = 0; i < file_num; i++)
       {
           printf("Max temperature in %d.txt: %d\n",i+1900,ans[i]);
       }
       gettimeofday(&time2,NULL);
       printf("Total runtime: %.6lf.\n",time2.tv_sec-time1.tv_sec + (time2.tv_usec-time1.tv_usec)/1000000.0);
   }
   else
   {
      // calculate(mypid);
       MPI_Send(ans,file_num,MPI_INT,0,0,MPI_COMM_WORLD);
   }
   
   MPI_Finalize();
   return 0;
}
