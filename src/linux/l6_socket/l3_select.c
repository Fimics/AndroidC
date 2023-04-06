#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>
#include "wrap.h"
//bad file
int main(){
    //创建socket
    int fd = Socket(AF_INET,SOCK_STREAM,0);
    //设置端口复用
    int opt=1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&opt, sizeof(int));

    //绑定 监听
    struct  sockaddr_in serv;
    serv.sin_family=AF_INET;
    serv.sin_port= htons(8888);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    Bind(fd,(struct sockaddr*)&serv,sizeof (serv));
    Listen(fd,128);

    //定义fd_set类型变量
    fd_set  readfds;
    fd_set tmpfds;

    //清空readfds 和tmpfds集合
    FD_ZERO(&readfds);
    FD_ZERO(&tmpfds);

    //所fd加入到readfds中，委托内核监控
    FD_SET(fd,&readfds);

    int maxfd =fd;
    int nready;
    int cfd;
    int i;
    int n;
    int sockfd;
    char buf[1024];

    while (1){
        tmpfds=readfds;
        //tmpfds是输入输出参数
        //输入：告诉内核要检测哪些文件描述符
        //输出:内核告诉应用程序有哪些文件描述符发生了变化
        nready= select(maxfd+1,&tmpfds,NULL,NULL,NULL);
        if (nready<0){
            if (errno==EINTR){
                //被信号中断
                continue;
            }
            break;
        }

        //有客户端连接请求到来
        if (FD_ISSET(fd,&tmpfds)){
            //接受新的客户端连接请求
            cfd= Accept(fd,NULL,NULL);
            //把cfd加科到readfds集合中
            FD_SET(cfd,&readfds);
            //修改内核的监控范围
            if (maxfd<cfd){
                maxfd=cfd;
            }
            if (--nready==0){
                continue;
            }
        }

        //有数据发来的情况
        for (i=fd+1; i < maxfd; i++) {
            sockfd=i;
            //判断sockfd 文件描述符是否有变化
            if (FD_ISSET(sockfd,&tmpfds)){
                //读数据
                memset(buf,0x00,sizeof (buf));
                n= Read(sockfd,buf, sizeof(buf));
                if (n<=0){
                    //关闭连接
                    close(sockfd);
                    //把sockfd 从readfds中删除
                    FD_CLR(sockfd,&readfds);
                } else{
                    printf("n==[%d],buf==[%s]\n",n,buf);
                    int k=0;
                    for (k=0; k < n; k++) {
                        buf[k]= toupper(buf[k]);
                    }
                    Write(sockfd,buf,n);
                }
            }
        }
    }


    return 0;
}
