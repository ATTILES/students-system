//funtion.c�ļ�
/*
����Ҫ�Ĺ��ܺ���
*/

//�궨��
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS //��VS��ʹ��scanf()��strcmp�Ⱥ���
#endif // !_CRT_SECURE_NO_WARNINGS

//������
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//�����û�ȷ��,����Y��yȷ��
int FunAskConfirm() {
    char confirm = ' ';
    while (1) {
        confirm = getchar();
        rewind(stdin);//��ձ�׼���뻺����
        if (confirm == 'Y' || confirm == 'y') {
            return 1;
        }
        else if (confirm == 'N' || confirm == 'n') {
            return 0;
        }
        else {
            printf("����Y��yȷ�ϣ�����N��nȡ��\n");
        }
    }
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//ѧ����Ϣ������ش���
/*
FS5272 updata time=2023.12.25
ע��������Ҫ����ע��/ȡ��ע�͹���˫������Ĳ��֡�
    ����ܿ����ں���������ڵ���ڲ����ݣ�����һ��id��ΪΨһ��ʶ
*/

//�ڵ����� 
//�ṹ�����ͣ�ѧ����Ϣ
#ifndef __STRUCT_STUDENTINFOMATION__
#define __STRUCT_STUDENTINFOMATION__
typedef struct StudentInfomation {
    char  id[20];
    char name[20];
    char sex[10];
    char homeAddress[100];
    char phone[20];
    struct StudentInfomation* next;
}StudentInfo, * Pointer;
#endif // !__STRUCT_STUDENTINFOMATION__

//�����սڵ�
//��������
//����ֵ��ָ��ڵ��ָ��
StudentInfo* createStuInfoNode() {
    StudentInfo* newStuInfoNode = (StudentInfo*)calloc(1, sizeof(StudentInfo));
    strcpy(newStuInfoNode->id, "");  // ��ʼ��
    strcpy(newStuInfoNode->name, "");  // ��ʼ��
    strcpy(newStuInfoNode->sex, "");  // ��ʼ��
    strcpy(newStuInfoNode->homeAddress, "");  // ��ʼ��
    strcpy(newStuInfoNode->phone, "");  // ��ʼ��
    newStuInfoNode->next = NULL;  // ��ʼ��
    return newStuInfoNode;
}

//������ĩβ���ӽڵ�
//������ָ�������ָ�룬�½ڵ��ָ��
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int appendStuInfoNode(StudentInfo** head, StudentInfo* newStuInfoNode) {
    if (*head == NULL) {//�������Ϊ�գ���ͷָ��ָ���½ڵ�
        *head = newStuInfoNode;
        (*head)->next = NULL;
    }
    else {// ���򣬱��������ҵ����һ���ڵ� 
        StudentInfo* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStuInfoNode;
        newStuInfoNode->next = NULL;
    }
    return 1; // ���ӳɹ�  
}

//��������ɾ��ָ���ڵ�
//������ָ�������ָ�룬ָ���ڵ������
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int deleteStuInfoNode(StudentInfo** head, int index) {
    if (*head == NULL) {
        return 0; // ����Ϊ�գ�ɾ��ʧ��  
    }

    StudentInfo* current = *head;
    StudentInfo* previous = NULL;
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
int updateStuInfoNode(StudentInfo** head, int index, StudentInfo* newStuInfoNode) {
    if (*head == NULL) {
        return 0; // ����Ϊ�գ����ʧ��  
    }

    StudentInfo* current = *head;
    StudentInfo* previous = NULL;
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
        (newStuInfoNode)->next = current->next;
        *head = newStuInfoNode;
    }
    else {
        //������Ƿ�ͷ�ڵ�  
        previous->next = newStuInfoNode;
        (newStuInfoNode)->next = current->next;
    }
    free(current); // �ͷű�����ڵ���ڴ�  
    return 1; // ����ɹ�  
}

//�������в�ѯ�����Ľڵ�
//������ָ�������ָ�룬����
//����ֵ��ָ��ڵ��ָ��
StudentInfo* getStuInfoNodeAtIndex(StudentInfo** head, int index) {
    // ��������Ƿ�Ϊ��  
    if (*head == NULL) {
        return NULL; // ����Ϊ�գ�����NULL  
    }

    // ������������ָ�������Ľڵ�  
    StudentInfo* current = *head;
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
int findStuInfoNodeIndex(StudentInfo** head, char* id) {
    // ��������Ƿ�Ϊ��  
    if (*head == NULL) {
        return -1; // ����Ϊ�գ�����-1��ʾʧ�� 
    }

    StudentInfo* current = *head;
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

//����ָ�����ȵ�����
//������ָ�������ָ�룬������ 
//����ֵ�������ͷָ�� 
StudentInfo* createStuInfoLinkedList(int len) {
    StudentInfo* head = NULL;
    StudentInfo* newStuInfoNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(StudentInfo));
    int i = 0;
    while (i < len) {
        newStuInfoNode = createStuInfoNode();
        /*
        printf("������id:\n");//��������ڵ������
        fgets(tempString, sizeof(newStuInfoNode->id), stdin);
        strcpy(newStuInfoNode->id, strtok(tempString, "\n"));
        */
        if (appendStuInfoNode(&head, newStuInfoNode)) {
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
void printStuInfoLinkedList(StudentInfo** head) {
    StudentInfo* current = *head;
    while (current != NULL) {
        printf("%s\n", current->id);
        current = current->next;
    }
    printf("\n");
}


//����ԭ������(����id��������) 
//������ָ�������ָ��
//����ֵ���ɹ�����1��ʧ�ܷ���0��
int sortStuInfoLinkedList(StudentInfo** head) {
    StudentInfo* current = *head;
    StudentInfo* previous = NULL;
    int indexI = 0, indexJ = 0, count = 0;

    for (count = 0; current != NULL; count++) {//������������ڵ�����
        current = current->next;
    }
    if (count > 0) {
        for (indexI = 0; indexI < count - 1; indexI++) {
            current = *head;
            previous = NULL;
            for (indexJ = 0; indexJ < count - indexI - 1; indexJ++) {
                if (strcmp(current->id, current->next->id) > 0) {//��ϵ��4���ڵ㣬1->2->3->4��previousָ��1��currentָ��2��3�����Ҳ�Ϊ�սڵ㣬4����Ϊ�սڵ�
                    previous->next = current->next;//��ʱ1->3->4,2->3->4
                    current->next = current->next->next;//��ʱ1->3->4,2->4
                    previous->next->next = current;//��ʱ1->3->2->4����ɽڵ�2��3�Ľ���
                }
                previous = current;
                current = current->next;
            }
        }
    }
    else {
        printf("����ʧ�ܣ�����Ϊ�ա�");
        return 0;
    }
    return 1;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//ѧ������������ش���
/*
FS5272 updata time=2023.12.25
ע��������Ҫ����ע��/ȡ��ע�͹���˫������Ĳ��֡�
    ����ܿ����ں���������ڵ���ڲ����ݣ�����һ��id��ΪΨһ��ʶ
*/

//�ڵ�����
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

//����ԭ������(����id��������) 
//������ָ�������ָ��
//����ֵ���ɹ�����1��ʧ�ܷ���0��
int sortStuDataLinkedList(StudentData** head) {
    StudentData* current = *head;
    StudentData* previous = NULL;
    int indexI = 0, indexJ = 0, count = 0;

    for (count = 0; current != NULL; count++) {//������������ڵ�����
        current = current->next;
    }
    if (count > 0) {
        for (indexI = 0; indexI < count - 1; indexI++) {
            current = *head;
            previous = NULL;
            for (indexJ = 0; indexJ < count - indexI - 1; indexJ++) {
                if (strcmp(current->id, current->next->id) > 0) {//��ϵ��4���ڵ㣬1->2->3->4��previousָ��1��currentָ��2��3�����Ҳ�Ϊ�սڵ㣬4����Ϊ�սڵ�
                    previous->next = current->next;//��ʱ1->3->4,2->3->4
                    current->next = current->next->next;//��ʱ1->3->4,2->4
                    previous->next->next = current;//��ʱ1->3->2->4����ɽڵ�2��3�Ľ���
                }
                previous = current;
                current = current->next;
            }
        }
    }
    else {
        printf("����ʧ�ܣ�����Ϊ�ա�");
        return 0;
    }
    return 1;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

