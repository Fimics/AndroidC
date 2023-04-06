#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{
	FILE *fp = NULL;

    //"./"表示根目录
	fp = fopen("./res/test.txt", "w");
	if (fp == NULL)
	{
		perror("fopen error");  //printf("fopen error\n");  :xxxxxxx
		getchar();
		return -1;
	}

	fclose(fp);
	printf("------------finish\n");
    return 0;
}
