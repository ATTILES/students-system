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
void addStuInfo(Pointer* head);
void deleteStuInfo(Pointer* head);
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
void clearStuInfoFile();//清空文件函数
void loadStuInfoFromFile(Pointer* head);//将学生信息加载到链表
void printStuInfo(Pointer head);//查看链表内容
void clearStuInfo(Pointer* head);//删除链表信息
void addStuInfotopointer(Pointer* head, const char* id, const char* name, const char* sex, const char* homeAddress, const char* phone);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//main函数
int main() {
    Pointer Head = NULL;
    int select=0;
    while (1) {
        showMenu();
        printf("请输入0-10来实现对应的功能:");
        select = -1;
        scanf("%d", &select);
        getchar();  // 清空输入缓冲区中的换行符
        rewind(stdin);//清空标准输入缓存区
        switch (select) {
            case 1:
                addStuInfo(&Head);
                break;
            case 2:
                deleteStuInfo(&Head);
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

//添加学生信息函数
void addStuInfo(Pointer* head)      //添加学生信息
{
    int flag;
    loadStuInfoFromFile(head);
    while (1) {
        int num;
        printf("请输入要添加的学生数量：");
        scanf("%d", &num);
        getchar();  // 清空输入缓冲区中的换行符

        for (int i = 0; i < num; i++) {
            Pointer p, q, r;
            char in_number[20];

            printf("请输入学号：");
            scanf("%s", in_number);
            getchar();  // 清空输入缓冲区中的换行符

            p = q = *head;
            while (p != NULL) {
                flag = 1;
                if (strcmp(p->id, in_number) == 0) {
                    printf("已经有相同的学号：\n");
                    printf("是否重新输入：Y/N\n");
                    if (FunAskConfirm() == 0) 
                    {
                        
                        return; }
                    else {
                        flag = 0;
                        break;
                    }
                    
                }
                else {
                    q = p;
                    p = p->next;  //走链判断是否存在这个学号信息
                }
            }
            if (flag == 0) { continue; }

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
            getchar();  // 清空输入缓冲区中的换行符
            printf("请输入性别：");
            scanf("%s", r->sex);
            getchar();  // 清空输入缓冲区中的换行符
            printf("请输入家庭地址：");
            scanf("%s", r->homeAddress);
            getchar();  // 清空输入缓冲区中的换行符
            printf("请输入电话：");
            scanf("%s", r->phone);
            getchar();  // 清空输入缓冲区中的换行符
            writeStuInfo(r); // 调用写入函数，将当前学生信息写入文件
        }
        if (flag == 1) {
            printf("是否继续添加学生信息：Y/N");
            if (FunAskConfirm() == 0) { return; }
        }
    }

}

//写入文件函数
void writeStuInfo(Pointer head)
{
    FILE* fp;

    if ((fp = fopen("StudentInfo.csv", "a")) == NULL) {
        if ((fp = fopen("StudentInfo.csv", "w+")) == NULL) {
            printf("已创建学生信息文件StudentInfo.csv\n");
        }
        
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

//删除学生信息函数
void deleteStuInfo(Pointer* head)
{
    printf("目前存在的学生信息\n");
    showStuInfo();             //展示现有的学生信息
    loadStuInfoFromFile(head);//将学生信息加载到链表
    printf("目前链表存在的学生信息\n");
    printStuInfo(*head);      //查看链表内容
    Pointer p, q;
    p = q = *head;
    char id[20];
    printf("请输入要删除的学生学号：");
    scanf("%s", id);
    getchar();  // 清空输入缓冲区中的换行符
    while (p != NULL) {
        if (strcmp(p->id, id) == 0)
        {
            if (p == *head) {
                *head = p->next;
            }
            else {
                q->next = p->next;
            }
            free(p);
            clearStuInfoFile();
            writeStuInfo(*head); // 将更新后的链表信息写入文件
            printf("学生信息已成功删除。\n");
            return;
        }
        else {
            q = p;
            p = p->next;
        }
    }

    printf("未找到指定学号的学生信息。\n");
}

//清空文件函数
void clearStuInfoFile()
{
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "w")) == NULL) {
        printf("无法打开文件\n");
        return;
    }
    fclose(fp);
}

// 向链表头指针指向的链表中添加学生信息
void addStuInfotopointer(Pointer* head, const char* id, const char* name, const char* sex, const char* homeAddress, const char* phone) {
    
   

    // 创建一个新节点
    Pointer newNode = (Pointer)malloc(sizeof(StudentInfo));

    // 将传入的学生信息复制到新节点的对应字段中
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    strcpy(newNode->sex, sex);
    strcpy(newNode->homeAddress, homeAddress);
    strcpy(newNode->phone, phone);

    // 将新节点的next指针置为NULL
    newNode->next = NULL;

    // 如果链表为空，则将新节点设置为头节点
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        // 否则，找到链表的末尾节点，并将新节点插入到末尾
        Pointer p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }
}

//查看链表内容
void printStuInfo(Pointer head) {
    Pointer p = head;
    while (p != NULL) {
        printf("学号：%s\n", p->id);
        printf("姓名：%s\n", p->name);
        printf("性别：%s\n", p->sex);
        printf("家庭地址：%s\n", p->homeAddress);
        printf("电话号码：%s\n", p->phone);
        printf("\n");
        p = p->next;
    }
}

//删除链表信息
void clearStuInfo(Pointer* head) {
    Pointer p = *head;
    while (p != NULL) {
        Pointer temp = p;
        p = p->next;
        free(temp);
    }
    *head = NULL; // 将头指针置为空，表示链表已清空
}

//将学生信息加载到链表
void loadStuInfoFromFile(Pointer* head)   //将学生信息加载到链表
{
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "r")) == NULL)
    {
        printf("无法打开文件");
        return;
    }

    char line[200];
    clearStuInfo(head); //清空原有链表内容
    while (fgets(line, sizeof(line), fp) != NULL) {
        char id[20], name[20], sex[10], homeAddress[100], phone[20];
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s", id, name, sex, homeAddress, phone);

        addStuInfotopointer(head, id, name, sex, homeAddress, phone);//将学生信息写入链表
    }

    fclose(fp);
}

void updateStuInfo() {
    printf("This is funtion about updateStuInfo()\n");
}

void queryStuInfo() {
    printf("This is funtion about queryStuInfo()\n");
}

void showStuInfo()
{
  
    printf("\n                              学生信息如下\n\n");
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "r")) == NULL) {
        printf("无法打开文件");
        return;
    }

    printf("%-15s%-15s%-15s%-15s%-15s\n", "学号", "姓名", "性别", "家庭住址", "电话号码");
    printf("------------------------------------------------------------------------\n");

    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* token = strtok(line, ",");
        int column = 0;
        while (token != NULL) {
            printf("%-15s", token);
            token = strtok(NULL, ",");
            column++;
        }
        count++;
        if (count % 5 == 0) {
            printf("\n");
        }
        else {
            printf("\n\n");
        }
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