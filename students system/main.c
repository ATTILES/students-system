/*
ѧ���ۺϲ���ϵͳ V1.0
����������һ��ѧ���ۺϲ���ϵͳ
������Ա����˧124732023002�������124732023011
����ʱ�䣺2023/12/19��ʼ
Github��ַ��https://github.com/ATTILES/students-system.git

*/

/*
ע��
1.����������С�շ����������׵��ʿ�ͷСд�����൥�ʿ�ͷ��д��
2.�ļ������ʽ������csv��ʽ
*/

//�궨��
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS //��VS��ʹ��scanf()��strcmp�Ⱥ���
#endif // !_CRT_SECURE_NO_WARNINGS

//�⺯������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StuInfoFuntion.h"
#include "StuDataFuntion.h"
#include "OtherFuntion.h"

//main����
int main() {
    int select = 0;
    while (1) {
        showMenu();
        select = -1;
        scanf("%d", &select);
        rewind(stdin);//��ձ�׼���뻺����
        switch (select) {
        case 1:
            addStuInfo();
            break;
        case 2:
            deleteStuInfo();
            break;
        case 3:
            updateStuInfo();
            break;
        case 4:
            queryStuInfo();
            break;
        case 5:
            showStuInfo();
            break;
        case 6:
            addStuData();
            break;
        case 7:
            deleteStuData();
            break;
        case 8:
            updateStuData();
            break;
        case 9:
            queryStuData();
            break;
        case 10:
            showStuData();
            break;
        case 0:
            exitSystem();
            break;
        default:
            printf("���ܱ����Ч����������ȷ�Ĺ��ܱ�š�\n");
            break;
        }
        printf("�밴enter��ȷ��\n");
        //getchar();
        rewind(stdin);//��ձ�׼���뻺����
    }
    return 0;
}