//StuDataFuntion.h�ļ�
/*
ѧ��������غ�������
*/
#ifndef __STUDATAFUNTION_H__
#define __STUDATAFUNTION_H__
    //�ڵ�����
    //�ṹ�����ͣ�ѧ������
    #ifndef __STRUCT_STUDENTDATA__
        #define __STRUCT_STUDENTDATA__
        typedef struct StudentData {
            char id[100];
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

    //��������
    StudentData* createStuDataNode();//�����սڵ�
    int appendStuDataNode(StudentData** head, StudentData* newStuDataNode);//������ĩβ���ӽڵ�
    int deleteStuDataNode(StudentData** head, int index);//��������ɾ��ָ���ڵ�
    int updateStuDataNode(StudentData** head, int index, StudentData* newStuDataNode);//�����������ָ���ڵ�
    StudentData* getStuDataNodeAtIndex(StudentData** head, int index);//�������в�ѯ�����Ľڵ�
    int findStuDataNodeIndex(StudentData** head, char* id);//�������в�ѯƥ����(�ַ���)�ڵ������
    StudentData* createStuDataLinkedList(int len);//����ָ�����ȵ�����([˫��][����])
    void printStuDataLinkedList(StudentData** head);//������ӡ����
    int sortStuDataLinkedList(StudentData** head);//����ԭ������(����id��������) 
    void freeStuDataLinkedList(StudentData** head);//�ͷ������ڴ�
    void addStuData();//����ѧ�����ݹ���
    void deleteStuData();//ɾ��ѧ�����ݹ���
    void updateStuData();//�޸Ļ����ѧ�����ݹ���
    void queryStuData();//��ѯѧ�����ݹ���
    void showStuData();//���ѧ�����ݹ���
    StudentData* readStuData();//���ļ��ж�ȡѧ�����ݵ������У����������ͷָ��
    void writeStuData(StudentData** head);//����ָ�������ָ�룬��ѧ����������������Ը�ʽ������ļ���
#endif // !__STUDATAFUNTION_H__