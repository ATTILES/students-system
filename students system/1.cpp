#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funtion.h"

#define max 100

typedef struct StudentInfomation
{
    char id[20];  
    char sex;
    char name[20];
    char phone[20];
    char homeAddress[50];
};

struct studerid
{
    struct StudentInfomation array[max];
    int size;
};

void showmenu()
{
    printf("***************************\n");
    printf("*****  1,添加学生信息  *****\n");
    printf("*****  2,显示学生信息  *****\n");
    printf("*****  3,删除学生信息  *****\n");
    printf("*****  4,查找学生信息  *****\n");
    printf("*****  5,修改学生信息  *****\n");
    printf("*****  6,   *****\n");
    printf("*****  0，退出 *****\n");
    printf("***************************\n");
}

void add(struct studerid* abs)
{
    while (1)
    {
        if (abs->size == max)
        {
            printf("已满");
                break; // 如果已满，结束添加
        }
        else
        {
            printf("请输入学号");  scanf("%s", abs->array[abs->size].id);
            printf("请输入性别:"); scanf("%s", &abs->array[abs->size].sex);
            printf("请输入名字:"); scanf("%s", &abs->array[abs->size].name);
            printf("请输入电话:"); scanf("%s", abs->array[abs->size].phone);
            printf("请输入地址:"); scanf("%s", abs->array[abs->size].homeAddress);
            abs->size++;
            printf("添加成功");
                

                printf("是否继续输入学生信息。Y/N");
                    
                    if (FunAskConfirm() == 0)
                    {
                        break; // 如果用户选择不继续，结束添加
                    }
        }
    }
}


void find(struct studerid* abs)
{
    if (abs->size == 0)
    {
        printf("null\n");
    }
    for (int i = 0; i < abs->size; i++)
    {
        printf("学号：%s\t", abs->array[i].id);
        printf("     性别：%s\t", (abs->array[i].sex == 1 ? "男" : "女"));
        printf("     年龄：%s\t", abs->array[i].name);
        printf("     电话：%s\t", abs->array[i].phone);
        printf("     地址：%s\n", abs->array[i].homeAddress);
    }
}

void deleted(struct studerid* abs)
{
    // 删除学生信息的代码
}

int main()
{
    struct studerid abs;
    abs.size = 0;
    int select = 0;
    while (1)
    {
        showmenu();
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            add(&abs);
            break;
        case 2:
            find(&abs);
            break;
        case 3:
            deleted(&abs);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            printf("baybay\n");
            system("pause");
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}
