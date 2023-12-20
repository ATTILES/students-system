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
2.数据文件保存格式均采用csv格式
*/

#define _CRT_SECURE_NO_WARNINGS //在VS中使用scanf()函数

//库函数引用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数声明
void showMenu(); 
void addStuInfo();
void deleteStuInfo();
void updateStuInfo();
void queryStuInfo();
void showStuInfo();
void addStuData();
void deleteStuData();
void updateStuData();
void queryStuData();
void showStuData();
void readStuInfo();//数据文件保存格式均采用csv格式
void writeStuInfo();//数据文件保存格式均采用csv格式
void readStuData();//数据文件保存格式均采用csv格式
void writeStuData();//数据文件保存格式均采用csv格式
void exitSystem();


//结构体类型：学生信息
typedef struct StudentInfomation {
    char id[20];
    char name[20];
    char sex[10];
    char homeAddress[50];
    char phone[20];
}StudentInfo;

//结构体类型：学生数据
typedef struct StudentData{
    char in[20];
    float scoreChinese;
    float scoreMath;
    float scoreEnglish;
    float scoreAverage;
    int scoreRanking;
    float evaluationClassmate;
    float scoreMoral;
    float evaluationTeacher;
    float totalScore;
    int totalRanking;
}StudentData;

//结构体类型：学生
typedef struct Student {
    StudentInfo stuInfo;
    StudentData stuData;
}Student;

//main函数
int main() {
    int select=0;
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
        getchar();
        rewind(stdin);//清空标准输入缓存区
    }
    return 0;
}

//主菜单UI展示
void showMenu() {
    system("cls");  // Windows系统清屏命令  
    printf("**************************************\n");
    printf("********                      ********\n");
    printf("********    学生综合测评系统  ********\n");
    printf("********                      ********\n");
    printf("********    1.添加学生信息    ********\n");
    printf("********    2.删除学生信息    ********\n");
    printf("********    3.修改学生信息    ********\n");
    printf("********    4.查询学生信息    ********\n");
    printf("********    5.浏览学生信息    ********\n");
    printf("********    6.添加学生数据    ********\n");
    printf("********    7.删除学生数据    ********\n");
    printf("********    8.修改学生数据    ********\n");
    printf("********    9.查询学生数据    ********\n");
    printf("********    10.浏览学生数据   ********\n");
    printf("********    0.退出系统        ********\n");
    printf("********                      ********\n");
    printf("**************************************\n");
}

void addStuInfo() {
    printf("This is funtion about addStuInfo\n");
}

void deleteStuInfo() {
    printf("This is funtion about deleteStuInfo()\n");
}

void updateStuInfo() {
    printf("This is funtion about updateStuInfo()\n");
}

void queryStuInfo() {
    printf("This is funtion about queryStuInfo()\n");
}

void showStuInfo() {
    printf("This is funtion about showStuInfo()\n");
}

void addStuData() {
    printf("This is funtion about addStuData\n");
}

void deleteStuData() {
    printf("This is funtion about deleteStuData\n");
}

void updateStuData() {
    printf("This is funtion about updateStuData()\n");
}

void queryStuData() {
    printf("This is funtion about queryStuData()\n");
}

void showStuData() {
    printf("This is funtion about showStuData()\n");
}


void readStuInfo() {
    printf("This is funtion about readStuInfo()\n");
}

void writeStuInfo() {
    printf("This is funtion about writeStuInfo()\n");
}

void readStuData() {
    printf("This is funtion about readStuData()\n");
}

void writeStuData() {
    printf("This is funtion about writeStuData()\n");
}

//退出系统
void exitSystem() {
    printf("确认退出系统？Y/N\n");
    char confirm = ' ';
    confirm = getchar();
    rewind(stdin);//清空标准输入缓存区
    if (confirm == 'Y' || confirm == 'y') {
        exit(0);
    }
    printf("本系统继续运行中...\n");
}