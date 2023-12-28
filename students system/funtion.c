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



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//请求用户确认,输入Y和y确认
int FunAskConfirm() {
    char confirm = ' ';
    while (1) {
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


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//学生信息链表相关代码
/*
FS5272 updata time=2023.12.25
注：根据需要自行注释/取消注释关于双向链表的部分。
    刻意避开了在函数内输入节点的内部数据，仅以一个id作为唯一标识
*/

//节点类型 
//结构体类型：学生信息
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

//创建空节点
//参数：无
//返回值：指向节点的指针
StudentInfo* createStuInfoNode() {
    StudentInfo* newStuInfoNode = (StudentInfo*)calloc(1, sizeof(StudentInfo));
    strcpy(newStuInfoNode->id, "");  // 初始化
    strcpy(newStuInfoNode->name, "");  // 初始化
    strcpy(newStuInfoNode->sex, "");  // 初始化
    strcpy(newStuInfoNode->homeAddress, "");  // 初始化
    strcpy(newStuInfoNode->phone, "");  // 初始化
    newStuInfoNode->next = NULL;  // 初始化
    return newStuInfoNode;
}

//在链表末尾增加节点
//参数：指向链表的指针，新节点的指针
//返回值：成功返回1，失败返回0 
int appendStuInfoNode(StudentInfo** head, StudentInfo* newStuInfoNode) {
    if (*head == NULL) {//如果链表为空，则将头指针指向新节点
        *head = newStuInfoNode;
        (*head)->next = NULL;
    }
    else {// 否则，遍历链表找到最后一个节点 
        StudentInfo* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStuInfoNode;
        newStuInfoNode->next = NULL;
    }
    return 1; // 增加成功  
}

//在链表中删除指定节点
//参数：指向链表的指针，指定节点的索引
//返回值：成功返回1，失败返回0 
int deleteStuInfoNode(StudentInfo** head, int index) {
    if (*head == NULL) {
        return 0; // 链表为空，删除失败  
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

//在链表中替代指定节点
//参数：指向链表的指针，指定节点的索引，替代原节点的新节点
//返回值：成功返回1，失败返回0 
int updateStuInfoNode(StudentInfo** head, int index, StudentInfo* newStuInfoNode) {
    if (*head == NULL) {
        return 0; // 链表为空，替代失败  
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
        return 0; // 索引越界，替代失败  
    }
    else if (previous == NULL) {
        //替代的是头节点  
        (newStuInfoNode)->next = current->next;
        *head = newStuInfoNode;
    }
    else {
        //替代的是非头节点  
        previous->next = newStuInfoNode;
        (newStuInfoNode)->next = current->next;
    }
    free(current); // 释放被替代节点的内存  
    return 1; // 替代成功  
}

//在链表中查询索引的节点
//参数：指向链表的指针，索引
//返回值：指向节点的指针
StudentInfo* getStuInfoNodeAtIndex(StudentInfo** head, int index) {
    // 检查链表是否为空  
    if (*head == NULL) {
        return NULL; // 链表为空，返回NULL  
    }

    // 遍历链表，查找指定索引的节点  
    StudentInfo* current = *head;
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
//参数：指向链表的指针，匹配项(字符串)
//返回值：指定节点的索引 
int findStuInfoNodeIndex(StudentInfo** head, char* id) {
    // 检查链表是否为空  
    if (*head == NULL) {
        return -1; // 链表为空，返回-1表示失败 
    }

    StudentInfo* current = *head;
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

//创建指定长度的链表
//参数：指向链表的指针，链表长度 
//返回值：链表的头指针 
StudentInfo* createStuInfoLinkedList(int len) {
    StudentInfo* head = NULL;
    StudentInfo* newStuInfoNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(StudentInfo));
    int i = 0;
    while (i < len) {
        newStuInfoNode = createStuInfoNode();
        /*
        printf("请输入id:\n");//依次输入节点的数据
        fgets(tempString, sizeof(newStuInfoNode->id), stdin);
        strcpy(newStuInfoNode->id, strtok(tempString, "\n"));
        */
        if (appendStuInfoNode(&head, newStuInfoNode)) {
            printf("插入节点成功\n");
        }
        else {
            printf("插入节点失败\n");
        }
        i++;
    }
    return head;
}

//遍历打印链表
//参数：指向链表的指针
//返回值：无
void printStuInfoLinkedList(StudentInfo** head) {
    StudentInfo* current = *head;
    while (current != NULL) {
        printf("%s\n", current->id);
        current = current->next;
    }
    printf("\n");
}


//链表原地排序(根据id排序升序) 
//参数：指向链表的指针
//返回值：成功返回1，失败返回0。
int sortStuInfoLinkedList(StudentInfo** head) {
    StudentInfo* current = *head;
    StudentInfo* previous = NULL;
    int indexI = 0, indexJ = 0, count = 0;

    for (count = 0; current != NULL; count++) {//遍历链表，计算节点数量
        current = current->next;
    }
    if (count > 0) {
        for (indexI = 0; indexI < count - 1; indexI++) {
            current = *head;
            previous = NULL;
            for (indexJ = 0; indexJ < count - indexI - 1; indexJ++) {
                if (strcmp(current->id, current->next->id) > 0) {//关系到4个节点，1->2->3->4。previous指向1，current指向2，3存在且不为空节点，4可能为空节点
                    previous->next = current->next;//此时1->3->4,2->3->4
                    current->next = current->next->next;//此时1->3->4,2->4
                    previous->next->next = current;//此时1->3->2->4，完成节点2和3的交换
                }
                previous = current;
                current = current->next;
            }
        }
    }
    else {
        printf("排序失败，链表为空。");
        return 0;
    }
    return 1;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//学生数据链表相关代码
/*
FS5272 updata time=2023.12.25
注：根据需要自行注释/取消注释关于双向链表的部分。
    刻意避开了在函数内输入节点的内部数据，仅以一个id作为唯一标识
*/

//节点类型
//结构体类型：学生数据
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

//创建空节点
//参数：无
//返回值：指向节点的指针
StudentData* createStuDataNode() {
    StudentData* newStuDataNode = (StudentData*)calloc(1, sizeof(StudentData));
    strcpy(newStuDataNode->id, "");  // 初始化
    newStuDataNode->scoreChinese = 0;  // 初始化
    newStuDataNode->scoreMath = 0;  // 初始化
    newStuDataNode->scoreEnglish = 0;  // 初始化
    newStuDataNode->scoreAverage = 0;  // 初始化
    newStuDataNode->scoreRanking = 0;  // 初始化
    newStuDataNode->evaluationClassmate = 0;  // 初始化
    newStuDataNode->scoreMoral = 0;  // 初始化
    newStuDataNode->evaluationTeacher = 0;  // 初始化
    newStuDataNode->totalScore = 0;  // 初始化
    newStuDataNode->totalRanking = 0;  // 初始化
    newStuDataNode->next = NULL;  // 初始化
    return newStuDataNode;
}

//在链表末尾增加节点
//参数：指向链表的指针，新节点的指针
//返回值：成功返回1，失败返回0 
int appendStuDataNode(StudentData** head, StudentData* newStuDataNode) {
    if (*head == NULL) {//如果链表为空，则将头指针指向新节点
        *head = newStuDataNode;
        (*head)->next = NULL;
    }
    else {// 否则，遍历链表找到最后一个节点 
        StudentData* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStuDataNode;
        newStuDataNode->next = NULL;
    }
    return 1; // 增加成功  
}

//在链表中删除指定节点
//参数：指向链表的指针，指定节点的索引
//返回值：成功返回1，失败返回0 
int deleteStuDataNode(StudentData** head, int index) {
    if (*head == NULL) {
        return 0; // 链表为空，删除失败  
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

//在链表中替代指定节点
//参数：指向链表的指针，指定节点的索引，替代原节点的新节点
//返回值：成功返回1，失败返回0 
int updateStuDataNode(StudentData** head, int index, StudentData* newStuDataNode) {
    if (*head == NULL) {
        return 0; // 链表为空，替代失败  
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
        return 0; // 索引越界，替代失败  
    }
    else if (previous == NULL) {
        //替代的是头节点  
        (newStuDataNode)->next = current->next;
        *head = newStuDataNode;
    }
    else {
        //替代的是非头节点  
        previous->next = newStuDataNode;
        (newStuDataNode)->next = current->next;
    }
    free(current); // 释放被替代节点的内存  
    return 1; // 替代成功  
}

//在链表中查询索引的节点
//参数：指向链表的指针，索引
//返回值：指向节点的指针
StudentData* getStuDataNodeAtIndex(StudentData** head, int index) {
    // 检查链表是否为空  
    if (*head == NULL) {
        return NULL; // 链表为空，返回NULL  
    }

    // 遍历链表，查找指定索引的节点  
    StudentData* current = *head;
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
//参数：指向链表的指针，匹配项(字符串)
//返回值：指定节点的索引 
int findStuDataNodeIndex(StudentData** head, char* id) {
    // 检查链表是否为空  
    if (*head == NULL) {
        return -1; // 链表为空，返回-1表示失败 
    }

    StudentData* current = *head;
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

//创建指定长度的链表([双向][环型])
//参数：指向链表的指针，链表长度 
//返回值：链表的头指针 
StudentData* createStuDataLinkedList(int len) {
    StudentData* head = NULL;
    StudentData* newStuDataNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(StudentData));
    int i = 0;
    while (i < len) {
        newStuDataNode = createStuDataNode();
        //printf("请输入id:\n");//依次输入节点的数据 
        //fgets(tempString, sizeof(newStuDataNode->id), stdin);
        //strcpy(newStuDataNode->id, strtok(tempString, "\n"));
        if (appendStuDataNode(&head, newStuDataNode)) {
            printf("插入节点成功\n");
        }
        else {
            printf("插入节点失败\n");
        }
        i++;
    }
    return head;
}

//遍历打印链表
//参数：指向链表的指针
//返回值：无
void printStuDataLinkedList(StudentData** head) {
    StudentData* current = *head;
    while (current != NULL) {
        printf("%s\n", current->id);
        current = current->next;
    }
    printf("\n");
}

//链表原地排序(根据id排序升序) 
//参数：指向链表的指针
//返回值：成功返回1，失败返回0。
int sortStuDataLinkedList(StudentData** head) {
    StudentData* current = *head;
    StudentData* previous = NULL;
    int indexI = 0, indexJ = 0, count = 0;

    for (count = 0; current != NULL; count++) {//遍历链表，计算节点数量
        current = current->next;
    }
    if (count > 0) {
        for (indexI = 0; indexI < count - 1; indexI++) {
            current = *head;
            previous = NULL;
            for (indexJ = 0; indexJ < count - indexI - 1; indexJ++) {
                if (strcmp(current->id, current->next->id) > 0) {//关系到4个节点，1->2->3->4。previous指向1，current指向2，3存在且不为空节点，4可能为空节点
                    previous->next = current->next;//此时1->3->4,2->3->4
                    current->next = current->next->next;//此时1->3->4,2->4
                    previous->next->next = current;//此时1->3->2->4，完成节点2和3的交换
                }
                previous = current;
                current = current->next;
            }
        }
    }
    else {
        printf("排序失败，链表为空。");
        return 0;
    }
    return 1;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

