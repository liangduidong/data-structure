#include<stdio.h>
#include<stdlib.h>

void del_x(LinkList* L, int x){
	LNode *p=L,*pre;
	while(p!=NULL){
		if(p->data==x){
			pre->next=p->next;
			free(p);
			p=pre;
		}
		pre=p;
		p=p->next;
	}
}
