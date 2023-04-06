//
// Created by mac on 2023/3/30.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>


//管道基本读写
int pipe_create();

//非阻塞管道
int pipe_no_block();

//管道重定向 使用pipe完成ps aux | grep bash操作
int pipe_dup2();


int main() {
//    pipe_create();
//    pipe_no_block();
    pipe_dup2();
    return 0;
}

int pipe_create() {
    //创建管道
    int fd[2];
    int result = pipe(fd);
    if (result < 0) {
        perror("pipe error");
        return -1;
    }

    //创建子进程
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork error");
        return -1;
    } else if (pid > 0) {
        //父进程 关闭读端
        close(fd[0]);
        sleep(5);
        const char *c = "hello world";
        write(fd[1], "hello world", strlen(c));
    } else {
        //子进程关闭写端
        close(fd[1]);
        char buf[64];
        memset(buf, 0x00, sizeof(buf));
        int n = read(fd[0], buf, sizeof(buf));
        printf("read over ,n==[%d],buf==[%s]", n, buf);
    }
    return 0;
}

int pipe_no_block() {
    //创建管道
    //int pipe(int pipefd[2]);
    int fd[2];
    int ret = pipe(fd);
    if (ret < 0) {
        perror("pipe error");
        return -1;
    }
    printf("pipe size==[%ld]\n", fpathconf(fd[0], _PC_PIPE_BUF));
    printf("pipe size==[%ld]\n", fpathconf(fd[1], _PC_PIPE_BUF));
    //close(fd[0]);
    //write(fd[1], "hello world", strlen("hello world"));

    //关闭写端
    close(fd[1]);
    //设置管道的读端为非阻塞
    int flag = fcntl(fd[0], F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(fd[0], F_SETFL, flag);

    char buf[64];
    memset(buf, 0x00, sizeof(buf));
    int n = read(fd[0], buf, sizeof(buf));
    printf("read over, n==[%d], buf==[%s]\n", n, buf);
    return 0;
}

int pipe_dup2() {

    //创建管道
    //int pipe(int pipefd[2]);
    int fd[2];
    int ret = pipe(fd);
    if (ret < 0) {
        perror("pipe error");
        return -1;
    }

    //创建子进程
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork error");
        return -1;
    } else if (pid > 0) {
        //关闭读端
        close(fd[0]);
        //将标准输出重定向到管道的写端
        dup2(fd[1], STDOUT_FILENO);
        execlp("ps", "ps", "aux", NULL);
        perror("execlp error");
    } else {
        //关闭写端
        close(fd[1]);
        //将标准输入重定向到管道的读端
        dup2(fd[0], STDIN_FILENO);
        execlp("grep", "grep", "--color=auto", "bash", NULL);
        perror("execlp error");
    }
    return 0;
}