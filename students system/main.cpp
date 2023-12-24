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
#define MAX 100                 //最大数据支撑100个学生

//库函数引用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funtion.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//结构体类型：学生信息
typedef struct StudentInfomation {
    char  id[20];
    char name[20];
    char sex[10];
    char homeAddress[100];
    char phone[20];
    struct StudentInfomation* next;
}StudentInfo,*Pointer;



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

//函数声明
void readStuInfo(StudentInfo stu[]);
void showMenu();
void addStuInfo(Pointer* Head);
void deleteStuInfo();
void updateStuInfo();
void queryStuInfo();
void addStuData();
void deleteStuData();
void updateStuData();
void queryStuData();
void showStuInfo();
void showStuData();
void readStuData();//数据文件保存格式均采用csv格式
void writeStuData();//数据文件保存格式均采用csv格式
void exitSystem();
void writeStuInfo(Pointer head);
void clearStuInfo(StudentInfo stu[], int size);// 清空结构体缓存
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//main函数
int main() {
    Pointer Head = NULL;
    int select=0;
    while (1) {
        showMenu();
        select = -1;
        scanf("%d", &select);
        rewind(stdin);//清空标准输入缓存区
        switch (select) {
            case 1:
                addStuInfo(&Head);
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

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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


void readStuInfo(StudentInfo stu[])
{
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "r")) == NULL)
    {
        printf("无法打开文件");
        fclose(fp);
        return;
    }
    else
    {
        char line[100];
        int i=0;
        while (fgets(line, sizeof(line), fp) != NULL) // 逐行读取文件内容
        {
            if(i==MAX)
            {
                break;
            }
           sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s", stu[i].id, stu[i].name, stu[i].sex, stu[i].homeAddress, stu[i].phone);
           i++;
        }

        fclose(fp);
    }
}

void addStuInfo(Pointer* head)      //添加学生信息
{
    int num;
    printf("请输入要添加的学生数量：");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        Pointer p, q, r;
        char in_number[20];

        printf("请输入学号：");
        scanf("%s", in_number);

        p = q = *head;
        while (p != NULL) {
            if (strcmp(p->id, in_number) == 0) {
                printf("已经有相同的学号：");
                return;
            }
            else {
                q = p;
                p = p->next;  //走链判断是否存在这个学号信息
            }
        }

        r = (Pointer)malloc(sizeof(StudentInfo));

        if (r == NULL) {
            printf("分配空间失败!");
            return;
        }

        r->next = NULL;

        if (q == NULL)
            *head = r;
        else {
            q->next = r;
        }

        strcpy(r->id, in_number);
        printf("请输入姓名：");
        scanf("%s", r->name);
        printf("请输入性别：");
        scanf("%s", r->sex);
        printf("请输入家庭地址：");
        scanf("%s", r->homeAddress);
        printf("请输入电话：");
        scanf("%s", r->phone);

        writeStuInfo(r); // 调用写入函数，将当前学生信息写入文件
    }
}



void writeStuInfo(Pointer head)
{
    FILE* fp;

    if ((fp = fopen("StudentInfo.csv", "a+")) == NULL) {
        if ((fp = fopen("StudentInfo.csv", "w+")) == NULL) {
            printf("学生信息文件StudentInfo.csv创建失败\n");
            return;
        }
        printf("已创建学生信息文件StudentInfo.csv\n");
    }

    Pointer p = head;
    while (p != NULL)
    {
        fprintf(fp, "%s,%s,%s,%s,%s\n", p->id, p->name, p->sex, p->homeAddress, p->phone); // 将学生信息以指定格式写入文件
        p = p->next;
    }

    fclose(fp);
    printf("学生信息已成功写入文件。\n");
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

void showStuInfo() 
{
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "r")) == NULL) {
        printf("无法打开文件");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            printf("%-20s", token);  // 使用%-20s来左对齐输出
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(fp);
}


void clearStuInfo(StudentInfo stu[], int size) // 清空结构体缓存
{
    memset(stu, 0, sizeof(StudentInfo) * size);
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

void showStuData() 
{
    printf("This is funtion about showStuData()\n");
}

void writeStuInfo() {
    printf("This is funtion about writeStuInfo()\n");
    //检索文件内容，以id为主码，在对应的id之间写入一行记录。
}

void readStuData() {
    printf("This is funtion about readStuData()\n");
}

void writeStuData() {
    printf("This is funtion about writeStuData()\n");
}


//退出系统
void exitSystem() {
    system("cls");  // Windows系统清屏命令  
    printf("确认退出系统？Y/N\n");
    if (FunAskConfirm()) {
        exit(0);
    }
    printf("本系统继续运行中...\n");
}