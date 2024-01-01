//�궨��
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS //��VS��ʹ��scanf()��strcmp�Ⱥ���
#endif // !_CRT_SECURE_NO_WARNINGS

//�⺯������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OtherFuntion.h"
#include "StuDataFuntion.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//ѧ������������ش���
//ע������ܿ����ں���������ڵ���ڲ����ݣ�����һ��id��ΪΨһ��ʶ

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
    float scoreRanking;
    float evaluationClassmate;
    float scoreMoral;
    float evaluationTeacher;
    float totalScore;
    float totalRanking;
    struct StudentData* next;
}StudentData;
#endif // !__STRUCT_STUDENTDATA__

//�����սڵ�
//��������
//����ֵ��ָ��ڵ��ָ��
StudentData* createStuDataNode() {
    StudentData* newStuDataNode = (StudentData*)calloc(1, sizeof(StudentData));
    strcpy(newStuDataNode->id, "");  // ��ʼ��
    newStuDataNode->scoreChinese = 0;  // ��ʼ��
    newStuDataNode->scoreMath = 0;  // ��ʼ��
    newStuDataNode->scoreEnglish = 0;  // ��ʼ��
    newStuDataNode->scoreAverage = 0;  // ��ʼ��
    newStuDataNode->scoreRanking = 0;  // ��ʼ��
    newStuDataNode->evaluationClassmate = 0;  // ��ʼ��
    newStuDataNode->scoreMoral = 0;  // ��ʼ��
    newStuDataNode->evaluationTeacher = 0;  // ��ʼ��
    newStuDataNode->totalScore = 0;  // ��ʼ��
    newStuDataNode->totalRanking = 0;  // ��ʼ��
    newStuDataNode->next = NULL;  // ��ʼ��
    return newStuDataNode;
}

//������ĩβ���ӽڵ�
//������ָ�������ָ�룬�½ڵ��ָ��
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int appendStuDataNode(StudentData** head, StudentData* newStuDataNode) {
    if (*head == NULL) {//�������Ϊ�գ���ͷָ��ָ���½ڵ�
        *head = newStuDataNode;
        (*head)->next = NULL;
    }
    else {// ���򣬱��������ҵ����һ���ڵ� 
        StudentData* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStuDataNode;
        newStuDataNode->next = NULL;
    }
    return 1; // ���ӳɹ�  
}

//��������ɾ��ָ���ڵ�
//������ָ�������ָ�룬ָ���ڵ������
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int deleteStuDataNode(StudentData** head, int index) {
    if (*head == NULL) {
        return 0; // ����Ϊ�գ�ɾ��ʧ��  
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
        return 0; // ����Խ�磬ɾ��ʧ��  
    }
    else if (previous == NULL) {
        // ɾ������ͷ�ڵ�  
        *head = (*head)->next;
    }
    else {
        // ɾ�����Ƿ�ͷ�ڵ�  
        previous->next = current->next;
    }
    free(current); // �ͷű�ɾ���ڵ���ڴ�  
    return 1; // ɾ���ɹ�  
}

//�����������ָ���ڵ�
//������ָ�������ָ�룬ָ���ڵ�����������ԭ�ڵ���½ڵ�
//����ֵ���ɹ�����1��ʧ�ܷ���0 
int updateStuDataNode(StudentData** head, int index, StudentData* newStuDataNode) {
    if (*head == NULL) {
        return 0; // ����Ϊ�գ����ʧ��  
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
        return 0; // ����Խ�磬���ʧ��  
    }
    else if (previous == NULL) {
        //�������ͷ�ڵ�  
        (newStuDataNode)->next = current->next;
        *head = newStuDataNode;
    }
    else {
        //������Ƿ�ͷ�ڵ�  
        previous->next = newStuDataNode;
        (newStuDataNode)->next = current->next;
    }
    free(current); // �ͷű�����ڵ���ڴ�  
    return 1; // ����ɹ�  
}

