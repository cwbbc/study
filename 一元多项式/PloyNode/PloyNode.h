/*******************************************************
[�ṹ������] PloyNode
[�ṹ�幦��] ���һԪ����ʽ������
********************************************************/
typedef struct node
{
	float coef;
	int exp;
	struct node *next;

} PloyNode;
/*******************************************************
[��������] start
[��������] ��ʼ��������
[��    ��] PloyNode *����������ͷ���
[�� �� ֵ] ��
********************************************************/
void start(PloyNode **head)
{
	*head=(PloyNode*)malloc(sizeof(PloyNode));                   //����ͷ��㣬��headָʾ���ַ
		(*head)->next=NULL;                                      //���������ΪNULL
}
/*******************************************************
[��������] inset
[��������] ����һԪ����ʽ
[��    ��] PloyNode *��Ҫ����һԪ����ʽ
[�� �� ֵ] ��
********************************************************/
void inset(PloyNode *head, int n)
{
	PloyNode *p, *q;
	int i;
	p = head;
	if (n == 0)
		printf("�����������������룡");

	for (i = 1; i <= n; i++)
	{
		q = (PloyNode*)malloc(sizeof(PloyNode));
		printf("�������%d���ϵ��:", i);
		scanf_s("%f", &q->coef);                                 //����ϵ��
		printf("�������%d���ָ��:", i);
		scanf_s("%d", &q->exp);                                  //����ָ��
		printf("\n");
		q->next = p->next;
		p->next = q;
		p = q;

	}
}
/*******************************************************
[��������] out
[��������] ���һԪ����ʽ
[��    ��] PloyNode *������һԪ����ʽ
[�� �� ֵ] ��
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
		p = p->next;                                            //�������������ж��� x,2x,0x^2,2x^0

	}                                                           //����������һ��
	if (p->coef != 0 && p->exp != 0 && p->coef != 1 && p->exp != 1)
		printf("%gx^%d", p->coef, p->exp);
	if (p->coef != 0 && p->exp == 0)
		printf("%g", p->coef);
	if (p->coef == 1 && p->exp != 0 && p->exp != 1)
		printf("x^%d", p->exp);
	if (p->coef != 0 && p->exp == 1 && p->coef != 1)
		printf("%gx", p->coef);
	if (p->coef == 1 && p->exp == 1)
		printf("x");                                             //�������������ж��� x,2x,0x^2,2x^0
	printf("\n");
}
/*******************************************************
[��������] add
[��������] �������һԪ����ʽ
[��    ��] PloyNode *:����һԪ����ʽ
[�� �� ֵ] ��
********************************************************/
void add(PloyNode *head, PloyNode *head2)
{
	PloyNode *p, *q, *t;
	p = head;
	while (p->next != NULL)
	{
		q = head2;
		while (q->next != NULL)                                  //head��ÿ�������head2��ÿ�������бȽ�
		{
			if (p->next->exp<q->next->exp)                       //headָ����head2ָ��С����ǰ�����
			{
				t = (PloyNode*)malloc(sizeof(PloyNode));
				t->coef = p->next->coef;
				t->exp = p->next->exp;
				t->next = q->next;
				q->next = t;
				break;

			}

			if (p->next->exp == q->next->exp)                    //ָ����Ƚ����ǵ�ϵ�����
			{
				q->next->coef = p->next->coef + q->next->coef;
				break;
			}

			if (p->next->exp>q->next->exp&&q->next->next == NULL) //headָ����head2ָ���󣬲���head2�Ѿ������ֱ꣬�Ӽӵ�head2β��
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