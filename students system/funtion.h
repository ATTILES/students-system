//funtion.h文件
/*
非主要的功能函数声明
*/


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "funtion.c"
//节点类型 
//结构体类型：学生信息
#ifndef __STRUCT_STUDENTINFOMATION__
#define __STRUCT_STUDENTINFOMATION__
typedef struct StudentInfomation {
    char id[20];
    char name[20];
    char sex[10];
    char homeAddress[100];
    char phone[20];
    struct StudentInfomation* next;
}StudentInfo, * Pointer;
#endif // !__STRUCT_STUDENTINFOMATION__

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

//防止多次引用
#ifndef __FUNTION_H__
#define __FUNTION_H__
//函数声明
int FunAskConfirm();//请求用户确认,输入Y和y确认

StudentInfo* createStuInfoNode();//创建空节点
int appendStuInfoNode(StudentInfo** head, StudentInfo* newStuInfoNode);//在链表末尾增加节点
int deleteStuInfoNode(StudentInfo** head, int index);//在链表中删除指定节点
int updateStuInfoNode(StudentInfo** head, int index, StudentInfo* newStuInfoNode);//在链表中替代指定节点
StudentInfo* getStuInfoNodeAtIndex(StudentInfo** head, int index);//在链表中查询索引的节点
int findStuInfoNodeIndex(StudentInfo** head, char* id);//在链表中查询匹配项(字符串)节点的索引
StudentInfo* createStuInfoLinkedList(int len);//创建指定长度的链表([双向][环型])
void printStuInfoLinkedList(StudentInfo** head);//遍历打印链表
int sortStuInfoLinkedList(StudentInfo** head);//链表原地排序(根据id排序升序) 

StudentData* createStuDataNode();//创建空节点
int appendStuDataNode(StudentData** head, StudentData* newStuDataNode);//在链表末尾增加节点
int deleteStuDataNode(StudentData** head, int index);//在链表中删除指定节点
int updateStuDataNode(StudentData** head, int index, StudentData* newStuDataNode);//在链表中替代指定节点
StudentData* getStuDataNodeAtIndex(StudentData** head, int index);//在链表中查询索引的节点
int findStuDataNodeIndex(StudentData** head, char* id);//在链表中查询匹配项(字符串)节点的索引
StudentData* createStuDataLinkedList(int len);//创建指定长度的链表([双向][环型])
void printStuDataLinkedList(StudentData** head);//遍历打印链表
int sortStuDataLinkedList(StudentData** head);//链表原地排序(根据id排序升序) 
#endif // !__FUNTION_H__


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

