#include "stdio.h"

void add(int m,int n){
    printf("m+n=%d\n",m+n);
}

void mins(int m,int n){
    printf("m-b=%d\n",m-n);
}

// 操作 回调到  add  mins
// void(*method)(int,int)  声明好 函数指针
// void 返回值
// (*method) 函数名
// (int,int) 两个参数
void operator(void(*method)(int,int),int m,int n){
    method(m,n);
    printf("method result =%p\n",method);
}

void callback(char *file_name,int current,int total){
    printf("%s 图片压缩的进度是:%d  %d\n",file_name,current,total);
}

void compress(char *file_name,void(*callback)(char * ,int ,int)){
    callback(file_name,20,100);
}

int main(){
    //1.
    operator(add,10,10);
    operator(mins,10,10);

    //2.
    void(*call)(char * ,int ,int);
    call=&callback;
    compress("hello.png",call);
}