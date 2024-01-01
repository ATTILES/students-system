/*
学生综合测评系统 V1.0
描述：这是一个学生综合测评系统
开发人员：付帅124732023002、刘华炜124732023011
开发时间：2023/12/19开始
Github地址：https://github.com/ATTILES/students-system.git

*/

/*
注：
1.变量命名：小驼峰命名法（首单词开头小写，其余单词开头大写）
2.文件保存格式均采用csv格式
*/

//宏定义
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS //在VS中使用scanf()、strcmp等函数
#endif // !_CRT_SECURE_NO_WARNINGS

//库函数引用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StuInfoFuntion.h"
#include "StuDataFuntion.h"
#include "OtherFuntion.h"

//main函数
int main() {
    int select = 0;
    while (1) {
        showMenu();
        select = -1;
        scanf("%d", &select);
        rewind(stdin);//清空标准输入缓存区
        switch (select) {
        case 1:
            addStuInfo();
            break;
        case 2:
            deleteStuInfo();
            break;
        case 3:
            updateStuInfo();
            break;
        case 4:
            queryStuInfo();
            break;
        case 5:
            showStuInfo();
            break;
        case 6:
            addStuData();
            break;
        case 7:
            deleteStuData();
            break;
        case 8:
            updateStuData();
            break;
        case 9:
            queryStuData();
            break;
        case 10:
            showStuData();
            break;
        case 0:
            exitSystem();
            break;
        default:
            printf("功能编号无效！请输入正确的功能编号。\n");
            break;
        }
        printf("请按enter键确认\n");
        //getchar();
        rewind(stdin);//清空标准输入缓存区
    }
    return 0;
}