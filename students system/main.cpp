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
#define MAX 100                 //�������֧��100��ѧ��

//�⺯������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funtion.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//�ṹ�����ͣ�ѧ����Ϣ
typedef struct StudentInfomation {
    char  id[20];
    char name[20];
    char sex[10];
    char homeAddress[100];
    char phone[20];
    struct StudentInfomation* next;
}StudentInfo,*Pointer;



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

//��������
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
void readStuData();//�����ļ������ʽ������csv��ʽ
void writeStuData();//�����ļ������ʽ������csv��ʽ
void exitSystem();
void writeStuInfo(Pointer head);
void clearStuInfo(StudentInfo stu[], int size);// ��սṹ�建��
void clearStuInfoFile();//����ļ�����
void loadStuInfoFromFile(Pointer* head);//��ѧ����Ϣ���ص�����
void addStuInfotopointer(Pointer* head, const char* id, const char* name, const char* sex, const char* homeAddress, const char* phone);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//main����
int main() {
    Pointer Head = NULL;
    int select=0;
    while (1) {
        showMenu();
        select = -1;
        scanf("%d", &select);
        rewind(stdin);//��ձ�׼���뻺����
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
                printf("���ܱ����Ч����������ȷ�Ĺ��ܱ�š�\n");
                break;
        }
        printf("�밴enter��ȷ��\n");
        getchar();
        rewind(stdin);//��ձ�׼���뻺����
    }
    return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

void readStuInfo(StudentInfo stu[])
{
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "r")) == NULL)
    {
        printf("�޷����ļ�");
        fclose(fp);
        return;
    }
    else
    {
        char line[100];
        int i=0;
        while (fgets(line, sizeof(line), fp) != NULL) // ���ж�ȡ�ļ�����
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

void addStuInfo(Pointer* head)      //���ѧ����Ϣ
{
    int num;
    printf("������Ҫ��ӵ�ѧ��������");
    scanf("%d", &num);
    getchar();  // ������뻺�����еĻ��з�

    for (int i = 0; i < num; i++) {
        Pointer p, q, r;
        char in_number[20];

        printf("������ѧ�ţ�");
        scanf("%s", in_number);
        getchar();  // ������뻺�����еĻ��з�

        p = q = *head;
        while (p != NULL) {
            if (strcmp(p->id, in_number) == 0) {
                printf("�Ѿ�����ͬ��ѧ�ţ�");
                continue;  // ������ǰѭ����������һ��ѭ��
            }
            else {
                q = p;
                p = p->next;  //�����ж��Ƿ�������ѧ����Ϣ
            }
        }

        r = (Pointer)malloc(sizeof(StudentInfo));

        if (r == NULL) {
            printf("����ռ�ʧ��!");
            return;
        }

        r->next = NULL;

        if (q == NULL)
            *head = r;
        else {
            q->next = r;
        }

        strcpy(r->id, in_number);
        printf("������������");
        scanf("%s", r->name);
        getchar();  // ������뻺�����еĻ��з�
        printf("�������Ա�");
        scanf("%s", r->sex);
        getchar();  // ������뻺�����еĻ��з�
        printf("�������ͥ��ַ��");
        scanf("%s", r->homeAddress);
        getchar();  // ������뻺�����еĻ��з�
        printf("������绰��");
        scanf("%s", r->phone);
        getchar();  // ������뻺�����еĻ��з�
        writeStuInfo(r); // ����д�뺯��������ǰѧ����Ϣд���ļ�
    }
}


//д���ļ�����
void writeStuInfo(Pointer head)
{
    FILE* fp;

    if ((fp = fopen("StudentInfo.csv", "a")) == NULL) {
        if ((fp = fopen("StudentInfo.csv", "w+")) == NULL) {
            printf("ѧ����Ϣ�ļ�StudentInfo.csv����ʧ��\n");
            return;
        }
        printf("�Ѵ���ѧ����Ϣ�ļ�StudentInfo.csv\n");
    }

    Pointer p = head;
    while (p != NULL)
    {
        fprintf(fp, "%s,%s,%s,%s,%s\n", p->id, p->name, p->sex, p->homeAddress, p->phone); // ��ѧ����Ϣ��ָ����ʽд���ļ�
        p = p->next;
    }

    fclose(fp);
    printf("ѧ����Ϣ�ѳɹ�д���ļ���\n");
}


//ɾ��ѧ����Ϣ����
void deleteStuInfo(Pointer* head)
{
    printf("Ŀǰ���ڵ�ѧ����Ϣ\n");
    showStuInfo();
    loadStuInfoFromFile(head);
    Pointer p, q;
    p = q = *head;
    char id[20];
    printf("������Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%s", id);
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
            printf("ѧ����Ϣ�ѳɹ�ɾ����\n");
            clearStuInfoFile();
            writeStuInfo(*head); // �����º��������Ϣд���ļ�
            return;
        }
        else {
            q = p;
            p = p->next;
        }
    }

    printf("δ�ҵ�ָ��ѧ�ŵ�ѧ����Ϣ��\n");
}

//����ļ�����
void clearStuInfoFile()
{
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "w")) == NULL) {
        printf("�޷����ļ�\n");
        return;
    }
    fclose(fp);
}

// ������ͷָ��ָ������������ѧ����Ϣ
void addStuInfotopointer(Pointer* head, const char* id, const char* name, const char* sex, const char* homeAddress, const char* phone) {
    // ����һ���½ڵ�
    Pointer newNode = (Pointer)malloc(sizeof(StudentInfo));

    // �������ѧ����Ϣ���Ƶ��½ڵ�Ķ�Ӧ�ֶ���
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    strcpy(newNode->sex, sex);
    strcpy(newNode->homeAddress, homeAddress);
    strcpy(newNode->phone, phone);

    // ���½ڵ��nextָ����ΪNULL
    newNode->next = NULL;

    // �������Ϊ�գ����½ڵ�����Ϊͷ�ڵ�
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        // �����ҵ������ĩβ�ڵ㣬�����½ڵ���뵽ĩβ
        Pointer p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }
}


void loadStuInfoFromFile(Pointer* head)   //��ѧ����Ϣ���ص�����
{
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "r")) == NULL)
    {
        printf("�޷����ļ�");
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char id[20], name[20], sex[10], homeAddress[100], phone[20];
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s", id, name, sex, homeAddress, phone);

        addStuInfotopointer(head, id, name, sex, homeAddress, phone);
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
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "r")) == NULL) {
        printf("�޷����ļ�");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            printf("%-20s", token);  // ʹ��%-20s����������
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(fp);
}

void clearStuInfo(StudentInfo stu[], int size) // ��սṹ�建��
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
    //�����ļ����ݣ���idΪ���룬�ڶ�Ӧ��id֮��д��һ�м�¼��
}

void readStuData() {
    printf("This is funtion about readStuData()\n");
}

void writeStuData() {
    printf("This is funtion about writeStuData()\n");
}


//�˳�ϵͳ
void exitSystem() {
    system("cls");  // Windowsϵͳ��������  
    printf("ȷ���˳�ϵͳ��Y/N\n");
    if (FunAskConfirm()) {
        exit(0);
    }
    printf("��ϵͳ����������...\n");
}