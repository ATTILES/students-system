//funtion.h�ļ�
/*
����Ҫ�Ĺ��ܺ�������
*/

//�궨��
// 
//������
#ifndef __FUNTION_C__
#define __FUNTION_C__
#include "funtion.c"
#endif // !__FUNTION_C__

//��������
int FunAskConfirm();
Node* createNode();
int appendNode(Node** head, Node* newNode);
int deleteNode(Node** head, int index);
int updateNode(Node** head, int index, Node* newNode);
Node* getNodeAtIndex(Node** head, int index);
int findNodeIndex(Node** head, char* id);
Node* createLinkedList(int len);
void printLinkedList(Node** head);
void sortLinkedList(Node** head);

