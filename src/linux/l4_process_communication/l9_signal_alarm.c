//signal函数测试---注册信号处理函数
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//信号处理函数
void sighandler(int signo) {
    printf("signo==[%d]\n", signo);
}

int main() {
    //注册信号处理函数
    signal(SIGINT, sighandler);
    signal(SIGALRM, sighandler);

    int n = alarm(5);
    printf("first: n==[%d]\n", n);

    sleep(2);
    n = alarm(5);
    //n = alarm(0); //取消时钟
    printf("second: n==[%d]\n", n);

    while (1) {
        sleep(10);
    }
    return 0;
}
