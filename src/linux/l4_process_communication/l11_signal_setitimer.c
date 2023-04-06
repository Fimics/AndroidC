//周期性定时器
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

//SIGALRM信号处理函数
void sig_handler(int signal_no){
    printf("signal_no=[%d]\n",signal_no);
}

int main() {

    //注册信号处理函数
    signal(SIGALRM,sig_handler);
    struct itimerval tm;
    //周期性时间
    tm.it_interval.tv_sec=1;
    tm.it_interval.tv_usec=0;
    //第一次触发时间
    tm.it_value.tv_sec=3;
    tm.it_value.tv_usec=0;

    setitimer(ITIMER_REAL,&tm,NULL);
    while (1) {
        sleep(1);
    }
    return 0;
}