//�������в�ѯ�����Ľڵ�
//������ָ�������ָ�룬����
//����ֵ��ָ��ڵ��ָ��
StudentData* getStuDataNodeAtIndex(StudentData** head, int index) {
    // ��������Ƿ�Ϊ��  
    if (*head == NULL) {
        return NULL; // ����Ϊ�գ�����NULL  
    }

    // ������������ָ�������Ľڵ�  
    StudentData* current = *head;
    int count = 0;
    while (current->next != NULL && count < index) {
        current = current->next;
        count++;
    }

    // ����Ƿ��ҵ���ָ�������Ľڵ�  
    if (current == NULL || count > index) {
        return NULL; // ����Խ���δ�ҵ�������NULL  
    }
    else {
        return current; // �����ҵ��Ľڵ�ָ��  
    }
}

//�������в�ѯƥ����(�ַ���)�ڵ������
//������ָ�������ָ�룬ƥ����(�ַ���)
//����ֵ��ָ���ڵ������ 
int findStuDataNodeIndex(StudentData** head, char* id) {
    // ��������Ƿ�Ϊ��  
    if (*head == NULL) {
        return -1; // ����Ϊ�գ�����-1��ʾʧ�� 
    }

    StudentData* current = *head;
    int index = 0;// ������0��ʼ����
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            return index; // �ҵ�Ŀ��ڵ㣬��������
        }
        current = current->next; // �ƶ�����һ���ڵ�  
        index++; // �������� 
    }
    return -1; // δ�ҵ�Ŀ��ڵ㣬����-1��ʾʧ��  
}

//����ָ�����ȵ�����([˫��][����])
//������ָ�������ָ�룬������ 
//����ֵ�������ͷָ�� 
StudentData* createStuDataLinkedList(int len) {
    StudentData* head = NULL;
    StudentData* newStuDataNode = NULL;
    char* tempString = (char*)calloc(1, sizeof(StudentData));
    int i = 0;
    while (i < len) {
        newStuDataNode = createStuDataNode();
        //printf("������id:\n");//��������ڵ������ 
        //fgets(tempString, sizeof(newStuDataNode->id), stdin);
        //strcpy(newStuDataNode->id, strtok(tempString, "\n"));
        if (appendStuDataNode(&head, newStuDataNode)) {
            printf("����ڵ�ɹ�\n");
        }
        else {
            printf("����ڵ�ʧ��\n");
        }
        i++;
    }
    return head;
}

//������ӡ����
//������ָ�������ָ��
//����ֵ����
void printStuDataLinkedList(StudentData** head) {
    StudentData* current = *head;
    while (current != NULL) {
        printf("%s\n", current->id);
        current = current->next;
    }
    printf("\n");
    system("pause");
}

//����ԭ������(����id��������) 
//������ָ�������ָ��
//����ֵ���ɹ�����1��ʧ�ܷ���0��
int sortStuDataLinkedList(StudentData** head) {
    StudentData* current = *head;
    StudentData* previous = NULL;
    int indexI = 0, indexJ = 0, count = 0;

    for (count = 0, current = *head; current != NULL; current = current->next) {//������������ڵ�����
        count++;
    }
    if (count > 0) {
        for (indexI = 0; indexI < count - 1; indexI++) {
            current = *head;
            previous = NULL;
            for (indexJ = 0; indexJ < count - indexI - 1; indexJ++) {
                if (strcmp(current->id, current->next->id) > 0) {//��ϵ��4���ڵ�1->2->3->4��previousָ��1��currentָ��2��3�����Ҳ�Ϊ�սڵ㣬4����Ϊ�սڵ�
                    if (previous == NULL) {//�׸�Ԫ�ؾ���Ҫ��������ʱprevious->next�����ڣ�ʹ��previous->�ᱨ��
                        *head = current->next;//previousΪNULL��currentָ��1������Ҫ*headָ��2����ʱNULL��1->2->3->4��*head==2
                        current->next = current->next->next;//��ʱ1->3->4��*head==2->3->4
                        (*head)->next = current;//��ʱ��head==2->1->3->4
                        current = *head;//����currentָ���λ�ã�previousָ��NULL��currentָ��1������1��2����λ�ã�����previous��current�м����һ��2������
                    }
                    else {
                        previous->next = current->next;//��ʱ1->3->4,2->3->4
                        current->next = current->next->next;//��ʱ1->3->4,2->4
                        previous->next->next = current;//��ʱ1->3->2->4����ɽڵ�2��3�Ľ���
                        current = previous->next;//����currentָ���λ�ã�previousָ��1��currentָ��2������2��3����λ�ã�����previous��current�м����һ��3������
                    }
                }
                previous = current;
                current = current->next;
            }
        }
    }
    else {
        printf("����ʧ�ܣ�����Ϊ�ա�\n");
        return 0;
    }
    return 1;
}

