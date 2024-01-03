//StuInfoFuntion.h文件
/*
学生信息相关函数声明
*/
#ifndef __STUINFOFUNTION_H__
#define __STUINFOFUNTION_H__
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

    //函数声明
    StudentInfo* createStuInfoNode();//创建空节点
    int appendStuInfoNode(StudentInfo** head, StudentInfo* newStuInfoNode);//在链表末尾增加节点
    int deleteStuInfoNode(StudentInfo** head, int index);//在链表中删除指定节点
    int updateStuInfoNode(StudentInfo** head, int index, StudentInfo* newStuInfoNode);//在链表中替代指定节点
    StudentInfo* getStuInfoNodeAtIndex(StudentInfo** head, int index);//在链表中查询索引的节点
    int findStuInfoNodeIndex(StudentInfo** head, char* id);//在链表中查询匹配项(字符串)节点的索引
    StudentInfo* createStuInfoLinkedList(int len);//创建指定长度的链表([双向][环型])
    void printStuInfoLinkedList(StudentInfo** head);//遍历打印链表
    int sortStuInfoLinkedList(StudentInfo** head);//链表原地排序(根据id排序升序) 
    void freeStuInfoLinkedList(StudentInfo** head);//释放链表内存
    StudentInfo* readStuInfo();//从文件中读取学生信息到链表中，返回链表的头指针
    int writeStuInfo(StudentInfo** head);//输入指向链表的指针，将学生信息链表的内容以格式化输出文件中
    void addStuInfo();//增加学生信息功能
    void deleteStuInfo();//删除学生信息功能
    void updateStuInfo();//修改或插入学生信息功能
    void queryStuInfo();//查询学生信息功能
    void showStuInfo();//浏览学生信息功能
#endif // !__STUINFOFUNTION_H__

