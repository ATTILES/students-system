/*
ѧ���ۺϲ���ϵͳ V1.0
����������һ��ѧ���ۺϲ���ϵͳ
������Ա����˧124732023002�������124732023011
����ʱ�䣺2023/12/19��ʼ
Github��ַ��https://github.com/ATTILES/students-system.git

*/

/*
ע��
1.����������С�շ����������׵��ʿ�ͷСд�����൥�ʿ�ͷ��д��
2.�����ļ������ʽ������csv��ʽ
*/

#define _CRT_SECURE_NO_WARNINGS //��VS��ʹ��scanf()����

//�⺯������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��������
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
void readStuInfo();//�����ļ������ʽ������csv��ʽ
void writeStuInfo();//�����ļ������ʽ������csv��ʽ
void readStuData();//�����ļ������ʽ������csv��ʽ
void writeStuData();//�����ļ������ʽ������csv��ʽ
void exitSystem();


//�ṹ�����ͣ�ѧ����Ϣ
typedef struct StudentInfomation {
    char id[20];
    char name[20];
    char sex[10];
    char homeAddress[50];
    char phone[20];
}StudentInfo;

//�ṹ�����ͣ�ѧ������
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

//�ṹ�����ͣ�ѧ��
typedef struct Student {
    StudentInfo stuInfo;
    StudentData stuData;
}Student;

//main����
int main() {
    int select=0;
    while (1) {
        showMenu();
        select = -1;
        scanf("%d", &select);
        rewind(stdin);//��ձ�׼���뻺����
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
                printf("���ܱ����Ч����������ȷ�Ĺ��ܱ�š�\n");
                break;
        }
        printf("�밴enter��ȷ��\n");
        getchar();
        rewind(stdin);//��ձ�׼���뻺����
    }
    return 0;
}

//���˵�UIչʾ
void showMenu() {
    system("cls");  // Windowsϵͳ��������  
    printf("**************************************\n");
    printf("********                      ********\n");
    printf("********    ѧ���ۺϲ���ϵͳ  ********\n");
    printf("********                      ********\n");
    printf("********    1.���ѧ����Ϣ    ********\n");
    printf("********    2.ɾ��ѧ����Ϣ    ********\n");
    printf("********    3.�޸�ѧ����Ϣ    ********\n");
    printf("********    4.��ѯѧ����Ϣ    ********\n");
    printf("********    5.���ѧ����Ϣ    ********\n");
    printf("********    6.���ѧ������    ********\n");
    printf("********    7.ɾ��ѧ������    ********\n");
    printf("********    8.�޸�ѧ������    ********\n");
    printf("********    9.��ѯѧ������    ********\n");
    printf("********    10.���ѧ������   ********\n");
    printf("********    0.�˳�ϵͳ        ********\n");
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

//�˳�ϵͳ
void exitSystem() {
    printf("ȷ���˳�ϵͳ��Y/N\n");
    char confirm = ' ';
    confirm = getchar();
    rewind(stdin);//��ձ�׼���뻺����
    if (confirm == 'Y' || confirm == 'y') {
        exit(0);
    }
    printf("��ϵͳ����������...\n");
}