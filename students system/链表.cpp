/*
FS5272 updata time=2023.12.18
������ش���
*/
/*
������Ҫ����ע��/ȡ��ע�͹���˫������Ĳ��֡�
����ܿ����ں���������ṹ����ڲ����ݣ�����һ��id��ΪΨһ��ʶ��
*/

#define _CRT_SECURE_NO_WARNINGS //��VS��ʹ��strcmp����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ڵ����� 
typedef struct Node {
    char id[20];
    struct Node* next;
    //struct Node* back;//˫�� 
}Node;

//�����սڵ�
//��������
//����ֵ��ָ��ڵ��ָ��
Node* createNode() {
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    strcpy(newNode->id, "");  // ��ʼ��
    newNode->next = NULL;  // ��ʼ��
    //newNode->back = NULL;  // ��ʼ��//˫�� 
    return newNode;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//������ĩβ���ӽڵ� 
//�����������ͷָ�룬�½ڵ��ָ��
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int appendNode(Node* head, Node* newNode) {
    //�������Ϊ�գ���ͷָ��ָ���½ڵ�
    if (head == NULL) {
        head = newNode;
        head->next = NULL;
        //head->back = NULL;//˫�� 
    }
    // ���򣬱��������ҵ����һ���ڵ� 
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
        //newNode->back = current;//˫�� 
    }
    return 1; // ���ӳɹ�  
}

//��������ɾ��ָ���ڵ� 
//�����������ͷָ�룬ָ���ڵ������
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int deleteNode(Node* head, int index) {
    if (head == NULL) {
        return 0; // ����Ϊ�գ�ɾ��ʧ��  
    }

    Node* current = head;
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
        head = head->next;
        //ɾ������β�ڵ� //˫�� 
        //if(head != NULL){
        //    head->back = NULL;//˫�� 		
        //}
    }
    else {
        // ɾ�����Ƿ�ͷ�ڵ�  
        previous->next = current->next;
        //ɾ������β�ڵ� //˫�� 
        //if(current->next != NULL){
        //	current->next->back =  previous;//˫�� 
        //}
    }
    free(current); // �ͷű�ɾ���ڵ���ڴ�  
    return 1; // ɾ���ɹ�  
}

//�����������ָ���ڵ� 
//�����������ͷָ�룬ָ���ڵ������
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int updateNode(Node* head, int index, Node* newNode) {
    if (head == NULL) {
        return 0; // ����Ϊ�գ����ʧ��  
    }

    Node* current = head;
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
        newNode->next = current->next;
        //newNode->back = NULL;//˫��
        //�������β�ڵ� //˫�� 
        //if(current->next != NULL){
        //    current->next->back = newNode;//˫��
        //}
        head = newNode;
    }
    else {
        //������Ƿ�ͷ�ڵ�  
        previous->next = newNode;
        newNode->next = current->next;
        //newNode->back = previous;//˫�� 
        //�������β�ڵ�  //˫�� 
        //if(current->next != NULL){
        //    current->next->back = newNode;//˫�� 
        //} 
    }
    free(current); // �ͷű�����ڵ���ڴ�  
    return 1; // ����ɹ�  
}

//�������в�ѯ�����Ľڵ�
//�����������ͷָ�룬����
//����ֵ��ָ��ڵ��ָ��
Node* getNodeAtIndex(Node* head, int index) {
    // ��������Ƿ�Ϊ��  
    if (head == NULL) {
        return NULL; // ����Ϊ�գ�����NULL  
    }

    // ������������ָ�������Ľڵ�  
    Node* current = head;
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
//�����������ͷָ�룬ƥ����(�ַ���)
//����ֵ��ָ���ڵ������ 
int findNodeIndex(Node* head, char* id) {
    // ��������Ƿ�Ϊ��  
    if (head == NULL) {
        return -1; // ����Ϊ�գ�����-1��ʾʧ�� 
    }

    Node* current = head;
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

//������ӡ���� �� 
//�����������ͷָ��
//����ֵ����
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->id);
        current = current->next;
    }
    printf("\n");
}

//����ָ�����ȵ�����([˫��][����]) 
//�����������ͷָ�룬������ 
//����ֵ��ָ�������ͷָ�� 
Node* createLinkedList(int len) {
    Node* head = NULL;
    Node* newNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(Node));
    int i = 0;
    while (i < len) {
        newNode = createNode();//�޷���ָ���½ڵ������ 
        printf("������id:\n");//��������ڵ������ 
        //fgets(tempString,sizeof(newNode->id), stdin);
        //strcpy(newNode->id,strtok(tempString, "\n"));
        strcpy(newNode->id, "123");
        if (appendNode(head, newNode)) {//debug������뺯����head�ᱻ���㣬newNode�ᱻ�ı� 
            printf("����ڵ�ɹ�\n");
        }
        else {
            printf("����ڵ�ʧ��\n");
        }
        //free(tempNode);
        i++;
    }
    return head;
}

//ûд�� 
//����ԭ������(����id��������) 
//�����������ͷָ��
//����ֵ����
void sortLinkedList(Node* head) {
    Node* current = head;
    int count = 0;
    //�����ó�����ڵ����� 
    while (current != NULL) {
        count++;
        current = current->next;
    }


}



int main() {
    Node* head = NULL;
    printf("����1:\n");
    //head = createLinkedList(3);

    printf("����2:\n");
    printLinkedList(head);
    printf("����3:\n");
    return 0;
}



