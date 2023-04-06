#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//结构体需要根据数据类型进行内存对齐
//struct stus
//{
//	char name[20];//20
//	unsigned int age;//4
//	char tel[15];//15
//	char sex;//1  52
//	float scores[3];//12
//}stu;

struct stus {
    //char * p;   //4
    //char arr[2];//2  8
    //short d; //2   16
    //int c;  //4
    //long g;//4
    //double f;//8  24
    //float h[2];//8   40


    double f;//8  24
    float h[2];//8   40
    long g;//4
    int c;  //4
    char *p;   //4
    short d; //2   16
    char arr[2];//2  8


    /*
    姓名：  char name[200];
    等级： int
    当前经验：int
    攻击： int
    防御：int
    技能冷却：foat

    */

} stu;


int main() {
    printf("结构体大小%d\n", sizeof(stu));
    return 0;
}
