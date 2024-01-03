//宏定义
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS //在VS中使用scanf()、strcmp等函数
#endif // !_CRT_SECURE_NO_WARNINGS

//库函数引用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OtherFuntion.h"
#include "StuInfoFuntion.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//学生信息链表相关代码
//注：刻意避开了在函数内输入节点的内部数据，仅以一个id作为唯一标识

//节点类型 
//结构体类型：学生信息
#ifndef __STRUCT_STUDENTINFOMATION__
#define __STRUCT_STUDENTINFOMATION__
typedef struct StudentInfomation {
    char  id[100];
    char name[100];
    char sex[100];
    char homeAddress[100];
    char phone[100];
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

    for (count = 0, current = *head; current != NULL; current = current->next) {//遍历链表，计算节点数量
        count++;
    }
    if (count > 0) {
        for (indexI = 0; indexI < count - 1; indexI++) {
            current = *head;
            previous = NULL;
            for (indexJ = 0; indexJ < count - indexI - 1; indexJ++) {
                if (strcmp(current->id, current->next->id) > 0) {//关系到4个节点1->2->3->4。previous指向1，current指向2，3存在且不为空节点，4可能为空节点
                    if (previous == NULL) {//首个元素就需要交换，此时previous->next不存在，使用previous->会报错。
                        *head = current->next;//previous为NULL，current指向1，所以要*head指向2，此时NULL，1->2->3->4，*head==2
                        current->next = current->next->next;//此时1->3->4，*head==2->3->4
                        (*head)->next = current;//此时，head==2->1->3->4
                        current = *head;//修正current指针的位置，previous指向NULL，current指向1，由于1、2交换位置，所以previous和current中间隔了一个2被跳过
                    }
                    else {
                        previous->next = current->next;//此时1->3->4,2->3->4
                        current->next = current->next->next;//此时1->3->4,2->4
                        previous->next->next = current;//此时1->3->2->4，完成节点2和3的交换
                        current = previous->next;//修正current指针的位置，previous指向1，current指向2，由于2、3交换位置，所以previous和current中间隔了一个3被跳过
                    }
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

//释放链表内存
//参数：指向链表的指针
//返回值：无
void freeStuInfoLinkedList(StudentInfo** head) {
    StudentInfo* current = *head;
    StudentInfo* previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//从文件中读取学生信息到链表中，返回链表的头指针
StudentInfo* readStuInfo() {
    FILE* fp = NULL;
    StudentInfo* head = NULL;
    StudentInfo* newStuInfoNode = (StudentInfo*)calloc(1, sizeof(StudentInfo));
    char tempString[200];// 临时字符串，假设每行数据不超过200个字符
    if ((fp = fopen("StudentInfomation.csv", "r+")) == NULL) {//文件不存在则创建文件
        if ((fp = fopen("StudentInfomation.csv", "w+")) == NULL) {
            fclose(fp);
            printf("文件不存在或无法打开文件\n");
            return head;
        }
    }
    //文件存在
    //若读取字符串不为空，则创建新节点并将字符串格式化输入该节点，再往链表内添加该节点
    while (fgets(tempString, sizeof(StudentInfo), fp) != NULL) {
        newStuInfoNode = createStuInfoNode();
        sscanf(tempString, "%[^,],%[^,],%[^,],%[^,],%s", newStuInfoNode->id, newStuInfoNode->name, newStuInfoNode->sex, newStuInfoNode->homeAddress, newStuInfoNode->phone);
        appendStuInfoNode(&head, newStuInfoNode);
    }
    fclose(fp);
    return head;
}

//输入指向链表的指针，将学生信息链表的内容以格式化输出文件中
int writeStuInfo(StudentInfo** head) {
    FILE* fp = NULL;
    StudentInfo* current = *head;
    if ((fp = fopen("StudentInfomation.csv", "w+")) == NULL) {//文件不存在
        fclose(fp);
        printf("文件不存在或无法打开文件");
        return 0;
    }
    //文件存在
    sortStuInfoLinkedList(head);//根据学号升序对链表排序
    //遍历链表，将链表的内容以格式化输出文件中
    current = *head;
    while (current != NULL) {
        fprintf(fp, "%s,%s,%s,%s,%s\n", current->id, current->name, current->sex, current->homeAddress, current->phone); // 将学生信息以指定格式写入文件
        current = current->next;
    }
    fclose(fp);
    return 1;
}

//添加学生信息函数
void addStuInfo() {
    StudentInfo* head = readStuInfo();//从文件中读取已有内容并转为链表
    StudentInfo* current = head;//位移指针
    StudentInfo* previous = NULL;//位移指针
    StudentInfo* newStuInfoNode = NULL;//新节点
    int index = 0;
    int flag = 0;

    system("cls");  // Windows系统清屏命令  
    printf("添加学生信息功能\n");
    while (1) {
        newStuInfoNode = createStuInfoNode();//创建节点
        printf("请输入要添加学生的学号：");
        fgets(newStuInfoNode->id, sizeof(newStuInfoNode->id), stdin);//从标准输入区stdin读取长度为sizeof(newStuInfoNode->id)的字符串写入tempString
        newStuInfoNode->id[strcspn(newStuInfoNode->id, "\n")] = '\0';  // 删除字符串末尾的回车符  
        printf("请输入姓名：");
        fgets(newStuInfoNode->name, sizeof(newStuInfoNode->name), stdin);
        newStuInfoNode->name[strcspn(newStuInfoNode->name, "\n")] = '\0'; 
        printf("请输入性别：");
        fgets(newStuInfoNode->sex, sizeof(newStuInfoNode->sex), stdin);
        newStuInfoNode->sex[strcspn(newStuInfoNode->sex, "\n")] = '\0';
        printf("请输入家庭地址：");
        fgets(newStuInfoNode->homeAddress, sizeof(newStuInfoNode->homeAddress), stdin);
        newStuInfoNode->homeAddress[strcspn(newStuInfoNode->homeAddress, "\n")] = '\0';
        printf("请输入联系电话：");
        fgets(newStuInfoNode->phone, sizeof(newStuInfoNode->phone), stdin);
        newStuInfoNode->phone[strcspn(newStuInfoNode->phone, "\n")] = '\0';
        if (strlen(newStuInfoNode->id) > 0) {
            index = findStuInfoNodeIndex(&head, newStuInfoNode->id);//根据id查询节点的索引值，不存在返回-1
            if (index == -1) {
                appendStuInfoNode(&head, newStuInfoNode);//将新节点添加到链表中
                flag = writeStuInfo(&head);//将链表写入文件
                if (flag == 1) {
                    printf("添加学生信息成功。\n");
                }
                else {
                    printf("添加学生信息失败。\n");
                }
            }
            else {
                printf("添加学生信息失败，已存在该学生的信息。\n");
            }
        }
        else {
            printf("添加学生信息失败，学号无效。\n");
        }
        printf("是否继续输入学生信息? Y/N\n");
        if (FunAskConfirm() == 0) {//不继续，则释放内存并退出函数
            freeStuInfoLinkedList(&head);//释放链表内存
            return;
        }
    }
}

//删除学生信息函数
void deleteStuInfo() {
    StudentInfo* head = readStuInfo();//从文件中读取已有内容并转为链表
    StudentInfo* current = head;//位移指针
    StudentInfo* previous = NULL;//位移指针
    char tempString[100];//临时字符串
    int tempInt = 0;
    int index = 0;
    int flag = 0;
    int flag2 = 0;

    system("cls");  // Windows系统清屏命令  
    printf("删除学生信息功能\n");
    while (1) {
        printf("请输入要删除的学生学号：");
        fgets(tempString, sizeof(tempString), stdin);//从标准输入区stdin读取长度为sizeof(newStuInfoNode->id)的字符串写入tempString
        tempString[strcspn(tempString, "\n")] = '\0';// 删除字符串末尾的回车符  
        if (strlen(tempString) > 0) {
            index = findStuInfoNodeIndex(&head, tempString);//根据id查询节点的索引值，不存在返回-1
            if (index != -1) {
                current = head;
                tempInt = 0;
                while (tempInt < index) {//移动到对应节点
                    current = current->next;
                    tempInt++;
                }
                printf("%-15s%-15s%-15s%-15s%-15s\n", "学号", "姓名", "性别", "家庭住址", "电话号码");
                printf("------------------------------------------------------------------------\n");
                printf("%-15s%-15s%-15s%-15s%-15s\n", current->id, current->name, current->sex, current->homeAddress, current->phone);
                printf("是否确认删除该学生的信息。Y/N\n");
                if (FunAskConfirm() == 1) {
                    flag = deleteStuInfoNode(&head, index);//将节点从链表中删除
                    flag2 = writeStuInfo(&head);//将链表写入文件
                    if (flag == 1 && flag2 == 1) {
                        printf("删除学生信息成功。\n");
                    }
                    else {
                        printf("删除学生信息失败，写入文件失败。\n");
                    }
                }
                else {
                    printf("已放弃删除操作。\n");
                }
            }
            else {
                printf("删除学生信息失败，不存在该学生。\n");
            }
        }
        else {
            printf("删除学生信息失败，学号无效。\n");
        }
        printf("是否继续删除学生信息。Y/N\n");
        if (FunAskConfirm() == 0) {//不继续，则释放内存并退出函数
            freeStuInfoLinkedList(&head);//释放链表内存
            return;
        }
    }
}

//修改学生信息函数
void updateStuInfo() {
    StudentInfo* head = readStuInfo();//从文件中读取已有内容并转为链表
    StudentInfo* current = head;//位移指针
    StudentInfo* previous = NULL;//位移指针
    StudentInfo* newStuInfoNode = NULL;//新节点
    char tempString[100];//临时字符串
    int index = 0;
    int flag = 0;

    system("cls");  // Windows系统清屏命令  
    printf("修改学生信息功能\n");
    while (1) {
        newStuInfoNode = createStuInfoNode();//创建节点
        printf("请输入要修改或插入学生的学号：");
        fgets(newStuInfoNode->id, sizeof(newStuInfoNode->id), stdin);//从标准输入区stdin读取长度为sizeof(newStuInfoNode->id)的字符串写入tempString
        newStuInfoNode->id[strcspn(newStuInfoNode->id, "\n")] = '\0';// 删除字符串末尾的回车符  
        printf("请输入姓名：");
        fgets(newStuInfoNode->name, sizeof(newStuInfoNode->name), stdin);
        newStuInfoNode->name[strcspn(newStuInfoNode->name, "\n")] = '\0'; 
        printf("请输入性别：");
        fgets(newStuInfoNode->sex, sizeof(newStuInfoNode->sex), stdin);
        newStuInfoNode->sex[strcspn(newStuInfoNode->sex, "\n")] = '\0';
        printf("请输入家庭地址：");
        fgets(newStuInfoNode->homeAddress, sizeof(newStuInfoNode->homeAddress), stdin);
        newStuInfoNode->homeAddress[strcspn(newStuInfoNode->homeAddress, "\n")] = '\0';
        printf("请输入联系电话：");
        fgets(newStuInfoNode->phone, sizeof(newStuInfoNode->phone), stdin);
        newStuInfoNode->phone[strcspn(newStuInfoNode->phone, "\n")] = '\0';
        if (strlen(newStuInfoNode->id) > 0) {
            index = findStuInfoNodeIndex(&head, newStuInfoNode->id);//根据id查询节点的索引值，不存在返回-1
            if (index != -1) {//修改学生信息
                flag = updateStuInfoNode(&head, index, newStuInfoNode);
            }
            else {//插入学生信息
                flag = appendStuInfoNode(&head, newStuInfoNode);
            }
            flag = writeStuInfo(&head);//将链表写入文件
            if (flag == 1) {
                printf("修改或插入学生信息成功。\n");
            }
            else {
                printf("修改或插入学生信息失败，写入文件失败。\n");
            }
        }
        else {
            printf("修改或插入学生信息失败，学号无效。\n");
        }
        printf("是否继续修改或插入学生信息。Y/N\n");
        if (FunAskConfirm() == 0) {//不继续，则释放内存并退出函数
            freeStuInfoLinkedList(&head);//释放链表内存
            return;
        }
    }
}

//查询学生信息函数
void queryStuInfo() {
    StudentInfo* head = readStuInfo();//从文件中读取已有内容并转为链表
    StudentInfo* current = head;//位移指针
    StudentInfo* previous = NULL;//位移指针
    char tempString[100];//临时字符串
    int tempInt = 0;
    int index = 0;

    system("cls");  // Windows系统清屏命令  
    printf("查询学生信息功能\n");
    while (1) {
        printf("请输入要查询的学生学号：");
        fgets(tempString, sizeof(tempString), stdin);//从标准输入区stdin读取长度为sizeof(newStuInfoNode->id)的字符串写入tempString
        tempString[strcspn(tempString, "\n")] = '\0';// 删除字符串末尾的回车符  
        if (strlen(tempString) > 0) {
            index = findStuInfoNodeIndex(&head, tempString);//根据id查询节点的索引值，不存在返回-1
            if (index != -1) {
                current = head;
                tempInt = 0;
                while (tempInt < index) {//移动到对应节点
                    current = current->next;
                    tempInt++;
                }
                printf("%-15s%-15s%-15s%-15s%-15s\n", "学号", "姓名", "性别", "家庭住址", "电话号码");
                printf("------------------------------------------------------------------------\n");
                printf("%-15s%-15s%-15s%-15s%-15s\n", current->id, current->name, current->sex, current->homeAddress, current->phone);
            }
            else {
                printf("查询学生信息失败，不存在该学生。\n");
            }
        }
        else {
            printf("查询学生信息失败，学号无效。\n");
        }
        printf("是否继续查询学生信息。Y/N\n");
        if (FunAskConfirm() == 0) {//不继续，则释放内存并退出函数
            freeStuInfoLinkedList(&head);//释放链表内存
            return;
        }
    }
}

//浏览学生信息函数
void showStuInfo() {
    StudentInfo* head = readStuInfo();//从文件中读取已有内容并转为链表
    StudentInfo* current = head;//位移指针
    StudentInfo* previous = NULL;//位移指针
    char tempString[100];//临时字符串
    int tempInt = 0;
    int index = 0;

    while(1){
        system("cls");  // Windows系统清屏命令  
        printf("浏览学生信息功能\n");
        printf("\n                              学生信息如下\n\n");
        printf("%-15s%-15s%-15s%-15s%-15s\n", "学号", "姓名", "性别", "家庭住址", "电话号码");
        printf("------------------------------------------------------------------------\n");
        current = head;

        while (current != NULL) {//遍历输出
            printf("%-15s%-15s%-15s%-15s%-15s\n\n", current->id, current->name, current->sex, current->homeAddress, current->phone);
            current = current->next;
        }
        printf("是否继续浏览学生信息。Y/N\n");
        if (FunAskConfirm() == 0) {//不继续，则释放内存并退出函数
            freeStuInfoLinkedList(&head);//释放链表内存
            return;
        }
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++