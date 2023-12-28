//StuDataFuntion.h文件
/*
学生数据相关函数声明
*/
#ifndef __STUDATAFUNTION_H__
#define __STUDATAFUNTION_H__
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
            int scoreRanking;
            float evaluationClassmate;
            float scoreMoral;
            float evaluationTeacher;
            float totalScore;
            int totalRanking;
            struct StudentData* next;
        }StudentData;
    #endif // !__STRUCT_STUDENTDATA__

    //函数声明
    StudentData* createStuDataNode();//创建空节点
    int appendStuDataNode(StudentData** head, StudentData* newStuDataNode);//在链表末尾增加节点
    int deleteStuDataNode(StudentData** head, int index);//在链表中删除指定节点
    int updateStuDataNode(StudentData** head, int index, StudentData* newStuDataNode);//在链表中替代指定节点
    StudentData* getStuDataNodeAtIndex(StudentData** head, int index);//在链表中查询索引的节点
    int findStuDataNodeIndex(StudentData** head, char* id);//在链表中查询匹配项(字符串)节点的索引
    StudentData* createStuDataLinkedList(int len);//创建指定长度的链表([双向][环型])
    void printStuDataLinkedList(StudentData** head);//遍历打印链表
    int sortStuDataLinkedList(StudentData** head);//链表原地排序(根据id排序升序) 
    void freeStuDataLinkedList(StudentData** head);//释放链表内存
    void addStuData();//增加学生数据功能
    void deleteStuData();//删除学生数据功能
    void updateStuData();//修改或插入学生数据功能
    void queryStuData();//查询学生数据功能
    void showStuData();//浏览学生数据功能
    StudentData* readStuData();//从文件中读取学生数据到链表中，返回链表的头指针
    void writeStuData(StudentData** head);//输入指向链表的指针，将学生数据链表的内容以格式化输出文件中
#endif // !__STUDATAFUNTION_H__