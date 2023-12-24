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
    printf("*****  1,���ѧ����Ϣ  *****\n");
    printf("*****  2,��ʾѧ����Ϣ  *****\n");
    printf("*****  3,ɾ��ѧ����Ϣ  *****\n");
    printf("*****  4,����ѧ����Ϣ  *****\n");
    printf("*****  5,�޸�ѧ����Ϣ  *****\n");
    printf("*****  6,   *****\n");
    printf("*****  0���˳� *****\n");
    printf("***************************\n");
}

void add(struct studerid* abs)
{
    while (1)
    {
        if (abs->size == max)
        {
            printf("����");
                break; // ����������������
        }
        else
        {
            printf("������ѧ��");  scanf("%s", abs->array[abs->size].id);
            printf("�������Ա�:"); scanf("%s", &abs->array[abs->size].sex);
            printf("����������:"); scanf("%s", &abs->array[abs->size].name);
            printf("������绰:"); scanf("%s", abs->array[abs->size].phone);
            printf("�������ַ:"); scanf("%s", abs->array[abs->size].homeAddress);
            abs->size++;
            printf("��ӳɹ�");
                

                printf("�Ƿ��������ѧ����Ϣ��Y/N");
                    
                    if (FunAskConfirm() == 0)
                    {
                        break; // ����û�ѡ�񲻼������������
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
        printf("ѧ�ţ�%s\t", abs->array[i].id);
        printf("     �Ա�%s\t", (abs->array[i].sex == 1 ? "��" : "Ů"));
        printf("     ���䣺%s\t", abs->array[i].name);
        printf("     �绰��%s\t", abs->array[i].phone);
        printf("     ��ַ��%s\n", abs->array[i].homeAddress);
    }
}

void deleted(struct studerid* abs)
{
    // ɾ��ѧ����Ϣ�Ĵ���
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
