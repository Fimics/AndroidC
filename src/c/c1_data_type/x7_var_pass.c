#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
 * 	•	函数调用流程
	•	局部变量、函数形参、函数返回地址.. 入栈 和 出栈
	•	调用惯例
	•	主调函数和被调函数必须要有一致约定，才能正确的调用函数，这个约定我们称为调用惯例
	•	调用惯例 包含内容： 出栈方、参数传递顺序、函数名称修饰
	•	C/C++下默认调用惯例： cdecl   从右到左 ，主调函数管理出栈
 * @return
 */

char *func() {
    char *p = malloc(10); //堆区数据，只要没有释放，都可以使用
    int c = 10;//在func中可以使用，test01和main都不可以使用
    return p;
}

void test01() {
    int b = 10; // 在test01 、func 可以使用，在main中不可以用
    func();
}

int main() {
    int a = 10; //在main 、test01 、 func中都可以使用
    test01();
    system("pause");
    return EXIT_SUCCESS;
}