/*
funtion.c
一些复用率高的函数
*/

//库函数引用
#include <stdio.h>
#include <stdlib.h>

//请求用户确认,输入Y和y确认
int FunAskConfirm() {
    char confirm = ' ';
    while(1){
        confirm = getchar();
        rewind(stdin);//清空标准输入缓存区
        if (confirm == 'Y' || confirm == 'y') {
            return 1;
        }
        else if (confirm == 'N' || confirm == 'n') {
            return 0;
        }
        else {
            printf("输入Y或y确认，输入N或n取消\n");
        }
    }
}