/*******************************************************
[结构体名称] PloyNode
[结构体功能] 存放一元多项式的链表
********************************************************/
typedef struct node
{
	float coef;
	int exp;
	struct node *next;

} PloyNode;
/*******************************************************
[函数名称] start
[函数功能] 初始化单链表
[参    数] PloyNode *：操作链表头结点
[返 回 值] 无
********************************************************/
void start(PloyNode **head)
{
	*head=(PloyNode*)malloc(sizeof(PloyNode));                   //申请头结点，由head指示其地址
		(*head)->next=NULL;                                      //至结束标记为NULL
}
/*******************************************************
[函数名称] inset
[函数功能] 插入一元多项式
[参    数] PloyNode *：要保存一元多项式
[返 回 值] 无
********************************************************/
void inset(PloyNode *head, int n)
{
	PloyNode *p, *q;
	int i;
	p = head;
	if (n == 0)
		printf("输入有误，请重新输入！");

	for (i = 1; i <= n; i++)
	{
		q = (PloyNode*)malloc(sizeof(PloyNode));
		printf("请输入第%d项的系数:", i);
		scanf_s("%f", &q->coef);                                 //输入系数
		printf("请输入第%d项的指数:", i);
		scanf_s("%d", &q->exp);                                  //输入指数
		printf("\n");
		q->next = p->next;
		p->next = q;
		p = q;

	}
}
/*******************************************************
[函数名称] out
[函数功能] 输出一元多项式
[参    数] PloyNode *：操作一元多项式
[返 回 值] 无
********************************************************/
void out(PloyNode *head)
{
	PloyNode *p;
	p = (PloyNode*)malloc(sizeof(PloyNode));
	p = head->next;
	while (p->next != NULL)
	{
		if (p->coef != 0 && p->exp != 0 && p->coef != 1 && p->exp != 1)
			printf("%gx^%d+", p->coef, p->exp);
		if (p->coef != 0 && p->exp == 0)
			printf("%g+", p->coef);
		if (p->coef == 1 && p->exp != 0 && p->exp != 1)
			printf("x^%d+", p->exp);
		if (p->coef != 0 && p->exp == 1 && p->coef != 1)
			printf("%gx+", p->coef);
		if (p->coef == 1 && p->exp == 1)
			printf("x+");
		p = p->next;                                            //特殊条件进行判断如 x,2x,0x^2,2x^0

	}                                                           //单独输出最后一项
	if (p->coef != 0 && p->exp != 0 && p->coef != 1 && p->exp != 1)
		printf("%gx^%d", p->coef, p->exp);
	if (p->coef != 0 && p->exp == 0)
		printf("%g", p->coef);
	if (p->coef == 1 && p->exp != 0 && p->exp != 1)
		printf("x^%d", p->exp);
	if (p->coef != 0 && p->exp == 1 && p->coef != 1)
		printf("%gx", p->coef);
	if (p->coef == 1 && p->exp == 1)
		printf("x");                                             //特殊条件进行判断如 x,2x,0x^2,2x^0
	printf("\n");
}
/*******************************************************
[函数名称] add
[函数功能] 相加两个一元多项式
[参    数] PloyNode *:操作一元多项式
[返 回 值] 无
********************************************************/
void add(PloyNode *head, PloyNode *head2)
{
	PloyNode *p, *q, *t;
	p = head;
	while (p->next != NULL)
	{
		q = head2;
		while (q->next != NULL)                                  //head的每个结点与head2的每个结点进行比较
		{
			if (p->next->exp<q->next->exp)                       //head指数比head2指数小进行前插操作
			{
				t = (PloyNode*)malloc(sizeof(PloyNode));
				t->coef = p->next->coef;
				t->exp = p->next->exp;
				t->next = q->next;
				q->next = t;
				break;

			}

			if (p->next->exp == q->next->exp)                    //指数相等将它们的系数相加
			{
				q->next->coef = p->next->coef + q->next->coef;
				break;
			}

			if (p->next->exp>q->next->exp&&q->next->next == NULL) //head指数比head2指数大，并且head2已经遍历完，直接加到head2尾部
			{
				t = (PloyNode*)malloc(sizeof(PloyNode));
				t->coef = p->next->coef;
				t->exp = p->next->exp;
				t->next = NULL;
				q->next->next = t;
				break;
			}
			q = q->next;
		}
		p = p->next;
	}
}