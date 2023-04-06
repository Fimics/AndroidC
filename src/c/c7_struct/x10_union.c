#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//共用体(共用最大类型数据结构)   union 共用体名称  成员列表  共用体变量名
union vars {
    double a;
    float b;
    int c;
    short d;
    char f;
    //char arr[17];//17
} var;

int main() {
    printf("%d\n", sizeof(var));
    var.a = 100;
    var.b = 3.14;
    var.c = 66;
    printf("%f\n", var.a);
    printf("%f\n", var.b);
    printf("%d\n", var.c);
}