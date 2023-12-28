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

//ѧ����Ϣ������ش���
//ע������ܿ����ں���������ڵ���ڲ����ݣ�����һ��id��ΪΨһ��ʶ

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
//������ָ��������ָ�룬�½ڵ��ָ��
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
//������ָ��������ָ�룬ָ���ڵ������
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
//������ָ��������ָ�룬ָ���ڵ�����������ԭ�ڵ���½ڵ�
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
//������ָ��������ָ�룬����
//����ֵ��ָ��ڵ��ָ��
StudentInfo* getStuInfoNodeAtIndex(StudentInfo** head, int index) {
    // ��������Ƿ�Ϊ��  
    if (*head == NULL) {
        return NULL; // ����Ϊ�գ�����NULL  
    }

    // ��������������ָ�������Ľڵ�  
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
//������ָ��������ָ�룬ƥ����(�ַ���)
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
//������ָ��������ָ�룬�������� 
//����ֵ��������ͷָ�� 
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
//������ָ��������ָ��
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
//������ָ��������ָ��
//����ֵ���ɹ�����1��ʧ�ܷ���0��
int sortStuInfoLinkedList(StudentInfo** head) {
    StudentInfo* current = *head;
    StudentInfo* previous = NULL;
    int indexI = 0, indexJ = 0, count = 0;

    for (count = 0; current != NULL; count++) {//��������������ڵ�����
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

//�ͷ������ڴ�
void freeStuInfoLinkedList(StudentInfo** head) {
    ;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//ѧ����Ϣ���ܺ���
//ע������ܿ����ں���������ڵ���ڲ����ݣ�����һ��id��ΪΨһ��ʶ

//���ļ��ж�ȡѧ����Ϣ�������У�����������ͷָ��
StudentInfo* readStuInfo() {
    FILE* fp = NULL;
    StudentInfo* head = NULL;
    StudentInfo* newStuInfoNode = (StudentInfo*)calloc(1, sizeof(StudentInfo));
    char* tempString = (char*)calloc(1, sizeof(StudentInfo));
    if ((fp = fopen("StudentInfomation.csv", "r+")) == NULL) {//�ļ�������
        if ((fp = fopen("StudentInfo.csv", "w+")) == NULL) {
            fclose(fp);
            printf("�ļ������ڻ��޷����ļ�\n");
            return NULL;
        }
    }
    else {//�ļ�����
        //����ȡ�ַ�����Ϊ�գ��򴴽��½ڵ㲢���ַ�����ʽ������ýڵ㣬�������������Ӹýڵ�
        while (fgets(tempString, sizeof(StudentInfo), fp) != NULL) {
            newStuInfoNode = createStuInfoNode();
            sscanf(tempString, "%[^,],%[^,],%[^,],%[^,],%s", newStuInfoNode->id, newStuInfoNode->name, newStuInfoNode->sex, newStuInfoNode->homeAddress, newStuInfoNode->phone);
            appendStuInfoNode(&head, newStuInfoNode);
        }
        fclose(fp);
        return head;
    }
}

//����ָ��������ָ�룬��ѧ����Ϣ�����������Ը�ʽ������ļ���
int writeStuInfo(StudentInfo** head) {
    FILE* fp = NULL;
    StudentInfo* current = *head;
    if ((fp = fopen("StudentInfomation.csv", "w+")) == NULL) {//�ļ�������
        fclose(fp);
        printf("�ļ������ڻ��޷����ļ�");
        return 0;
    }
    else {//�ļ�����
        sortStuInfoLinkedList(head);
        //�����������������������Ը�ʽ������ļ���
        while (current != NULL) {
            fprintf(fp, "%s,%s,%s,%s,%s\n", current->id, current->name, current->sex, current->homeAddress, current->phone); // ��ѧ����Ϣ��ָ����ʽд���ļ�
            current = current->next;
        }
        fclose(fp);
        return 1;
    }
}

//����ѧ����Ϣ����
void addStuInfo() {
    StudentInfo* head = readStuInfo();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentInfo* current = head;//λ��ָ��
    StudentInfo* previous = NULL;//λ��ָ��
    StudentInfo* newStuInfoNode = NULL;//�½ڵ�
    char* tempString = (char*)calloc(1, sizeof(StudentInfo));//��ʱ�ַ���
    int index = 0;
    int flag = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("����ѧ����Ϣ����\n");
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
                appendStuInfoNode(&head, newStuInfoNode);//���½ڵ����ӵ�������
                flag = writeStuInfo(&head);//������д���ļ�
                if (flag == 1) {
                    printf("����ѧ����Ϣ�ɹ���\n");
                }
                else {
                    printf("����ѧ����Ϣʧ�ܡ�\n");
                }
            }
            else {
                printf("����ѧ����Ϣʧ�ܣ��Ѵ��ڸ�ѧ������Ϣ��\n");
            }
        }
        else {
            printf("����ѧ����Ϣʧ�ܣ�ѧ����Ч��\n");
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
void deleteStuInfo() {
    StudentInfo* head = readStuInfo();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentInfo* current = head;//λ��ָ��
    StudentInfo* previous = NULL;//λ��ָ��
    char* tempString = (char*)calloc(1, sizeof(StudentInfo));//��ʱ�ַ���
    int tempInt = 0;
    int index = 0;
    int flag = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("ɾ��ѧ����Ϣ����\n");
    while (1) {
        printf("������Ҫɾ����ѧ��ѧ�ţ�");
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
                printf("�Ƿ�ȷ��ɾ����ѧ������Ϣ��\n");
                if (FunAskConfirm() == 1) {
                    deleteStuInfo(&head, index);//���ڵ��������ɾ��
                    flag = writeStuInfo(&head);//������д���ļ�
                    if (flag == 1) {
                        printf("ɾ��ѧ����Ϣ�ɹ���\n");
                    }
                    else {
                        printf("ɾ��ѧ����Ϣʧ�ܣ�д���ļ�ʧ�ܡ�\n");
                    }
                }
                else {
                    printf("�ѷ���ɾ��������\n");
                }
            }
            else {
                printf("ɾ��ѧ����Ϣʧ�ܣ������ڸ�ѧ����\n");
            }
        }
        else {
            printf("ɾ��ѧ����Ϣʧ�ܣ�ѧ����Ч��\n");
        }
        printf("�Ƿ����ɾ��ѧ����Ϣ��Y/N\n");
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

//�޸�ѧ����Ϣ����
void updateStuInfo() {
    StudentInfo* head = readStuInfo();//���ļ��ж�ȡ�������ݲ�תΪ����
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
            flag = writeStuInfo(&head);//������д���ļ�
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
    StudentInfo* head = readStuInfo();//���ļ��ж�ȡ�������ݲ�תΪ����
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

//���ѧ����Ϣ����
void showStuInfo() {
    StudentInfo* head = readStuInfo();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentInfo* current = head;//λ��ָ��
    StudentInfo* previous = NULL;//λ��ָ��
    char* tempString = (char*)calloc(1, sizeof(StudentInfo));//��ʱ�ַ���
    int tempInt = 0;
    int index = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("���ѧ����Ϣ����\n");
    printf("\n                              ѧ����Ϣ����\n\n");
    printf("%-15s%-15s%-15s%-15s%-15s\n", "ѧ��", "����", "�Ա�", "��ͥסַ", "�绰����");
    printf("------------------------------------------------------------------------\n");
    current = head;
    while (current != NULL) {//�������
        printf("%-15s%-15s%-15s%-15s%-15s\n\n", current->id, current->name, current->sex, current->homeAddress, current->phone);
        current = current->next;
    }
    printf("�Ƿ��˳����ѧ����Ϣ��Y/N\n");
    while (FunAskConfirm() != 1) {}//�����������ͷ��ڴ沢�˳�����
    current = head;
    previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }
    return;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++