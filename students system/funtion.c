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

//�����û�ȷ��,����Y��yȷ��
int FunAskConfirm() {
    char confirm = ' ';
    while(1){
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

//������ش���
/*
FS5272 updata time=2023.12.25
ע��������Ҫ����ע��/ȡ��ע�͹���˫������Ĳ��֡�
    ����ܿ����ں���������ڵ���ڲ����ݣ�����һ��id��ΪΨһ��ʶ
*/

//�ڵ����� ��
typedef struct Node {
    char id[20];
    struct Node* next;
}Node;

//�����սڵ� ��
//��������
//����ֵ��ָ��ڵ��ָ��
Node* createNode() {
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    strcpy(newNode->id, "");  // ��ʼ��
    newNode->next = NULL;  // ��ʼ��
    return newNode;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//������ĩβ���ӽڵ� ��
//������ָ������������½ڵ��ָ��
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int appendNode(Node** head, Node* newNode) {
    if (*head == NULL) {//�������Ϊ�գ���ͷָ��ָ���½ڵ�
        *head = newNode;
        (*head)->next = NULL;
    }
    else {// ���򣬱��������ҵ����һ���ڵ� 
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
    }
    return 1; // ���ӳɹ�  
}

//��������ɾ��ָ���ڵ� ��
//������ָ�����������ָ���ڵ������
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int deleteNode(Node** head, int index) {
    if (*head == NULL) {
        return 0; // ����Ϊ�գ�ɾ��ʧ��  
    }

    Node* current = *head;
    Node* previous = NULL;
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

//�����������ָ���ڵ� ��
//������ָ�����������ָ���ڵ�����������ԭ�ڵ���½ڵ�
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int updateNode(Node** head, int index, Node* newNode) {
    if (*head == NULL) {
        return 0; // ����Ϊ�գ����ʧ��  
    }

    Node* current = *head;
    Node* previous = NULL;
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
        (newNode)->next = current->next;
        *head = newNode;
    }
    else {
        //������Ƿ�ͷ�ڵ�  
        previous->next = newNode;
        (newNode)->next = current->next;
    }
    free(current); // �ͷű�����ڵ���ڴ�  
    return 1; // ����ɹ�  
}

//�������в�ѯ�����Ľڵ� ��
//�����������ͷָ�룬����
//����ֵ��ָ��ڵ��ָ��
Node* getNodeAtIndex(Node** head, int index) {
    // ��������Ƿ�Ϊ��  
    if (*head == NULL) {
        return NULL; // ����Ϊ�գ�����NULL  
    }

    // ������������ָ�������Ľڵ�  
    Node* current = *head;
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

//�������в�ѯƥ����(�ַ���)�ڵ������ ��
//�����������ͷָ�룬ƥ����(�ַ���)
//����ֵ��ָ���ڵ������ 
int findNodeIndex(Node** head, char* id) {
    // ��������Ƿ�Ϊ��  
    if (*head == NULL) {
        return -1; // ����Ϊ�գ�����-1��ʾʧ�� 
    }

    Node* current = *head;
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

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//����ָ�����ȵ�����([˫��][����])  ��
//�����������ͷָ�룬������ 
//����ֵ��ָ�������ͷָ�� 
Node* createLinkedList(int len) {
    Node* head = NULL;
    Node* newNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(Node));
    int i = 0;
    while (i < len) {
        newNode = createNode();
        printf("������id:\n");//��������ڵ������ 
        fgets(tempString, sizeof(newNode->id), stdin);
        strcpy(newNode->id, strtok(tempString, "\n"));
        if (appendNode(&head, newNode)) {
            printf("����ڵ�ɹ�\n");
        }
        else {
            printf("����ڵ�ʧ��\n");
        }
        i++;
    }
    return head;
}

//������ӡ���� �� 
//�����������ͷָ��
//����ֵ����
void printLinkedList(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        printf("%s\n", current->id);
        current = current->next;
    }
    printf("\n");
}

//ûд�� 
//����ԭ������(����id��������) 
//�����������ͷָ��
//����ֵ����
void sortLinkedList(Node** head) {
    Node* current = *head;
    int count = 0;
    //�����ó�����ڵ����� 
    while (current != NULL) {
        count++;
        current = current->next;
    }


}

//�������ܲ���
/*
int main() {
    Node* head = NULL;
    Node* newNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(Node));
    int index = 0;
    printf("------------------------------------------------------------\n");
    printf("����һ���µ�����,����Ϊ��\n");
    scanf("%d", &index);
    rewind(stdin);
    head = createLinkedList(index);
    printf("���������\n");
    printLinkedList(&head);
    printf("------------------------------------------------------------\n");
    //printf("Ҫɾ���ڵ������ֵ\n");
    //scanf("%d", &index);
    //rewind(stdin);
    //deleteNode(&head, index);
    //printf("���������\n");
    //printLinkedList(&head);
    ////printf("------------------------------------------------------------\n");
    //printf("Ҫ�޸Ľڵ������ֵ\n");
    //scanf("%d", &index);
    //rewind(stdin);
    //newNode = createNode();
    //printf("�������½ڵ��id:\n");
    //fgets(tempString, sizeof(newNode->id), stdin);
    //rewind(stdin);
    //strcpy(newNode->id, strtok(tempString, "\n"));
    //updateNode(&head, index, newNode);
    //printf("���������\n");
    //printLinkedList(&head);
    //printf("------------------------------------------------------------\n");
    //printf("Ҫ���ҽڵ������ֵ\n");
    //scanf("%d", &index);
    //rewind(stdin);
    //newNode = getNodeAtIndex(&head, index);
    //printf("��ѯ���Ľڵ㣺\n");
    //printf("�ڵ�idΪ%s\n",newNode->id);
    //printf("------------------------------------------------------------\n");
    //printf("������Ӧid�Ľڵ�����\n");
    //newNode = createNode();
    //fgets(tempString, sizeof(newNode->id), stdin);
    //rewind(stdin);
    //strcpy(newNode->id, strtok(tempString, "\n"));
    //index = findNodeIndex(&head, tempString);
    //printf("������%d��\n",index);
    //printf("------------------------------------------------------------\n");
    return 0;
}
*/



