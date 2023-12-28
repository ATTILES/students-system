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

//�ṹ�����ͣ�ѧ����Ϣ
#ifndef __STRUCT_STUDENTINFOMATION__
#define __STRUCT_STUDENTINFOMATION__
typedef struct StudentInfomation {
    char id[20];
    char name[20];
    char sex[10];
    char homeAddress[100];
    char phone[20];
    struct StudentInfomation* next;
}StudentInfo, * Pointer;
#endif // !__STRUCT_STUDENTINFOMATION__

//�ṹ�����ͣ�ѧ������
#ifndef __STRUCT_STUDENTDATA__
#define __STRUCT_STUDENTDATA__
typedef struct StudentData {
    char id[20];
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
    struct StudentData* next;
}StudentData;
#endif // !__STRUCT_STUDENTDATA__

//�ṹ�����ͣ�ѧ��
typedef struct Student {
    StudentInfo stuInfo;
    StudentData stuData;
    struct Student* next;
}Student;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//��������
void showMenu();
void addStuInfo();
void deleteStuInfo(Pointer* head);
void updateStuInfo();
void queryStuInfo();
void showStuInfo();
void addStuData();
void deleteStuData();
void updateStuData();
void queryStuData();
void showStuData();
void exitSystem();

void readStuInfo(StudentInfo stu[]);
void writeStuInfo(Pointer head);
void readStuData();//�����ļ������ʽ������csv��ʽ
void writeStuData();//�����ļ������ʽ������csv��ʽ

void clearStuInfo(StudentInfo stu[], int size);// ��սṹ�建��
void clearStuInfoFile();//����ļ�����
void loadStuInfoFromFile(Pointer* head);//��ѧ����Ϣ���ص�����
void printStuInfo(Pointer head);//�鿴��������
void clearStuInfo(Pointer* head);//ɾ��������Ϣ
void addStuInfotopointer(Pointer* head, const char* id, const char* name, const char* sex, const char* homeAddress, const char* phone);

