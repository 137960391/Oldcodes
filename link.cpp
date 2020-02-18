#include <stdio.h>
#include <Windows.h>
#include <time.h>

//宏定义
#define NUM 10

//链表声明

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;

//函数声明
Node* CreatList(LinkList p);
void Show(LinkList L);
Node* CreatListW(LinkList L);

void main()
{
	srand((unsigned)time(NULL));  //随机数种子
	Node *L;  //定义链表结构
	//链表初始化
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;    //定义一个空链表；
	//L=CreatList(L); //头插法
	L = CreatListW(L);
	Show(L);
	getchar();


}

Node* CreatList(LinkList p)
{

	for (int i=0; i < NUM; i++)
	{
		Node *r;   //新建一个中间节点
		r = (LinkList)malloc(sizeof(Node));  //开辟内存空间
		r->data = rand() % 100 + 1;
		printf("%d\n",r->data);
		r->next= p->next;
		p->next = r;
	}
	return p;
}

void Show(LinkList L)
{
	
	Node *p;
	p = L->next;
	
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	free(p);
}

Node* CreatListW(LinkList L)
{
	Node *r,*q;
	r = L;
	for (int i = 0; i < NUM; i++)
	{
		Node* p;  //新建一个中间节点
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		printf("%d\n", p->data);
		r->next = p;
		r = p;
		//free(p);
		
	}
	r->next = 0;
	
	return L;
}