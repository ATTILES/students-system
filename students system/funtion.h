//funtion.h文件
/*
非主要的功能函数声明
*/

//宏定义
// 
//库引用
#ifndef __FUNTION_C__
#define __FUNTION_C__
#include "funtion.c"
#endif // !__FUNTION_C__

//函数声明
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

