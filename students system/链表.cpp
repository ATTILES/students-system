/*
FS5272 updata time=2023.12.18
链表相关代码
*/
/*
根据需要自行注释/取消注释关于双向链表的部分。
刻意避开了在函数内输入结构体的内部数据，仅以一个id作为唯一标识。
*/

#define _CRT_SECURE_NO_WARNINGS //在VS中使用strcmp函数

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//节点类型 
typedef struct Node {
    char id[20];
    struct Node* next;
    //struct Node* back;//双向 
}Node;

//创建空节点
//参数：无
//返回值：指向节点的指针
Node* createNode() {
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    strcpy(newNode->id, "");  // 初始化
    newNode->next = NULL;  // 初始化
    //newNode->back = NULL;  // 初始化//双向 
    return newNode;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//在链表末尾增加节点 
//参数：链表的头指针，新节点的指针
//返回值：成功返回1，失败返回0 
int appendNode(Node* head, Node* newNode) {
    //如果链表为空，则将头指针指向新节点
    if (head == NULL) {
        head = newNode;
        head->next = NULL;
        //head->back = NULL;//双向 
    }
    // 否则，遍历链表找到最后一个节点 
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
        //newNode->back = current;//双向 
    }
    return 1; // 增加成功  
}

//在链表中删除指定节点 
//参数：链表的头指针，指定节点的索引
//返回值：成功返回1，失败返回0 
int deleteNode(Node* head, int index) {
    if (head == NULL) {
        return 0; // 链表为空，删除失败  
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
        return 0; // 索引越界，删除失败  
    }
    else if (previous == NULL) {
        // 删除的是头节点  
        head = head->next;
        //删除的是尾节点 //双向 
        //if(head != NULL){
        //    head->back = NULL;//双向 		
        //}
    }
    else {
        // 删除的是非头节点  
        previous->next = current->next;
        //删除的是尾节点 //双向 
        //if(current->next != NULL){
        //	current->next->back =  previous;//双向 
        //}
    }
    free(current); // 释放被删除节点的内存  
    return 1; // 删除成功  
}

//在链表中替代指定节点 
//参数：链表的头指针，指定节点的索引
//返回值：成功返回1，失败返回0 
int updateNode(Node* head, int index, Node* newNode) {
    if (head == NULL) {
        return 0; // 链表为空，替代失败  
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
        return 0; // 索引越界，替代失败  
    }
    else if (previous == NULL) {
        //替代的是头节点  
        newNode->next = current->next;
        //newNode->back = NULL;//双向
        //替代的是尾节点 //双向 
        //if(current->next != NULL){
        //    current->next->back = newNode;//双向
        //}
        head = newNode;
    }
    else {
        //替代的是非头节点  
        previous->next = newNode;
        newNode->next = current->next;
        //newNode->back = previous;//双向 
        //替代的是尾节点  //双向 
        //if(current->next != NULL){
        //    current->next->back = newNode;//双向 
        //} 
    }
    free(current); // 释放被替代节点的内存  
    return 1; // 替代成功  
}

//在链表中查询索引的节点
//参数：链表的头指针，索引
//返回值：指向节点的指针
Node* getNodeAtIndex(Node* head, int index) {
    // 检查链表是否为空  
    if (head == NULL) {
        return NULL; // 链表为空，返回NULL  
    }

    // 遍历链表，查找指定索引的节点  
    Node* current = head;
    int count = 0;
    while (current->next != NULL && count < index) {
        current = current->next;
        count++;
    }

    // 检查是否找到了指定索引的节点  
    if (current == NULL || count > index) {
        return NULL; // 索引越界或未找到，返回NULL  
    }
    else {
        return current; // 返回找到的节点指针  
    }
}

//在链表中查询匹配项(字符串)节点的索引
//参数：链表的头指针，匹配项(字符串)
//返回值：指定节点的索引 
int findNodeIndex(Node* head, char* id) {
    // 检查链表是否为空  
    if (head == NULL) {
        return -1; // 链表为空，返回-1表示失败 
    }

    Node* current = head;
    int index = 0;// 索引从0开始计数
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            return index; // 找到目标节点，返回索引
        }
        current = current->next; // 移动到下一个节点  
        index++; // 更新索引 
    }
    return -1; // 未找到目标节点，返回-1表示失败  
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//遍历打印链表 √ 
//参数：链表的头指针
//返回值：无
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->id);
        current = current->next;
    }
    printf("\n");
}

//创建指定长度的链表([双向][环型]) 
//参数：链表的头指针，链表长度 
//返回值：指定链表的头指针 
Node* createLinkedList(int len) {
    Node* head = NULL;
    Node* newNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(Node));
    int i = 0;
    while (i < len) {
        newNode = createNode();//无法起到指向新节点的作用 
        printf("请输入id:\n");//依次输入节点的数据 
        //fgets(tempString,sizeof(newNode->id), stdin);
        //strcpy(newNode->id,strtok(tempString, "\n"));
        strcpy(newNode->id, "123");
        if (appendNode(head, newNode)) {//debug这里进入函数后head会被清零，newNode会被改变 
            printf("插入节点成功\n");
        }
        else {
            printf("插入节点失败\n");
        }
        //free(tempNode);
        i++;
    }
    return head;
}

//没写完 
//链表原地排序(根据id排序升序) 
//参数：链表的头指针
//返回值：无
void sortLinkedList(Node* head) {
    Node* current = head;
    int count = 0;
    //遍历得出链表节点数量 
    while (current != NULL) {
        count++;
        current = current->next;
    }


}



int main() {
    Node* head = NULL;
    printf("这是1:\n");
    //head = createLinkedList(3);

    printf("这是2:\n");
    printLinkedList(head);
    printf("这是3:\n");
    return 0;
}



