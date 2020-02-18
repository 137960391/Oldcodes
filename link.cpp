#include <stdio.h>
#include <Windows.h>
#include <time.h>

//�궨��
#define NUM 10

//��������

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;

//��������
Node* CreatList(LinkList p);
void Show(LinkList L);
Node* CreatListW(LinkList L);

void main()
{
	srand((unsigned)time(NULL));  //���������
	Node *L;  //��������ṹ
	//�����ʼ��
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;    //����һ��������
	//L=CreatList(L); //ͷ�巨
	L = CreatListW(L);
	Show(L);
	getchar();


}

Node* CreatList(LinkList p)
{

	for (int i=0; i < NUM; i++)
	{
		Node *r;   //�½�һ���м�ڵ�
		r = (LinkList)malloc(sizeof(Node));  //�����ڴ�ռ�
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
		Node* p;  //�½�һ���м�ڵ�
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