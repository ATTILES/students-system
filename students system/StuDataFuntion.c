//宏定义
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS //在VS中使用scanf()、strcmp等函数
#endif // !_CRT_SECURE_NO_WARNINGS

//库函数引用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OtherFuntion.h"
#include "StuDataFuntion.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//学生数据链表相关代码
//注：刻意避开了在函数内输入节点的内部数据，仅以一个id作为唯一标识

//节点类型
//结构体类型：学生数据
#ifndef __STRUCT_STUDENTDATA__
#define __STRUCT_STUDENTDATA__
typedef struct StudentData {
    char id[100];
    float scoreChinese;
    float scoreMath;
    float scoreEnglish;
    float scoreAverage;
    float scoreRanking;
    float evaluationClassmate;
    float scoreMoral;
    float evaluationTeacher;
    float totalScore;
    float totalRanking;
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
    system("pause");
}

//链表原地排序(根据id排序升序) 
//参数：指向链表的指针
//返回值：成功返回1，失败返回0。
int sortStuDataLinkedList(StudentData** head) {
    StudentData* current = *head;
    StudentData* previous = NULL;
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
        printf("排序失败，链表为空。\n");
        return 0;
    }
    return 1;
}

//释放链表内存
void freeStuDataLinkedList(StudentData** head) {
    StudentData* current = *head;
    StudentData* previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }
}