//�ͷ������ڴ�
void freeStuDataLinkedList(StudentData** head) {
    StudentData* current = *head;
    StudentData* previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }
}

//������������תΪ����2λС�����ַ���
void formatFloat(float num, char* result) {
    sprintf(result, "%.2f", num); // ʹ��sprintf��������������ʽ��Ϊ�ַ���������2λС��
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//���ļ��ж�ȡѧ�����ݵ������У����������ͷָ��
StudentData* readStuData() {
    FILE* fp = NULL;
    StudentData* head = NULL;
    char tempString[158]; // ��ʱ�ַ���������ÿ�����ݲ�����158���ַ�

    if ((fp = fopen("StudentData.csv", "r+")) == NULL) {
        if ((fp = fopen("StudentData.csv", "w+")) == NULL) {
            fclose(fp);
            printf("�ļ������ڻ��޷����ļ�\n");
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

//����ָ�������ָ�룬��ѧ����Ϣ����������Ը�ʽ������ļ���
int writeStuData(StudentData** head) {
    FILE* fp = NULL;
    StudentData* current = *head;
    StudentData* currentExternal = *head;
    if ((fp = fopen("StudentData.csv", "w+")) == NULL) {//�ļ�������
        fclose(fp);
        printf("�ļ������ڻ��޷����ļ�");
        return 0;
    }
    //�ļ�����
    sortStuDataLinkedList(head);//����ѧ���������������
    //���¼��㿼�Գɼ����ۺϲ����ܷ�
    for (current = *head; current != NULL; current = current->next){
        current->scoreAverage = (current->scoreChinese + current->scoreMath + current->scoreEnglish) / 3;
        current->totalScore = current->scoreAverage * 0.6 + current->evaluationClassmate * 0.1 + current->scoreMoral * 0.1 + current->evaluationTeacher * 0.2;
    }
    //���¼�������
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
    //��������������������Ը�ʽ������ļ���
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

//���ѧ�����ݺ���
void addStuData() {
    StudentData* head = readStuData();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentData* current = head;//λ��ָ��
    StudentData* previous = NULL;//λ��ָ��
    StudentData* newStuDataNode = NULL;//�½ڵ�
    int index = 0;
    int flag = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("���ѧ�����ݹ���\n");
    while (1) {
        newStuDataNode = createStuDataNode();//�����ڵ�
        printf("������Ҫ���ѧ����ѧ�ţ�");
        fgets(newStuDataNode->id, sizeof(newStuDataNode->id), stdin);//�ӱ�׼������stdin��ȡ����Ϊsizeof(newStuDataNode->id)���ַ���д��tempString
        newStuDataNode->id[strcspn(newStuDataNode->id, "\n")] = '\0';  // ɾ���ַ���ĩβ�Ļس���  
        printf("���������ĳɼ���");
        scanf("%f", &newStuDataNode->scoreChinese);
        printf("��������ѧ�ɼ���");
        scanf("%f", &newStuDataNode->scoreMath);
        printf("������Ӣ��ɼ���");
        scanf("%f", &newStuDataNode->scoreEnglish);
        newStuDataNode->scoreAverage = (newStuDataNode->scoreChinese + newStuDataNode->scoreMath + newStuDataNode->scoreEnglish) / 3;
        printf("��ǰ���Գɼ�Ϊ��%.2f\n", newStuDataNode->scoreAverage);
        for (newStuDataNode->scoreRanking = 1, current = head; current != NULL; current = current->next) {//ÿ��һ�˳ɼ����ڵ�ǰ������������һλ
            if (current->scoreAverage > newStuDataNode->scoreAverage) {
                newStuDataNode->scoreRanking++;
            }
        }
        printf("��ǰ���Գɼ�����Ϊ��%f\n", newStuDataNode->scoreRanking);
        printf("������ͬѧ�����֣�");
        scanf("%f", &newStuDataNode->evaluationClassmate);
        printf("������Ʒ�³ɼ���");
        scanf("%f", &newStuDataNode->scoreMoral);
        printf("�������ον�ʦ���֣�");
        scanf("%f", &newStuDataNode->evaluationTeacher);
        newStuDataNode->totalScore = newStuDataNode->scoreAverage * 0.6 + newStuDataNode->evaluationClassmate * 0.1 + newStuDataNode->scoreMoral * 0.1 + newStuDataNode->evaluationTeacher *0.2;
        printf("��ǰ�ۺϲ����ܷ�Ϊ��%.2f\n", newStuDataNode->totalScore);
        for (newStuDataNode->totalRanking = 1, current = head; current != NULL; current = current->next) {//ÿ��һ���ָܷ��ڵ�ǰ������������һλ
            if (current->totalScore > newStuDataNode->totalScore) {
                newStuDataNode->totalRanking++;
            }
        }
        printf("��ǰ�ۺϲ�������Ϊ��%f\n", newStuDataNode->totalRanking);
        if (strlen(newStuDataNode->id) > 0) {
            index = findStuDataNodeIndex(&head, newStuDataNode->id);//����id��ѯ�ڵ������ֵ�������ڷ���-1
            if (index == -1) {
                appendStuDataNode(&head, newStuDataNode);//���½ڵ���ӵ�������
                flag = writeStuData(&head);//������д���ļ�
                if (flag == 1) {
                    printf("���ѧ�����ݳɹ���\n");
                }
                else {
                    printf("���ѧ������ʧ�ܡ�\n");
                }
            }
            else {
                printf("���ѧ������ʧ�ܣ��Ѵ��ڸ�ѧ�������ݡ�\n");
            }
        }
        else {
            printf("���ѧ������ʧ�ܣ�ѧ����Ч��\n");
        }
        printf("�Ƿ��������ѧ������? Y/N\n");
        if (FunAskConfirm() == 0) {//�����������ͷ��ڴ沢�˳�����
            freeStuDataLinkedList(&head);//�ͷ������ڴ�
            return;
        }
    }
}

//ɾ��ѧ�����ݺ���
void deleteStuData() {
    StudentData* head = readStuData();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentData* current = head;//λ��ָ��
    StudentData* previous = NULL;//λ��ָ��
    char* tempString = (char*)calloc(1, sizeof(StudentData));//��ʱ�ַ���
    int tempInt = 0;
    int index = 0;
    int flag = 0;
    int flag2 = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("ɾ��ѧ�����ݹ���\n");
    while (1) {
        printf("������Ҫɾ����ѧ��ѧ�ţ�");
        fgets(tempString, sizeof(tempString), stdin);//�ӱ�׼������stdin��ȡ����Ϊsizeof(newStuDataNode->id)���ַ���д��tempString
        tempString[strcspn(tempString, "\n")] = '\0';// ɾ���ַ���ĩβ�Ļس���  
        if (strlen(tempString) > 0) {
            index = findStuDataNodeIndex(&head, tempString);//����id��ѯ�ڵ������ֵ�������ڷ���-1
            if (index != -1) {
                current = head;
                tempInt = 0;
                while (tempInt < index) {//�ƶ�����Ӧ�ڵ�
                    current = current->next;
                    tempInt++;
                }
                printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", \
                    "ѧ��", "����", "��ѧ", "Ӣ��", "���Գɼ�", "��������", \
                    "ͬѧ����", "Ʒ�³ɼ�", "��ʦ����", "�۲��ܷ�", "�۲�����");
                printf("------------------------------------------------------------------------------------------------------------\n");
                printf("%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", \
                    current->id, current->scoreChinese, current->scoreMath, current->scoreEnglish, current->scoreAverage, current->scoreRanking, \
                    current->evaluationClassmate, current->scoreMoral, current->evaluationTeacher, current->totalScore, current->totalRanking);
                printf("�Ƿ�ȷ��ɾ����ѧ������Ϣ��Y/N\n");
                if (FunAskConfirm() == 1) {
                    flag = deleteStuDataNode(&head, index);//���ڵ��������ɾ��
                    flag2 = writeStuData(&head);//������д���ļ�
                    if (flag == 1 && flag2 == 1) {
                        printf("ɾ��ѧ����Ϣ�ɹ���\n");
                    }
                    else {
                        printf("ɾ��ѧ����Ϣʧ�ܣ�д���ļ�ʧ�ܡ�\n");
                    }
                }
                else {
                    printf("�ѷ���ɾ��������\n");
                }
            }
            else {
                printf("ɾ��ѧ����Ϣʧ�ܣ������ڸ�ѧ����\n");
            }
        }
        else {
            printf("ɾ��ѧ����Ϣʧ�ܣ�ѧ����Ч��\n");
        }
        printf("�Ƿ����ɾ��ѧ����Ϣ��Y/N\n");
        if (FunAskConfirm() == 0) {//�����������ͷ��ڴ沢�˳�����
            freeStuDataLinkedList(&head);//�ͷ������ڴ�
            return;
        }
    }
}

//�޸�ѧ�����ݺ���
void updateStuData() {
    StudentData* head = readStuData();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentData* current = head;//λ��ָ��
    StudentData* previous = NULL;//λ��ָ��
    StudentData* newStuDataNode = NULL;//�½ڵ�
    char* tempString = (char*)calloc(1, sizeof(StudentData));//��ʱ�ַ���
    int index = 0;
    int flag = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("�޸�ѧ�����ݹ���\n");
    while (1) {
        newStuDataNode = createStuDataNode();//�����ڵ�
        printf("������Ҫ�޸Ļ����ѧ����ѧ�ţ�");
        fgets(newStuDataNode->id, sizeof(newStuDataNode->id), stdin);//�ӱ�׼������stdin��ȡ����Ϊsizeof(newStuDataNode->id)���ַ���д��tempString
        newStuDataNode->id[strcspn(newStuDataNode->id, "\n")] = '\0';// ɾ���ַ���ĩβ�Ļس���  
        printf("���������ĳɼ���");
        scanf("%f", &newStuDataNode->scoreChinese);
        printf("��������ѧ�ɼ���");
        scanf("%f", &newStuDataNode->scoreMath);
        printf("������Ӣ��ɼ���");
        scanf("%f", &newStuDataNode->scoreEnglish);
        newStuDataNode->scoreAverage = (newStuDataNode->scoreChinese + newStuDataNode->scoreMath + newStuDataNode->scoreEnglish) / 3;
        for (newStuDataNode->scoreRanking = 1, current = head; current != NULL; current = current->next) {//ÿ��һ�˳ɼ����ڵ�ǰ������������һλ
            if (current->scoreAverage > newStuDataNode->scoreAverage) {
                newStuDataNode->scoreRanking++;
            }
        }
        printf("������ͬѧ�����֣�");
        scanf("%f", &newStuDataNode->evaluationClassmate);
        printf("������Ʒ�³ɼ���");
        scanf("%f", &newStuDataNode->scoreMoral);
        printf("�������ον�ʦ���֣�");
        scanf("%f", &newStuDataNode->evaluationTeacher);
        newStuDataNode->totalScore = newStuDataNode->scoreAverage * 0.6 + newStuDataNode->evaluationClassmate * 0.1 + newStuDataNode->scoreMoral * 0.1 + newStuDataNode->evaluationTeacher * 0.2;
        for (newStuDataNode->totalRanking = 1, current = head; current != NULL; current = current->next) {//ÿ��һ���ָܷ��ڵ�ǰ������������һλ
            if (current->totalScore > newStuDataNode->totalScore) {
                newStuDataNode->totalRanking++;
            }
        }
        if (strlen(newStuDataNode->id) > 0) {
            index = findStuDataNodeIndex(&head, newStuDataNode->id);//����id��ѯ�ڵ������ֵ�������ڷ���-1
            if (index != -1) {//�޸�ѧ����Ϣ
                flag = updateStuDataNode(&head, index, newStuDataNode);
            }
            else {//����ѧ����Ϣ
                flag = appendStuDataNode(&head, newStuDataNode);
            }
            flag = writeStuData(&head);//������д���ļ�
            if (flag == 1) {
                printf("�޸Ļ����ѧ�����ݳɹ���\n");
            }
            else {
                printf("�޸Ļ����ѧ������ʧ�ܣ�д���ļ�ʧ�ܡ�\n");
            }
        }
        else {
            printf("�޸Ļ����ѧ������ʧ�ܣ�ѧ����Ч��\n");
        }
        printf("�Ƿ�����޸Ļ����ѧ�����ݡ�Y/N\n");
        if (FunAskConfirm() == 0) {//�����������ͷ��ڴ沢�˳�����
            freeStuDataLinkedList(&head);//�ͷ������ڴ�
            return;
        }
    }
}

//��ѯѧ�����ݺ���
void queryStuData() {
    StudentData* head = readStuData();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentData* current = head;//λ��ָ��
    StudentData* previous = NULL;//λ��ָ��
    char* tempString = (char*)calloc(1, sizeof(StudentData));//��ʱ�ַ���
    int tempInt = 0;
    int index = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("��ѯѧ�����ݹ���\n");
    while (1) {
        printf("������Ҫ��ѯ��ѧ��ѧ�ţ�");
        fgets(tempString, sizeof(tempString), stdin);//�ӱ�׼������stdin��ȡ����Ϊsizeof(newStuDataNode->id)���ַ���д��tempString
        tempString[strcspn(tempString, "\n")] = '\0';// ɾ���ַ���ĩβ�Ļس���  
        if (strlen(tempString) > 0) {
            index = findStuDataNodeIndex(&head, tempString);//����id��ѯ�ڵ������ֵ�������ڷ���-1
            if (index != -1) {
                current = head;
                tempInt = 0;
                while (tempInt < index) {//�ƶ�����Ӧ�ڵ�
                    current = current->next;
                    tempInt++;
                }
                printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", \
                    "ѧ��", "����", "��ѧ", "Ӣ��", "���Գɼ�", "��������", \
                    "ͬѧ����", "Ʒ�³ɼ�", "��ʦ����", "�۲��ܷ�", "�۲�����");
                printf("------------------------------------------------------------------------------------------------------------\n");
                printf("%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", \
                    current->id, current->scoreChinese, current->scoreMath, current->scoreEnglish, current->scoreAverage, current->scoreRanking, \
                    current->evaluationClassmate, current->scoreMoral, current->evaluationTeacher, current->totalScore, current->totalRanking);
            }
            else {
                printf("��ѯѧ������ʧ�ܣ������ڸ�ѧ����\n");
            }
        }
        else {
            printf("��ѯѧ������ʧ�ܣ�ѧ����Ч��\n");
        }
        printf("�Ƿ������ѯѧ�����ݡ�Y/N\n");
        if (FunAskConfirm() == 0) {//�����������ͷ��ڴ沢�˳�����
            freeStuDataLinkedList(&head);//�ͷ������ڴ�
            return;
        }
    }
}

//���ѧ�����ݺ���
void showStuData()
{
    StudentData* head = readStuData();//���ļ��ж�ȡ�������ݲ�תΪ����
    StudentData* current = head;//λ��ָ��
    StudentData* previous = NULL;//λ��ָ��
    char* tempString = (char*)calloc(1, sizeof(StudentData));//��ʱ�ַ���
    int tempInt = 0;
    int index = 0;

    system("cls");  // Windowsϵͳ��������  
    printf("���ѧ����Ϣ����\n");
    printf("\n                              ѧ����Ϣ����\n\n");
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", \
        "ѧ��", "����", "��ѧ", "Ӣ��", "���Գɼ�", "��������", \
        "ͬѧ����", "Ʒ�³ɼ�", "��ʦ����", "�۲��ܷ�", "�۲�����");
    printf("------------------------------------------------------------------------------------------------------------\n");
    current = head;
    while (current != NULL) {//�������
        printf("%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", \
            current->id, current->scoreChinese, current->scoreMath, current->scoreEnglish, current->scoreAverage, current->scoreRanking, \
            current->evaluationClassmate, current->scoreMoral, current->evaluationTeacher, current->totalScore, current->totalRanking);
        current = current->next;
    }
    printf("�Ƿ��˳����ѧ����Ϣ��Y/N\n");
    if (FunAskConfirm() == 0) {//�����������ͷ��ڴ沢�˳�����
        freeStuDataLinkedList(&head);//�ͷ������ڴ�
        return;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++