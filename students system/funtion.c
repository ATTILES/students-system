//funtion.c文件
/*
非主要的功能函数
*/

//宏定义
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS //在VS中使用scanf()、strcmp等函数
#endif // !_CRT_SECURE_NO_WARNINGS

//库引用
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//请求用户确认,输入Y和y确认
int FunAskConfirm() {
    char confirm = ' ';
    while(1){
        confirm = getchar();
        rewind(stdin);//清空标准输入缓存区
        if (confirm == 'Y' || confirm == 'y') {
            return 1;
        }
        else if (confirm == 'N' || confirm == 'n') {
            return 0;
        }
        else {
            printf("输入Y或y确认，输入N或n取消\n");
        }
    }
}

//链表相关代码
/*
FS5272 updata time=2023.12.25
注：根据需要自行注释/取消注释关于双向链表的部分。
    刻意避开了在函数内输入节点的内部数据，仅以一个id作为唯一标识
*/

//节点类型 √
typedef struct Node {
    char id[20];
    struct Node* next;
}Node;

//创建空节点 √
//参数：无
//返回值：指向节点的指针
Node* createNode() {
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    strcpy(newNode->id, "");  // 初始化
    newNode->next = NULL;  // 初始化
    return newNode;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//在链表末尾增加节点 √
//参数：指向链表的链表，新节点的指针
//返回值：成功返回1，失败返回0 
int appendNode(Node** head, Node* newNode) {
    if (*head == NULL) {//如果链表为空，则将头指针指向新节点
        *head = newNode;
        (*head)->next = NULL;
    }
    else {// 否则，遍历链表找到最后一个节点 
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
    }
    return 1; // 增加成功  
}

//在链表中删除指定节点 √
//参数：指向链表的链表，指定节点的索引
//返回值：成功返回1，失败返回0 
int deleteNode(Node** head, int index) {
    if (*head == NULL) {
        return 0; // 链表为空，删除失败  
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
        return 0; // 索引越界，删除失败  
    }
    else if (previous == NULL) {
        // 删除的是头节点  
        *head = (*head)->next;
    }
    else {
        // 删除的是非头节点  
        previous->next = current->next;
    }
    free(current); // 释放被删除节点的内存  
    return 1; // 删除成功  
}

//在链表中替代指定节点 √
//参数：指向链表的链表，指定节点的索引，替代原节点的新节点
//返回值：成功返回1，失败返回0 
int updateNode(Node** head, int index, Node* newNode) {
    if (*head == NULL) {
        return 0; // 链表为空，替代失败  
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
        return 0; // 索引越界，替代失败  
    }
    else if (previous == NULL) {
        //替代的是头节点  
        (newNode)->next = current->next;
        *head = newNode;
    }
    else {
        //替代的是非头节点  
        previous->next = newNode;
        (newNode)->next = current->next;
    }
    free(current); // 释放被替代节点的内存  
    return 1; // 替代成功  
}

//在链表中查询索引的节点 √
//参数：链表的头指针，索引
//返回值：指向节点的指针
Node* getNodeAtIndex(Node** head, int index) {
    // 检查链表是否为空  
    if (*head == NULL) {
        return NULL; // 链表为空，返回NULL  
    }

    // 遍历链表，查找指定索引的节点  
    Node* current = *head;
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

//在链表中查询匹配项(字符串)节点的索引 √
//参数：链表的头指针，匹配项(字符串)
//返回值：指定节点的索引 
int findNodeIndex(Node** head, char* id) {
    // 检查链表是否为空  
    if (*head == NULL) {
        return -1; // 链表为空，返回-1表示失败 
    }

    Node* current = *head;
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

//创建指定长度的链表([双向][环型])  √
//参数：链表的头指针，链表长度 
//返回值：指定链表的头指针 
Node* createLinkedList(int len) {
    Node* head = NULL;
    Node* newNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(Node));
    int i = 0;
    while (i < len) {
        newNode = createNode();
        printf("请输入id:\n");//依次输入节点的数据 
        fgets(tempString, sizeof(newNode->id), stdin);
        strcpy(newNode->id, strtok(tempString, "\n"));
        if (appendNode(&head, newNode)) {
            printf("插入节点成功\n");
        }
        else {
            printf("插入节点失败\n");
        }
        i++;
    }
    return head;
}

//遍历打印链表 √ 
//参数：链表的头指针
//返回值：无
void printLinkedList(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        printf("%s\n", current->id);
        current = current->next;
    }
    printf("\n");
}

//没写完 
//链表原地排序(根据id排序升序) 
//参数：链表的头指针
//返回值：无
void sortLinkedList(Node** head) {
    Node* current = *head;
    int count = 0;
    //遍历得出链表节点数量 
    while (current != NULL) {
        count++;
        current = current->next;
    }


}

//函数功能测试
/*
int main() {
    Node* head = NULL;
    Node* newNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(Node));
    int index = 0;
    printf("------------------------------------------------------------\n");
    printf("创建一个新的链表,长度为：\n");
    scanf("%d", &index);
    rewind(stdin);
    head = createLinkedList(index);
    printf("链表遍历：\n");
    printLinkedList(&head);
    printf("------------------------------------------------------------\n");
    //printf("要删除节点的索引值\n");
    //scanf("%d", &index);
    //rewind(stdin);
    //deleteNode(&head, index);
    //printf("链表遍历：\n");
    //printLinkedList(&head);
    ////printf("------------------------------------------------------------\n");
    //printf("要修改节点的索引值\n");
    //scanf("%d", &index);
    //rewind(stdin);
    //newNode = createNode();
    //printf("请输入新节点的id:\n");
    //fgets(tempString, sizeof(newNode->id), stdin);
    //rewind(stdin);
    //strcpy(newNode->id, strtok(tempString, "\n"));
    //updateNode(&head, index, newNode);
    //printf("链表遍历：\n");
    //printLinkedList(&head);
    //printf("------------------------------------------------------------\n");
    //printf("要查找节点的索引值\n");
    //scanf("%d", &index);
    //rewind(stdin);
    //newNode = getNodeAtIndex(&head, index);
    //printf("查询到的节点：\n");
    //printf("节点id为%s\n",newNode->id);
    //printf("------------------------------------------------------------\n");
    //printf("查找相应id的节点索引\n");
    //newNode = createNode();
    //fgets(tempString, sizeof(newNode->id), stdin);
    //rewind(stdin);
    //strcpy(newNode->id, strtok(tempString, "\n"));
    //index = findNodeIndex(&head, tempString);
    //printf("输出结果%d：\n",index);
    //printf("------------------------------------------------------------\n");
    return 0;
}
*/



