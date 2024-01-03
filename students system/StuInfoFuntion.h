//StuInfoFuntion.h�ļ�
/*
ѧ����Ϣ��غ�������
*/
#ifndef __STUINFOFUNTION_H__
#define __STUINFOFUNTION_H__
    //�ڵ����� 
    //�ṹ�����ͣ�ѧ����Ϣ
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

    //��������
    StudentInfo* createStuInfoNode();//�����սڵ�
    int appendStuInfoNode(StudentInfo** head, StudentInfo* newStuInfoNode);//������ĩβ���ӽڵ�
    int deleteStuInfoNode(StudentInfo** head, int index);//��������ɾ��ָ���ڵ�
    int updateStuInfoNode(StudentInfo** head, int index, StudentInfo* newStuInfoNode);//�����������ָ���ڵ�
    StudentInfo* getStuInfoNodeAtIndex(StudentInfo** head, int index);//�������в�ѯ�����Ľڵ�
    int findStuInfoNodeIndex(StudentInfo** head, char* id);//�������в�ѯƥ����(�ַ���)�ڵ������
    StudentInfo* createStuInfoLinkedList(int len);//����ָ�����ȵ�����([˫��][����])
    void printStuInfoLinkedList(StudentInfo** head);//������ӡ����
    int sortStuInfoLinkedList(StudentInfo** head);//����ԭ������(����id��������) 
    void freeStuInfoLinkedList(StudentInfo** head);//�ͷ������ڴ�
    StudentInfo* readStuInfo();//���ļ��ж�ȡѧ����Ϣ�������У����������ͷָ��
    int writeStuInfo(StudentInfo** head);//����ָ�������ָ�룬��ѧ����Ϣ����������Ը�ʽ������ļ���
    void addStuInfo();//����ѧ����Ϣ����
    void deleteStuInfo();//ɾ��ѧ����Ϣ����
    void updateStuInfo();//�޸Ļ����ѧ����Ϣ����
    void queryStuInfo();//��ѯѧ����Ϣ����
    void showStuInfo();//���ѧ����Ϣ����
#endif // !__STUINFOFUNTION_H__