//将浮点型数据转为保留2位小数的字符串
void formatFloat(float num, char* result) {
    sprintf(result, "%.2f", num); // 使用sprintf函数将浮点数格式化为字符串，保留2位小数
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//从文件中读取学生数据到链表中，返回链表的头指针
StudentData* readStuData() {
    FILE* fp = NULL;
    StudentData* head = NULL;
    char tempString[158]; // 临时字符串，假设每行数据不超过158个字符

    if ((fp = fopen("StudentData.csv", "r+")) == NULL) {
        if ((fp = fopen("StudentData.csv", "w+")) == NULL) {
            fclose(fp);
            printf("文件不存在或无法打开文件\n");
            return head;
        }
    }

    while (fgets(tempString, sizeof(tempString), fp) != NULL) {
        StudentData* newStudentData = createStuDataNode();
        sscanf(tempString, "%[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
            newStudentData->id, &newStudentData->scoreChinese, &newStudentData->scoreMath,
            &newStudentData->scoreEnglish, &newStudentData->scoreAverage, &newStudentData->scoreRanking,
            &newStudentData->evaluationClassmate, &newStudentData->scoreMoral, &newStudentData->evaluationTeacher,
            &newStudentData->totalScore, &newStudentData->totalRanking);

        appendStuDataNode(&head, newStudentData);
    }

    fclose(fp);
    return head;
}

//输入指向链表的指针，将学生信息链表的内容以格式化输出文件中
int writeStuData(StudentData** head) {
    FILE* fp = NULL;
    StudentData* current = *head;
    StudentData* currentExternal = *head;
    if ((fp = fopen("StudentData.csv", "w+")) == NULL) {//文件不存在
        fclose(fp);
        printf("文件不存在或无法打开文件");
        return 0;
    }
    //文件存在
    sortStuDataLinkedList(head);//根据学号升序对链表排序
    //重新计算考试成绩和综合测评总分
    for (current = *head; current != NULL; current = current->next){
        current->scoreAverage = (current->scoreChinese + current->scoreMath + current->scoreEnglish) / 3;
        current->totalScore = current->scoreAverage * 0.6 + current->evaluationClassmate * 0.1 + current->scoreMoral * 0.1 + current->evaluationTeacher * 0.2;
    }
    //重新计算排名
    for (currentExternal = *head; currentExternal != NULL; currentExternal = currentExternal->next) {
        currentExternal->scoreRanking = 1;
        currentExternal->totalRanking = 1;
        for (current = *head; current != NULL; current = current->next) {
            if (current->scoreAverage > currentExternal->scoreAverage) {
                currentExternal->scoreRanking++;
            }
            if (current->totalScore > currentExternal->totalScore) {
                currentExternal->totalRanking++;
            }
        }
    }
    //遍历链表，将链表的内容以格式化输出文件中
    current = *head;
    while (current != NULL) {
        char scoreChinese[10], scoreMath[10], scoreEnglish[10], scoreAverage[10], scoreRanking[10];
        char evaluationClassmate[10], scoreMoral[10], evaluationTeacher[10], totalScore[10], totalRanking[10];

        formatFloat(current->scoreChinese, scoreChinese);
        formatFloat(current->scoreMath, scoreMath);
        formatFloat(current->scoreEnglish, scoreEnglish);
        formatFloat(current->scoreAverage, scoreAverage);
        formatFloat(current->scoreRanking, scoreRanking);
        formatFloat(current->evaluationClassmate, evaluationClassmate);
        formatFloat(current->scoreMoral, scoreMoral);
        formatFloat(current->evaluationTeacher, evaluationTeacher);
        formatFloat(current->totalScore, totalScore);
        formatFloat(current->totalRanking, totalRanking);
        fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", current->id, scoreChinese, scoreMath,\
                scoreEnglish, scoreAverage, scoreRanking, evaluationClassmate,\
                scoreMoral,evaluationTeacher, totalScore, totalRanking);

        current = current->next;
    }
    
    fclose(fp);
    return 1;
}

//添加学生数据函数
void addStuData() {
    StudentData* head = readStuData();//从文件中读取已有内容并转为链表
    StudentData* current = head;//位移指针
    StudentData* previous = NULL;//位移指针
    StudentData* newStuDataNode = NULL;//新节点
    int index = 0;
    int flag = 0;

    system("cls");  // Windows系统清屏命令  
    printf("添加学生数据功能\n");
    while (1) {
        newStuDataNode = createStuDataNode();//创建节点
        printf("请输入要添加学生的学号：");
        fgets(newStuDataNode->id, sizeof(newStuDataNode->id), stdin);//从标准输入区stdin读取长度为sizeof(newStuDataNode->id)的字符串写入tempString
        newStuDataNode->id[strcspn(newStuDataNode->id, "\n")] = '\0';  // 删除字符串末尾的回车符  
        printf("请输入语文成绩：");
        scanf("%f", &newStuDataNode->scoreChinese);
        printf("请输入数学成绩：");
        scanf("%f", &newStuDataNode->scoreMath);
        printf("请输入英语成绩：");
        scanf("%f", &newStuDataNode->scoreEnglish);
        newStuDataNode->scoreAverage = (newStuDataNode->scoreChinese + newStuDataNode->scoreMath + newStuDataNode->scoreEnglish) / 3;
        printf("当前考试成绩为：%.2f\n", newStuDataNode->scoreAverage);
        for (newStuDataNode->scoreRanking = 1, current = head; current != NULL; current = current->next) {//每有一人成绩高于当前，则排名后退一位
            if (current->scoreAverage > newStuDataNode->scoreAverage) {
                newStuDataNode->scoreRanking++;
            }
        }
        printf("当前考试成绩排名为：%f\n", newStuDataNode->scoreRanking);
        printf("请输入同学互评分：");
        scanf("%f", &newStuDataNode->evaluationClassmate);
        printf("请输入品德成绩：");
        scanf("%f", &newStuDataNode->scoreMoral);
        printf("请输入任课教师评分：");
        scanf("%f", &newStuDataNode->evaluationTeacher);
        newStuDataNode->totalScore = newStuDataNode->scoreAverage * 0.6 + newStuDataNode->evaluationClassmate * 0.1 + newStuDataNode->scoreMoral * 0.1 + newStuDataNode->evaluationTeacher *0.2;
        printf("当前综合测评总分为：%.2f\n", newStuDataNode->totalScore);
        for (newStuDataNode->totalRanking = 1, current = head; current != NULL; current = current->next) {//每有一人总分高于当前，则排名后退一位
            if (current->totalScore > newStuDataNode->totalScore) {
                newStuDataNode->totalRanking++;
            }
        }
        printf("当前综合测评排名为：%f\n", newStuDataNode->totalRanking);
        if (strlen(newStuDataNode->id) > 0) {
            index = findStuDataNodeIndex(&head, newStuDataNode->id);//根据id查询节点的索引值，不存在返回-1
            if (index == -1) {
                appendStuDataNode(&head, newStuDataNode);//将新节点添加到链表中
                flag = writeStuData(&head);//将链表写入文件
                if (flag == 1) {
                    printf("添加学生数据成功。\n");
                }
                else {
                    printf("添加学生数据失败。\n");
                }
            }
            else {
                printf("添加学生数据失败，已存在该学生的数据。\n");
            }
        }
        else {
            printf("添加学生数据失败，学号无效。\n");
        }
        printf("是否继续输入学生数据? Y/N\n");
        if (FunAskConfirm() == 0) {//不继续，则释放内存并退出函数
            freeStuDataLinkedList(&head);//释放链表内存
            return;
        }
    }
}

//删除学生数据函数
void deleteStuData() {
    StudentData* head = readStuData();//从文件中读取已有内容并转为链表
    StudentData* current = head;//位移指针
    StudentData* previous = NULL;//位移指针
    char* tempString = (char*)calloc(1, sizeof(StudentData));//临时字符串
    int tempInt = 0;
    int index = 0;
    int flag = 0;
    int flag2 = 0;

    system("cls");  // Windows系统清屏命令  
    printf("删除学生数据功能\n");
    while (1) {
        printf("请输入要删除的学生学号：");
        fgets(tempString, sizeof(tempString), stdin);//从标准输入区stdin读取长度为sizeof(newStuDataNode->id)的字符串写入tempString
        tempString[strcspn(tempString, "\n")] = '\0';// 删除字符串末尾的回车符  
        if (strlen(tempString) > 0) {
            index = findStuDataNodeIndex(&head, tempString);//根据id查询节点的索引值，不存在返回-1
            if (index != -1) {
                current = head;
                tempInt = 0;
                while (tempInt < index) {//移动到对应节点
                    current = current->next;
                    tempInt++;
                }
                printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", \
                    "学号", "语文", "数学", "英语", "考试成绩", "考试排名", \
                    "同学互评", "品德成绩", "教师评价", "综测总分", "综测排名");
                printf("------------------------------------------------------------------------------------------------------------\n");
                printf("%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", \
                    current->id, current->scoreChinese, current->scoreMath, current->scoreEnglish, current->scoreAverage, current->scoreRanking, \
                    current->evaluationClassmate, current->scoreMoral, current->evaluationTeacher, current->totalScore, current->totalRanking);
                printf("是否确认删除该学生的信息。Y/N\n");
                if (FunAskConfirm() == 1) {
                    flag = deleteStuDataNode(&head, index);//将节点从链表中删除
                    flag2 = writeStuData(&head);//将链表写入文件
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
            freeStuDataLinkedList(&head);//释放链表内存
            return;
        }
    }
}

//修改学生数据函数
void updateStuData() {
    StudentData* head = readStuData();//从文件中读取已有内容并转为链表
    StudentData* current = head;//位移指针
    StudentData* previous = NULL;//位移指针
    StudentData* newStuDataNode = NULL;//新节点
    char* tempString = (char*)calloc(1, sizeof(StudentData));//临时字符串
    int index = 0;
    int flag = 0;

    system("cls");  // Windows系统清屏命令  
    printf("修改学生数据功能\n");
    while (1) {
        newStuDataNode = createStuDataNode();//创建节点
        printf("请输入要修改或插入学生的学号：");
        fgets(newStuDataNode->id, sizeof(newStuDataNode->id), stdin);//从标准输入区stdin读取长度为sizeof(newStuDataNode->id)的字符串写入tempString
        newStuDataNode->id[strcspn(newStuDataNode->id, "\n")] = '\0';// 删除字符串末尾的回车符  
        printf("请输入语文成绩：");
        scanf("%f", &newStuDataNode->scoreChinese);
        printf("请输入数学成绩：");
        scanf("%f", &newStuDataNode->scoreMath);
        printf("请输入英语成绩：");
        scanf("%f", &newStuDataNode->scoreEnglish);
        newStuDataNode->scoreAverage = (newStuDataNode->scoreChinese + newStuDataNode->scoreMath + newStuDataNode->scoreEnglish) / 3;
        for (newStuDataNode->scoreRanking = 1, current = head; current != NULL; current = current->next) {//每有一人成绩高于当前，则排名后退一位
            if (current->scoreAverage > newStuDataNode->scoreAverage) {
                newStuDataNode->scoreRanking++;
            }
        }
        printf("请输入同学互评分：");
        scanf("%f", &newStuDataNode->evaluationClassmate);
        printf("请输入品德成绩：");
        scanf("%f", &newStuDataNode->scoreMoral);
        printf("请输入任课教师评分：");
        scanf("%f", &newStuDataNode->evaluationTeacher);
        newStuDataNode->totalScore = newStuDataNode->scoreAverage * 0.6 + newStuDataNode->evaluationClassmate * 0.1 + newStuDataNode->scoreMoral * 0.1 + newStuDataNode->evaluationTeacher * 0.2;
        for (newStuDataNode->totalRanking = 1, current = head; current != NULL; current = current->next) {//每有一人总分高于当前，则排名后退一位
            if (current->totalScore > newStuDataNode->totalScore) {
                newStuDataNode->totalRanking++;
            }
        }
        if (strlen(newStuDataNode->id) > 0) {
            index = findStuDataNodeIndex(&head, newStuDataNode->id);//根据id查询节点的索引值，不存在返回-1
            if (index != -1) {//修改学生信息
                flag = updateStuDataNode(&head, index, newStuDataNode);
            }
            else {//插入学生信息
                flag = appendStuDataNode(&head, newStuDataNode);
            }
            flag = writeStuData(&head);//将链表写入文件
            if (flag == 1) {
                printf("修改或插入学生数据成功。\n");
            }
            else {
                printf("修改或插入学生数据失败，写入文件失败。\n");
            }
        }
        else {
            printf("修改或插入学生数据失败，学号无效。\n");
        }
        printf("是否继续修改或插入学生数据。Y/N\n");
        if (FunAskConfirm() == 0) {//不继续，则释放内存并退出函数
            freeStuDataLinkedList(&head);//释放链表内存
            return;
        }
    }
}

//查询学生数据函数
void queryStuData() {
    StudentData* head = readStuData();//从文件中读取已有内容并转为链表
    StudentData* current = head;//位移指针
    StudentData* previous = NULL;//位移指针
    char* tempString = (char*)calloc(1, sizeof(StudentData));//临时字符串
    int tempInt = 0;
    int index = 0;

    system("cls");  // Windows系统清屏命令  
    printf("查询学生数据功能\n");
    while (1) {
        printf("请输入要查询的学生学号：");
        fgets(tempString, sizeof(tempString), stdin);//从标准输入区stdin读取长度为sizeof(newStuDataNode->id)的字符串写入tempString
        tempString[strcspn(tempString, "\n")] = '\0';// 删除字符串末尾的回车符  
        if (strlen(tempString) > 0) {
            index = findStuDataNodeIndex(&head, tempString);//根据id查询节点的索引值，不存在返回-1
            if (index != -1) {
                current = head;
                tempInt = 0;
                while (tempInt < index) {//移动到对应节点
                    current = current->next;
                    tempInt++;
                }
                printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", \
                    "学号", "语文", "数学", "英语", "考试成绩", "考试排名", \
                    "同学互评", "品德成绩", "教师评价", "综测总分", "综测排名");
                printf("------------------------------------------------------------------------------------------------------------\n");
                printf("%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", \
                    current->id, current->scoreChinese, current->scoreMath, current->scoreEnglish, current->scoreAverage, current->scoreRanking, \
                    current->evaluationClassmate, current->scoreMoral, current->evaluationTeacher, current->totalScore, current->totalRanking);
            }
            else {
                printf("查询学生数据失败，不存在该学生。\n");
            }
        }
        else {
            printf("查询学生数据失败，学号无效。\n");
        }
        printf("是否继续查询学生数据。Y/N\n");
        if (FunAskConfirm() == 0) {//不继续，则释放内存并退出函数
            freeStuDataLinkedList(&head);//释放链表内存
            return;
        }
    }
}

//浏览学生数据函数
void showStuData()
{
    StudentData* head = readStuData();//从文件中读取已有内容并转为链表
    StudentData* current = head;//位移指针
    StudentData* previous = NULL;//位移指针
    char* tempString = (char*)calloc(1, sizeof(StudentData));//临时字符串
    int tempInt = 0;
    int index = 0;

    system("cls");  // Windows系统清屏命令  
    printf("浏览学生信息功能\n");
    printf("\n                              学生信息如下\n\n");
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", \
        "学号", "语文", "数学", "英语", "考试成绩", "考试排名", \
        "同学互评", "品德成绩", "教师评价", "综测总分", "综测排名");
    printf("------------------------------------------------------------------------------------------------------------\n");
    current = head;
    while (current != NULL) {//遍历输出
        printf("%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", \
            current->id, current->scoreChinese, current->scoreMath, current->scoreEnglish, current->scoreAverage, current->scoreRanking, \
            current->evaluationClassmate, current->scoreMoral, current->evaluationTeacher, current->totalScore, current->totalRanking);
        current = current->next;
    }
    printf("是否退出浏览学生信息。Y/N\n");
    if (FunAskConfirm() == 0) {//不继续，则释放内存并退出函数
        freeStuDataLinkedList(&head);//释放链表内存
        return;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++