//funtion.h�ļ�
/*
����Ҫ�Ĺ��ܺ�������
*/


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "funtion.c"
//�ڵ����� 
//�ṹ�����ͣ�ѧ����Ϣ
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

//�ڵ�����
//�ṹ�����ͣ�ѧ������
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

//��ֹ�������
#ifndef __FUNTION_H__
#define __FUNTION_H__
//��������
int FunAskConfirm();//�����û�ȷ��,����Y��yȷ��

StudentInfo* createStuInfoNode();//�����սڵ�
int appendStuInfoNode(StudentInfo** head, StudentInfo* newStuInfoNode);//������ĩβ���ӽڵ�
int deleteStuInfoNode(StudentInfo** head, int index);//��������ɾ��ָ���ڵ�
int updateStuInfoNode(StudentInfo** head, int index, StudentInfo* newStuInfoNode);//�����������ָ���ڵ�
StudentInfo* getStuInfoNodeAtIndex(StudentInfo** head, int index);//�������в�ѯ�����Ľڵ�
int findStuInfoNodeIndex(StudentInfo** head, char* id);//�������в�ѯƥ����(�ַ���)�ڵ������
StudentInfo* createStuInfoLinkedList(int len);//����ָ�����ȵ�����([˫��][����])
void printStuInfoLinkedList(StudentInfo** head);//������ӡ����
int sortStuInfoLinkedList(StudentInfo** head);//����ԭ������(����id��������) 

StudentData* createStuDataNode();//�����սڵ�
int appendStuDataNode(StudentData** head, StudentData* newStuDataNode);//������ĩβ���ӽڵ�
int deleteStuDataNode(StudentData** head, int index);//��������ɾ��ָ���ڵ�
int updateStuDataNode(StudentData** head, int index, StudentData* newStuDataNode);//�����������ָ���ڵ�
StudentData* getStuDataNodeAtIndex(StudentData** head, int index);//�������в�ѯ�����Ľڵ�
int findStuDataNodeIndex(StudentData** head, char* id);//�������в�ѯƥ����(�ַ���)�ڵ������
StudentData* createStuDataLinkedList(int len);//����ָ�����ȵ�����([˫��][����])
void printStuDataLinkedList(StudentData** head);//������ӡ����
int sortStuDataLinkedList(StudentData** head);//����ԭ������(����id��������) 
#endif // !__FUNTION_H__


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

