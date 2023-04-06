#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stra {
    int a;  //4   4
    float b;//4   8
    char c;//1   12  9
    char arr[7];   //16
    double h;//24
} abc;

struct strb {
    struct stra abc;//12  16
    short f;  //2
    char *e;  //4
    short g;
    //double d; //8
};

int main() {
    struct strb strbb;
    //strbb.d = 10.0f;
    //strbb.abc.a = 100;
    //printf("%d\n", strbb.abc.a);
    printf("%d\n", sizeof(strbb));
}