StudentInfo* readStuInfo_By_FS();
int writeStuInfo_By_FS(StudentInfo** head);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//main����
int main() {
    Pointer Head = NULL;
    int select = 0;
    while (1) {
        showMenu();
        select = -1;
        scanf("%d", &select);
        getchar();  // ������뻺�����еĻ��з�
        rewind(stdin);//��ձ�׼���뻺����
        switch (select) {
        case 1:
            addStuInfo();
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
    printf("������0-10��ʵ�ֶ�Ӧ�Ĺ���:");
}

//���ѧ����Ϣ����
void addStuInfo() {
    StudentInfo* head = readStuInfo_By_FS();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentInfo* current = head;//λ��ָ��
    StudentInfo* previous = NULL;//λ��ָ��
    StudentInfo* newStuInfoNode = NULL;//�½ڵ�
    char* tempString = (char*)calloc(1, sizeof(StudentInfo));//��ʱ�ַ���
    int index = 0;
    int flag = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("���ѧ����Ϣ����\n");
    while (1) {
        newStuInfoNode = createStuInfoNode();//�����ڵ�
        printf("������ѧ�ţ�");
        fgets(tempString, sizeof(newStuInfoNode->id), stdin);//�ӱ�׼������stdin��ȡ����Ϊsizeof(newStuInfoNode->id)���ַ���д��tempString
        strcpy(newStuInfoNode->id, strtok(tempString, "\n"));//��tempString�е��ַ�����\n�ָ����ѵ�һ��д��ڵ���
        printf("������������");
        fgets(tempString, sizeof(newStuInfoNode->name), stdin);
        strcpy(newStuInfoNode->name, strtok(tempString, "\n"));
        printf("�������Ա�");
        fgets(tempString, sizeof(newStuInfoNode->sex), stdin);
        strcpy(newStuInfoNode->sex, strtok(tempString, "\n"));
        printf("�������ͥ��ַ��");
        fgets(tempString, sizeof(newStuInfoNode->homeAddress), stdin);
        strcpy(newStuInfoNode->homeAddress, strtok(tempString, "\n"));
        printf("��������ϵ�绰��");
        fgets(tempString, sizeof(newStuInfoNode->phone), stdin);
        strcpy(newStuInfoNode->phone, strtok(tempString, "\n"));
        if (newStuInfoNode->id != NULL) {
            index = findStuInfoNodeIndex(&head, newStuInfoNode->id);//����id��ѯ�ڵ������ֵ�������ڷ���-1
            if (index == -1) {
                appendStuInfoNode(&head, newStuInfoNode);//���½ڵ���ӵ�������
                flag = writeStuInfo_By_FS(&head);//������д���ļ�
                if (flag == 1) {
                    printf("���ѧ����Ϣ�ɹ���\n");
                }
                else {
                    printf("���ѧ����Ϣʧ�ܡ�\n");
                }
            }
            else {
                printf("���ѧ����Ϣʧ�ܣ��Ѵ��ڸ�ѧ������Ϣ��\n");
            }
        }
        else {
            printf("���ѧ����Ϣʧ�ܣ�ѧ����Ч��\n");
        }
        printf("�Ƿ��������ѧ����Ϣ? Y/N\n");
        if (FunAskConfirm() == 0) {//�����������ͷ��ڴ沢�˳�����
            current = head;
            previous = NULL;
            while (current != NULL) {
                previous = current;
                current = current->next;
                free(previous);
            }
            return;
        }
    }
}

//ɾ��ѧ����Ϣ����
void deleteStuInfo(Pointer* head)
{
    printf("Ŀǰ���ڵ�ѧ����Ϣ\n");
    showStuInfo();             //չʾ���е�ѧ����Ϣ
    loadStuInfoFromFile(head);//��ѧ����Ϣ���ص�����
    printf("Ŀǰ������ڵ�ѧ����Ϣ\n");
    printStuInfo(*head);      //�鿴��������
    Pointer p, q;
    p = q = *head;
    char id[20];
    printf("������Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%s", id);
    getchar();  // ������뻺�����еĻ��з�
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
            writeStuInfo(*head); // �����º��������Ϣд���ļ�
            printf("ѧ����Ϣ�ѳɹ�ɾ����\n");
            return;
        }
        else {
            q = p;
            p = p->next;
        }
    }

    printf("δ�ҵ�ָ��ѧ�ŵ�ѧ����Ϣ��\n");
}

//�޸�ѧ����Ϣ����
void updateStuInfo() {
    StudentInfo* head = readStuInfo_By_FS();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentInfo* current = head;//λ��ָ��
    StudentInfo* previous = NULL;//λ��ָ��
    StudentInfo* newStuInfoNode = NULL;//�½ڵ�
    char* tempString = (char*)calloc(1, sizeof(StudentInfo));//��ʱ�ַ���
    int index = 0;
    int flag = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("�޸�ѧ����Ϣ����\n");
    while (1) {
        newStuInfoNode = createStuInfoNode();//�����ڵ�
        printf("������Ҫ�޸Ļ�����ѧ��ѧ�ţ�");
        fgets(tempString, sizeof(newStuInfoNode->id), stdin);
        strcpy(newStuInfoNode->id, strtok(tempString, "\n"));
        printf("������������");
        fgets(tempString, sizeof(newStuInfoNode->name), stdin);
        strcpy(newStuInfoNode->name, strtok(tempString, "\n"));
        printf("�������Ա�");
        fgets(tempString, sizeof(newStuInfoNode->sex), stdin);
        strcpy(newStuInfoNode->sex, strtok(tempString, "\n"));
        printf("�������ͥ��ַ��");
        fgets(tempString, sizeof(newStuInfoNode->homeAddress), stdin);
        strcpy(newStuInfoNode->homeAddress, strtok(tempString, "\n"));
        printf("��������ϵ�绰��");
        fgets(tempString, sizeof(newStuInfoNode->phone), stdin);
        strcpy(newStuInfoNode->phone, strtok(tempString, "\n"));
        if (newStuInfoNode->id != NULL) {
            index = findStuInfoNodeIndex(&head, newStuInfoNode->id);//����id��ѯ�ڵ������ֵ�������ڷ���-1
            if (index != -1) {//�޸�ѧ����Ϣ
                flag = updateStuInfoNode(&head, index, newStuInfoNode);
            }
            else {//����ѧ����Ϣ
                flag = appendStuInfoNode(&head, newStuInfoNode);
            }
            flag = writeStuInfo_By_FS(&head);//������д���ļ�
            if (flag == 1) {
                printf("�޸�ѧ����Ϣ�ɹ���\n");
            }
            else {
                printf("�޸�ѧ����Ϣʧ�ܣ�д���ļ�ʧ�ܡ�\n");
            }
        }
        else {
            printf("�޸�ѧ����Ϣʧ�ܣ�ѧ����Ч��\n");
        }
        printf("�Ƿ�����޸�ѧ����Ϣ��Y/N\n");
        if (FunAskConfirm() == 0) {//�����������ͷ��ڴ沢�˳�����
            current = head;
            previous = NULL;
            while (current != NULL) {
                previous = current;
                current = current->next;
                free(previous);
            }
            return;
        }
    }
}

