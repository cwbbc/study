#include<stdio.h>
#include<malloc.h>
#include"PloyNode.h"
int main()
{
	PloyNode *head, *head2;
	int n, m;
    start(&head);                                                                                 //��ʼ��������head
	start(&head2);                                                                                //��ʼ��������head2
	printf("/*ע��:ϵ��Ϊ�����ͣ�ָ��Ϊ����<��Ϊ����>���밴ָ����С����˳�����\n");
	printf("�������һ������ʽ������:");
	scanf_s("%d", &n);                                                                            //�����һ������
	inset(head, n);                                                                               //�����һ��һԪ����ʽ
	printf("�ö���ʽ�ɱ�ʾΪ:");
	out(head);
	printf("\n");
	printf("������ڶ�������ʽ������:");
	scanf_s("%d", &m);                                                                            //����ڶ�������
	inset(head2, m);                                                                              //����ڶ���һԪ����ʽ
	printf("�ö���ʽ�ɱ�ʾΪ:");
	out(head2);
	printf("\n");
	add(head, head2);
	printf("����ʽ֮��Ϊ:");
	out(head2);                                                                                   //�����Ӻ��һԪ����ʽ
	free(head);                                                                                   //�ͷŵ�����head
	free(head2);                                                                                  //�ͷŵ�����head2
	return 0;
}
