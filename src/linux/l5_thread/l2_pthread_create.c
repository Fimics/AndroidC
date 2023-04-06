//
// Created by mac on 2023/3/31.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/types.h"
#include "unistd.h"
#include "pthread.h"

/**
* 创建一个子线程
*/


void *runnable(void *arg){
    printf("child thread,pid==[%d] ,id = [%%ld]\n",getpid(),pthread_self());
}

int main(){

    pthread_t  pthread;
    int result = pthread_create(&pthread,NULL,runnable,NULL);
    if (result!=0){
        printf("pthread_create error,[%s]\n", strerror(result));
        return -1;
    }

    printf("main thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());
    //目的是为了让子线程能够执行起来
    sleep(1);
    return 0;
}