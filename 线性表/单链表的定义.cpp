#include<stdio.h>
#include<stdlib.h>

// ������Ķ��� 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

// 1.������ĳ�ʼ��
bool InitList(LinkList *L){
	L=(LNode*)malloc(sizeof(LNode));  //��ͷ��� 
	L->next=Null;
	return true;
}

// 2.���
int Length(LinkList *L){
	int len=0;
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	return len;
} 

// 3.����ڵ����
bool ListInsert(LinkList *L,int i,int value){
	LNode *p=L;
	int j=0;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL) return false;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=value;
	s->next=p->next;
	p->next=s;
	return true;
} 

// 4.ɾ���ڵ����
bool ListDelete(LinkList &L,int i,int &e){
	LNode *p=L;
	int j=0;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL||p->next==NULL) return false;
	LNode* q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return true;
} 

// 5.����ͷ�巨����������
LinkList List_HeadInsert(LinkList *L){
	LNode *s;int x;
	L=(LNode*)malloc(sizeof(LNode));
	L->next=NULL;
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
} 

// 6.����β�巨����������
Linklist List_TailInsert(LinkList* L){
	LNode *s,*p;
    int x;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    p=L;
    scanf("%d",&x);
    while(x!=9999){
    	s=(LNode*)malloc(sizeof(LNode));
    	s->data=x;
    	p->next=s;
    	s->next=NULL;
    	p=s;
    	scanf("%d",&x);
	}
	return L;
} 
