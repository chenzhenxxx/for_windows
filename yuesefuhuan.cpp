#include<iostream>
using namespace std;

typedef struct lnode
{
	int data;
	int num;
	struct lnode* next;
}LNode, * LinkList;      //链表

LinkList Creat(int n)
{
	LinkList L = NULL;         //不带头结点的链表
	LNode* s, * r = NULL;
	int x;
	for (int i = 1; i <= n; i++)
	{
		LNode* s = new LNode;
		cin >> x;
		s->data = x;
		s->num = i;
		if (L == NULL) L = s;
		else r->next = s;
		r = s;
	}
	if (r != NULL) r->next = L;
	return L;
}

void Circle(LinkList& H, int m, int n)
{
	LinkList q, p = H;
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i < m; i++)
		{
			p = p->next;
		}
		m = p->data;
		cout << p->num << " ";
		q = p->next;
		p->num = q->num;
		p->data = q->data;
		p->next = q->next;
		free(q);
	}
}

int main()
{
	int m, n;
	cout << "请输入人数" << endl;
	cin >> n;
	cout << "请按顺序输入各位的密码" << endl;
	LinkList L = new LNode;
	if (L == NULL) {
		cout<<"内存分配不成功！"<<endl;
	}
	else
	{
		L = Creat(n);
	}
	cout << "请给定第一个报数上限值" << endl;
	cin >> m;
	cout << "出列顺序如下" << endl;
	Circle(L, m, n);
	return 0;
}

