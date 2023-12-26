//funtion.h�ļ�
/*
����Ҫ�Ĺ��ܺ�������
*/

//�ڵ����� ��
#ifndef __STRUCT_STUDENTINFOMATION__
#define __STRUCT_STUDENTINFOMATION__
typedef struct StudentInfomation {
    char id[20];
    char name[20];
    char sex[10];
    char homeAddress[100];
    char phone[20];
    struct StudentInfomation* next;
}StudentInfo,*Pointer;
#endif // !__STRUCT_STUDENTINFOMATION__

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
void sortStuInfoLinkedList(StudentInfo** head);//ûд�� //����ԭ������(����id��������) 
#endif // !__FUNTION_H__


