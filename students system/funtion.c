/*
funtion.c
һЩ�����ʸߵĺ���
*/

//�⺯������
#include <stdio.h>
#include <stdlib.h>

//�����û�ȷ��,����Y��yȷ��
int FunAskConfirm() {
    char confirm = ' ';
    while(1){
        confirm = getchar();
        rewind(stdin);//��ձ�׼���뻺����
        if (confirm == 'Y' || confirm == 'y') {
            return 1;
        }
        else if (confirm == 'N' || confirm == 'n') {
            return 0;
        }
        else {
            printf("����Y��yȷ�ϣ�����N��nȡ��\n");
        }
    }
}