//��ѯѧ����Ϣ����
void queryStuInfo() {
    StudentInfo* head = readStuInfo_By_FS();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentInfo* current = head;//λ��ָ��
    StudentInfo* previous = NULL;//λ��ָ��
    char* tempString = (char*)calloc(1, sizeof(StudentInfo));//��ʱ�ַ���
    int tempInt = 0;
    int index = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("��ѯѧ����Ϣ����\n");
    while (1) {
        printf("������Ҫ��ѯ��ѧ��ѧ�ţ�");
        fgets(tempString, sizeof(current->id), stdin);
        strcpy(tempString, strtok(tempString, "\n"));
        if (tempString != NULL) {
            index = findStuInfoNodeIndex(&head, tempString);//����id��ѯ�ڵ������ֵ�������ڷ���-1
            if (index != -1) {
                current = head;
                tempInt = 0;
                while (tempInt < index) {//�ƶ�����Ӧ�ڵ�
                    current = current->next;
                    tempInt++;
                }
                printf("%-15s%-15s%-15s%-15s%-15s\n", "ѧ��", "����", "�Ա�", "��ͥסַ", "�绰����");
                printf("------------------------------------------------------------------------\n");
                printf("%-15s%-15s%-15s%-15s%-15s\n", current->id, current->name, current->sex, current->homeAddress, current->phone);
            }
            else {
                printf("��ѯѧ����Ϣʧ�ܣ������ڸ�ѧ����\n");
            }
        }
        else {
            printf("��ѯѧ����Ϣʧ�ܣ�ѧ����Ч��\n");
        }
        printf("�Ƿ������ѯѧ����Ϣ��Y/N\n");
        if (FunAskConfirm() == 0) {//�����������ͷ��ڴ沢�˳�����
            current = head;
            previous = NULL;
            while (current != NULL) {
                previous = current;
                current = current->next;
                free(previous);
            }
            return;
        }
    }
}

//չʾѧ����Ϣ����
void showStuInfo()
{

    printf("\n                              ѧ����Ϣ����\n\n");
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "r")) == NULL) {
        printf("�޷����ļ�");
        return;
    }

    printf("%-15s%-15s%-15s%-15s%-15s\n", "ѧ��", "����", "�Ա�", "��ͥסַ", "�绰����");
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

//�˳�ϵͳ
void exitSystem() {
    system("cls");  // Windowsϵͳ��������  
    printf("ȷ���˳�ϵͳ��Y/N\n");
    if (FunAskConfirm()) {
        exit(0);
    }
    printf("��ϵͳ����������...\n");
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//��ȡѧ����Ϣ�ļ�����
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
        int i = 0;
        while (fgets(line, sizeof(line), fp) != NULL) // ���ж�ȡ�ļ�����
        {
            if (i == MAX)
            {
                break;
            }
            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s", stu[i].id, stu[i].name, stu[i].sex, stu[i].homeAddress, stu[i].phone);
            i++;
        }

        fclose(fp);
    }
}

