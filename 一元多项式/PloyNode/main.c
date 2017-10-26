#include<stdio.h>
#include<malloc.h>
#include"PloyNode.h"
int main()
{
	PloyNode *head, *head2;
	int n, m;
    start(&head);                                                                                 //初始化单链表head
	start(&head2);                                                                                //初始化单链表head2
	printf("/*注意:系数为浮点型，指数为整数<可为负数>。请按指数从小到大顺序输出\n");
	printf("请输入第一个多项式的项数:");
	scanf_s("%d", &n);                                                                            //输入第一个项数
	inset(head, n);                                                                               //输入第一个一元多项式
	printf("该多项式可表示为:");
	out(head);
	printf("\n");
	printf("请输入第二个多项式的项数:");
	scanf_s("%d", &m);                                                                            //输入第二个项数
	inset(head2, m);                                                                              //输入第二个一元多项式
	printf("该多项式可表示为:");
	out(head2);
	printf("\n");
	add(head, head2);
	printf("多项式之和为:");
	out(head2);                                                                                   //输出相加后的一元多项式
	free(head);                                                                                   //释放单链表head
	free(head2);                                                                                  //释放单链表head2
	return 0;
}
