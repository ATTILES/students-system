//funtion.h�ļ�
/*
����Ҫ�Ĺ��ܺ�������
*/

//��ֹ�������
#ifndef __FUNTION_H__
#define __FUNTION_H__
//��������
int FunAskConfirm();
StudentInfo* createStuInfoNode();
int appendStuInfoNode(StudentInfo** head, StudentInfo* newStudentInfo);
int deleteStuInfoNode(StudentInfo** head, int index);
int updateStuInfoNode(StudentInfo** head, int index, StudentInfo* newStudentInfo);
StudentInfo* getStuInfoNodeAtIndex(StudentInfo** head, int index);
int findStuInfoNodeIndex(StudentInfo** head, char* id);
StudentInfo* createStuInfoLinkedList(int len);
void printStuInfoLinkedList(StudentInfo** head);
void sortStuInfoLinkedList(StudentInfo** head);
#endif // !__FUNTION_H__


