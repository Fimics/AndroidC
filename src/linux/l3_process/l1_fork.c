//
// Created by mac on 2023/3/30.
//

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/types.h"
#include "unistd.h"

int fork_test();

int fork_var();

int fork_loop();

//父子进程不能共享全局变量.
int g_var = 99;

int main() {
//    fork_test();
//    fork_var();
    fork_loop();
    return 0;
}

int fork_test() {
    printf("before for poad:[%d]\n", getpid());
    //创建子进程
    pid_t pid = fork();
    //fork失败的情况
    if (pid < 0) {
        perror("fork error");
        return -1;
    } else if (pid > 0) {
        //父进程
        printf("father: [%d], pid==[%d], fpid==[%d]\n", pid, getpid(), getppid());
        sleep(1);
    } else if (pid == 0) {
        //子进程
        printf("child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
    }
    printf("after fork, pid:[%d]\n", getpid());
}

int fork_var() {
    //创建子进程
    pid_t pid = fork();
    if (pid < 0) {
        //fork失败的情况
        perror("fork error");
        return -1;
    } else if (pid > 0) {
        //父进程
        printf("father: [%d], pid==[%d], fpid==[%d]\n", pid, getpid(), getppid());
        g_var++;
        printf("[%p]", &g_var);
    } else if (pid == 0) {
        //子进程
        sleep(1); //为了避免父进程还没有执行, 子进程已经结束了
        printf("[%p]", &g_var);
        printf("child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
        printf("child: g_var==[%d]\n", g_var);
    }
    return 0;
}

/**
 * //循环创建n个子进程
 * @return
 */
int fork_loop() {
    int i = 0;
    for (i = 0; i < 3; i++) {
        //创建子进程
        pid_t pid = fork();
        if (pid < 0) {
            //fork失败的情况
            perror("fork error");
            return -1;
        } else if (pid > 0) {
            //父进程
            printf("father: pid==[%d], fpid==[%d]\n", getpid(), getppid());
            //sleep(1);
        } else if (pid == 0) {
            //子进程
            printf("child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
            break;
        }
    }

    //第1个子进程
    if (i == 0) {
        printf("[%d]--[%d]: child\n", i, getpid());
    }

    //第2个子进程
    if (i == 1) {
        printf("[%d]--[%d]: child\n", i, getpid());
    }
    //第3个子进程
    if (i == 2) {
        printf("[%d]--[%d]: child\n", i, getpid());
    }
    //父进程
    if (i == 3) {
        printf("[%d]--[%d]: child\n", i, getpid());
    }
    sleep(10);

    return 0;
}