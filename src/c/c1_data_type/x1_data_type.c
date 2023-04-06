//
// Created by mac on 2021/6/7.
//

#include "stdio.h"

#define PI 3.1415            // 常量

//常量 1
void testCycle() {
    // 圆的面积  s = PI x 半径的平方
    // 圆的周长  l = 2 * PI * r
    //int r = 3;				// 变量
    const int r = 3;        // 只读变量

    float s = PI * r * r;
    float l = 2 * PI * r;

    //printf("圆的周长为：%f\n", l);  //18.849001
    //printf("圆的面积为：%f\n", s);  //28.273500

    printf("圆的周长为：%.2f\n", l);    // 指定小数点后保留2位, 对第3位做，4舍五入
    printf("圆的面积为：%.2f\n", s);    // 指定小数点后保留2位
}

//2
void sizeOf1() {
    int a = 3;
    short b = 4;
    long c = 5;            // 5L  5l
    long long d = 6;  // 5LL  5ll

    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(short) = %d\n", sizeof(short));
    printf("sizeof(long) = %d\n", sizeof(long));
    printf("sizeof(long long) = %d\n", sizeof(long long));

    printf("--------------------------------------\n");

    unsigned int aun = 2;        // 3u
    unsigned short bun = 4;        // 3u
    unsigned long cun = 5;        // 3lu
    unsigned long long dun = 6;    // 3llu

    printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int)); // aun
    printf("sizeof(unsigned short) = %d\n", sizeof(unsigned short));
    printf("sizeof(unsigned long) = %d\n", sizeof(unsigned long));
    printf("sizeof(unsigned long long) = %d\n", sizeof(unsigned long long));
}

//3
void sizeOf3() {
    int a = 10;        // 定义变量： 三要素

    short b = 20;

    long c = 30;
    long long d = 40;

    printf("================a===%d\n", sizeof(a));
    printf("================b===%d\n", sizeof(b));
    printf("================c===%d\n", sizeof(c));
    printf("================d===%d\n", sizeof(d));

    printf("int 大小为：%d\n", sizeof(int));
    printf("short 大小为：%d\n", sizeof(short));
    printf("long 大小为：%d\n", sizeof(long));
    printf("long long 大小为：%d\n", sizeof(long long));

}

//4
void testUnsigned() {
    size_t var = 10;
    printf("var = %u\n", var);

    unsigned int a = 10u;  // 简写成 unsigned int a = 10;
    unsigned short b = 20u;// 简写成 unsigned short b = 20;
    long c = 30u;
    unsigned long long d = 40LLu;

    printf("unsigned int 型数据值：%u\n", a);
    printf("unsigned short 型数据值：%hu\n", b);
    printf("unsigned long 型数据值：%lu\n", c);
    printf("unsigned long long 型数据值：%llu\n", d);
}

//5
void char1() {
    char ch = 'M';
    char var = '5';

    printf("ch = %c\n", ch + 32);
    printf("var = %c\n", var + 4);

    printf("'\\n\'的值为=%d\n", '\n');
}

//6
void char2() {
    char ch = 'A';  // 65

    //printf("1 ch = %c\n", ch);
    printf("1 ch = %d\n", ch);

    ch = 'm'; //

    //printf("2 ch = %c\n", ch);
    printf("2 ch = %d\n", ch);

    //ch = 97;
    ch = 'a';    // 97

    //printf("3 ch = %c\n", ch);
    printf("3 ch = %d\n", ch);
}

//7
void float1() {
    float m = 3.145;
    double n = 4.566545;

    printf("m = % .2f\n", m);
    printf("n = % .4lf\n", n);
}

int main() {
//    testCycle();
    sizeOf1();
//    sizeOf3();
//    testUnsigned();
//    char1();
//    char2();
//    float1();
    return 1;
}
//
// Created by mac on 2023/3/11.
//
