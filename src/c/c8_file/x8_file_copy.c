#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void file_cp() {
    FILE *rfp = fopen("./res/q.avi", "rb");
    FILE *wfp = fopen("./res/p.avi", "wb");

    char buf[4096] = {0};  // 缓冲区。

    int ret = 0;

    while (1) {
        memset(buf, 0, sizeof(buf));
        ret = fread(buf, 1, sizeof(buf), rfp);
        if (ret == 0) {
            break;
        }
        printf("ret = %d\n", ret);
        fwrite(buf, 1, ret, wfp);
    }

    fclose(wfp);
    fclose(rfp);
}

int main(void) {
    file_cp();
    printf("---------------------finish\n");
    return EXIT_SUCCESS;
}