//д��ѧ����Ϣ�ļ�����
void writeStuInfo(Pointer head)
{
    FILE* fp;

    if ((fp = fopen("StudentInfo.csv", "a")) == NULL) {
        if ((fp = fopen("StudentInfo.csv", "w+")) == NULL) {
            printf("�Ѵ���ѧ����Ϣ�ļ�StudentInfo.csv\n");
        }

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

void readStuData() {
    printf("This is funtion about readStuData()\n");
}

void writeStuData() {
    printf("This is funtion about writeStuData()\n");
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//���ļ��ж�ȡ��Ϣ�������У����������ͷָ��
StudentInfo* readStuInfo_By_FS() {
    FILE* fp = NULL;
    StudentInfo* head = NULL;
    StudentInfo* newStuInfoNode = (StudentInfo*)calloc(1, sizeof(StudentInfo));
    char* tempString = (char*)calloc(1, sizeof(StudentInfo));
    if ((fp = fopen("StudentInfo.csv", "r+")) == NULL) {//�ļ�������
        if ((fp = fopen("StudentInfo.csv", "w+")) == NULL) {
            fclose(fp);
            printf("�ļ������ڻ��޷����ļ�\n");
            return NULL;
        }
    }
    else {//�ļ�����
        //����ȡ�ַ�����Ϊ�գ��򴴽��½ڵ㲢���ַ�����ʽ������ýڵ㣬������������Ӹýڵ�
        while (fgets(tempString, sizeof(StudentInfo), fp) != NULL) {
            newStuInfoNode = createStuInfoNode();
            sscanf(tempString, "%[^,],%[^,],%[^,],%[^,],%s", newStuInfoNode->id, newStuInfoNode->name, newStuInfoNode->sex, newStuInfoNode->homeAddress, newStuInfoNode->phone);
            appendStuInfoNode(&head, newStuInfoNode);
        }
        fclose(fp);
        return head;
    }
}

//����ָ�������ָ�룬������������Ը�ʽ������ļ��У�����ֵ
int writeStuInfo_By_FS(StudentInfo** head) {
    FILE* fp = NULL;
    StudentInfo* current = *head;
    if ((fp = fopen("StudentInfo.csv", "w+")) == NULL) {//�ļ�������
        fclose(fp);
        printf("�ļ������ڻ��޷����ļ�");
        return 0;
    }
    else {//�ļ�����
        sortStuInfoLinkedList(head);
        //��������������������Ը�ʽ������ļ���
        while (current != NULL) {
            fprintf(fp, "%s,%s,%s,%s,%s\n", current->id, current->name, current->sex, current->homeAddress, current->phone); // ��ѧ����Ϣ��ָ����ʽд���ļ�
            current = current->next;
        }
        fclose(fp);
        return 1;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

//�鿴��������
void printStuInfo(Pointer head) {
    Pointer p = head;
    while (p != NULL) {
        printf("ѧ�ţ�%s\n", p->id);
        printf("������%s\n", p->name);
        printf("�Ա�%s\n", p->sex);
        printf("��ͥ��ַ��%s\n", p->homeAddress);
        printf("�绰���룺%s\n", p->phone);
        printf("\n");
        p = p->next;
    }
}

//ɾ��������Ϣ
void clearStuInfo(Pointer* head) {
    Pointer p = *head;
    while (p != NULL) {
        Pointer temp = p;
        p = p->next;
        free(temp);
    }
    *head = NULL; // ��ͷָ����Ϊ�գ���ʾ���������
}

//��ѧ����Ϣ���ص�����
void loadStuInfoFromFile(Pointer* head)   //��ѧ����Ϣ���ص�����
{
    FILE* fp;
    if ((fp = fopen("StudentInfo.csv", "r")) == NULL)
    {
        printf("�޷����ļ�");
        return;
    }

    char line[200];
    clearStuInfo(head); //���ԭ����������
    while (fgets(line, sizeof(line), fp) != NULL) {
        char id[20], name[20], sex[10], homeAddress[100], phone[20];
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s", id, name, sex, homeAddress, phone);

        addStuInfotopointer(head, id, name, sex, homeAddress, phone);//��ѧ����Ϣд������
    }

    fclose(fp);
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

// ��սṹ�建��
void clearStuInfo(StudentInfo stu[], int size)
{
    memset(stu, 0, sizeof(StudentInfo) * size);
}
