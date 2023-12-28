//�궨��
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS //��VS��ʹ��scanf()��strcmp�Ⱥ���
#endif // !_CRT_SECURE_NO_WARNINGS

//�⺯������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OtherFuntion.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//ѧ������������ش���
//ע������ܿ����ں���������ڵ���ڲ����ݣ�����һ��id��ΪΨһ��ʶ

//�ڵ�����
//�ṹ�����ͣ�ѧ������
#ifndef __STRUCT_STUDENTDATA__
#define __STRUCT_STUDENTDATA__
typedef struct StudentData {
    char id[100];
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

//�����սڵ�
//��������
//����ֵ��ָ��ڵ��ָ��
StudentData* createStuDataNode() {
    StudentData* newStuDataNode = (StudentData*)calloc(1, sizeof(StudentData));
    strcpy(newStuDataNode->id, "");  // ��ʼ��
    newStuDataNode->scoreChinese = 0;  // ��ʼ��
    newStuDataNode->scoreMath = 0;  // ��ʼ��
    newStuDataNode->scoreEnglish = 0;  // ��ʼ��
    newStuDataNode->scoreAverage = 0;  // ��ʼ��
    newStuDataNode->scoreRanking = 0;  // ��ʼ��
    newStuDataNode->evaluationClassmate = 0;  // ��ʼ��
    newStuDataNode->scoreMoral = 0;  // ��ʼ��
    newStuDataNode->evaluationTeacher = 0;  // ��ʼ��
    newStuDataNode->totalScore = 0;  // ��ʼ��
    newStuDataNode->totalRanking = 0;  // ��ʼ��
    newStuDataNode->next = NULL;  // ��ʼ��
    return newStuDataNode;
}

//������ĩβ���ӽڵ�
//������ָ�������ָ�룬�½ڵ��ָ��
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int appendStuDataNode(StudentData** head, StudentData* newStuDataNode) {
    if (*head == NULL) {//�������Ϊ�գ���ͷָ��ָ���½ڵ�
        *head = newStuDataNode;
        (*head)->next = NULL;
    }
    else {// ���򣬱��������ҵ����һ���ڵ� 
        StudentData* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStuDataNode;
        newStuDataNode->next = NULL;
    }
    return 1; // ���ӳɹ�  
}

//��������ɾ��ָ���ڵ�
//������ָ�������ָ�룬ָ���ڵ������
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int deleteStuDataNode(StudentData** head, int index) {
    if (*head == NULL) {
        return 0; // ����Ϊ�գ�ɾ��ʧ��  
    }

    StudentData* current = *head;
    StudentData* previous = NULL;
    int count = 0;
    while (current->next != NULL && count < index) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return 0; // ����Խ�磬ɾ��ʧ��  
    }
    else if (previous == NULL) {
        // ɾ������ͷ�ڵ�  
        *head = (*head)->next;
    }
    else {
        // ɾ�����Ƿ�ͷ�ڵ�  
        previous->next = current->next;
    }
    free(current); // �ͷű�ɾ���ڵ���ڴ�  
    return 1; // ɾ���ɹ�  
}

//�����������ָ���ڵ�
//������ָ�������ָ�룬ָ���ڵ�����������ԭ�ڵ���½ڵ�
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int updateStuDataNode(StudentData** head, int index, StudentData* newStuDataNode) {
    if (*head == NULL) {
        return 0; // ����Ϊ�գ����ʧ��  
    }

    StudentData* current = *head;
    StudentData* previous = NULL;
    int count = 0;
    while (current->next != NULL && count < index) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return 0; // ����Խ�磬���ʧ��  
    }
    else if (previous == NULL) {
        //�������ͷ�ڵ�  
        (newStuDataNode)->next = current->next;
        *head = newStuDataNode;
    }
    else {
        //������Ƿ�ͷ�ڵ�  
        previous->next = newStuDataNode;
        (newStuDataNode)->next = current->next;
    }
    free(current); // �ͷű�����ڵ���ڴ�  
    return 1; // ����ɹ�  
}

//�������в�ѯ�����Ľڵ�
//������ָ�������ָ�룬����
//����ֵ��ָ��ڵ��ָ��
StudentData* getStuDataNodeAtIndex(StudentData** head, int index) {
    // ��������Ƿ�Ϊ��  
    if (*head == NULL) {
        return NULL; // ����Ϊ�գ�����NULL  
    }

    // ������������ָ�������Ľڵ�  
    StudentData* current = *head;
    int count = 0;
    while (current->next != NULL && count < index) {
        current = current->next;
        count++;
    }

    // ����Ƿ��ҵ���ָ�������Ľڵ�  
    if (current == NULL || count > index) {
        return NULL; // ����Խ���δ�ҵ�������NULL  
    }
    else {
        return current; // �����ҵ��Ľڵ�ָ��  
    }
}

//�������в�ѯƥ����(�ַ���)�ڵ������
//������ָ�������ָ�룬ƥ����(�ַ���)
//����ֵ��ָ���ڵ������ 
int findStuDataNodeIndex(StudentData** head, char* id) {
    // ��������Ƿ�Ϊ��  
    if (*head == NULL) {
        return -1; // ����Ϊ�գ�����-1��ʾʧ�� 
    }

    StudentData* current = *head;
    int index = 0;// ������0��ʼ����
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            return index; // �ҵ�Ŀ��ڵ㣬��������
        }
        current = current->next; // �ƶ�����һ���ڵ�  
        index++; // �������� 
    }
    return -1; // δ�ҵ�Ŀ��ڵ㣬����-1��ʾʧ��  
}

//����ָ�����ȵ�����([˫��][����])
//������ָ�������ָ�룬������ 
//����ֵ�������ͷָ�� 
StudentData* createStuDataLinkedList(int len) {
    StudentData* head = NULL;
    StudentData* newStuDataNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(StudentData));
    int i = 0;
    while (i < len) {
        newStuDataNode = createStuDataNode();
        //printf("������id:\n");//��������ڵ������ 
        //fgets(tempString, sizeof(newStuDataNode->id), stdin);
        //strcpy(newStuDataNode->id, strtok(tempString, "\n"));
        if (appendStuDataNode(&head, newStuDataNode)) {
            printf("����ڵ�ɹ�\n");
        }
        else {
            printf("����ڵ�ʧ��\n");
        }
        i++;
    }
    return head;
}

//������ӡ����
//������ָ�������ָ��
//����ֵ����
void printStuDataLinkedList(StudentData** head) {
    StudentData* current = *head;
    while (current != NULL) {
        printf("%s\n", current->id);
        current = current->next;
    }
    printf("\n");
}

//����ԭ������(����id��������) û���Ժã����ȼ�StuInfoFuntion�ļ�
//������ָ�������ָ��
//����ֵ���ɹ�����1��ʧ�ܷ���0��
int sortStuDataLinkedList(StudentData** head) {
    return 1;
}

//�ͷ������ڴ�
void freeStuDataLinkedList(StudentData** head) {
    StudentData* current = *head;
    StudentData* previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//ѧ�����ݹ��ܺ���
//ע������ܿ����ں���������ڵ���ڲ����ݣ�����һ��id��ΪΨһ��ʶ

StudentData* readStuData() {
    ;
}

void writeStuData(StudentData** head) {
    ;
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

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++