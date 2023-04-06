#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//定义结构体格式
/*
struct 结构体名称
{
	结构体成员列表

};
//定义结构体变量
 struct 结构体名称 结构体变量名
 结构体变量名.结构体成员列表 = 值
 如果是字符串类型  需要使用strcpy
*/

struct students {
    //成员列表
    char name[21];
    unsigned int age;
    char tel[16];
    float scores[3];
    char sex;
} stu = {"尼古拉斯", 500, "13888888888", 100.0f, 200, 300, 'M'};

int main() {
    //按照结构体顺序 赋值
    //struct  students   stu = { "尼古拉斯",500,"13888888888",100.0f,200,300,'M' };

    //struct  students   stu = { .sex = 'M',.name = "刘能",.tel = "13777777777",.scores[0] = 100,.scores[1] = 99,.scores[2] = 88,.age = 48 };

    //struct students stu;
    ////stu.name = "谢广坤";
    //strcpy(stu.name, "谢广坤");
    //stu.age = 50;
    //strcpy(stu.tel, "13777777778");
    //stu.scores[0] = 90;
    //stu.scores[1] = 80;
    //stu.scores[2] = 70;
    //stu.sex = 'F';

    //strcpy(stu.name, "谢广坤");
    //stu.age = 50;
    //strcpy(stu.tel, "13777777778");
    //stu.scores[0] = 90;
    //stu.scores[1] = 80;
    //stu.scores[2] = 70;
    //stu.sex = 'F';


    printf("姓名：%s\n", stu.name);
    printf("年龄：%d\n", stu.age);
    printf("电话: %s\n", stu.tel);
    printf("成绩: %.1f   %.1f   %.1f\n", stu.scores[0], stu.scores[1], stu.scores[2]);
    printf("性别: %s\n", stu.sex == 'M' ? "男" : "女");
    return 0;
}