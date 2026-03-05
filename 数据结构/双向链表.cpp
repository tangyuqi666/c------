#include<stdio.h>
#include<stdlib.h>
typedef struct doublelinkednode{
	int data;
	struct doublelinkednode *next,*prev;
}node;
node* creatnode(int data){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
node* headnode(){
	node* head=creatnode(0);
	return head;
}
void inserthead(node* l,int data)
{
	node* newnode=creatnode(data);
	newnode->prev=l;
	newnode->next=l->next;
	if(l->next!=NULL){
		l->next->prev=newnode;
	}
	l->next=newnode;
}
void bianli(node* l)
{
	node* p=l->next;
	while(p!=NULL){
		printf("%d",p->data);
		p=p->next;
		
	}
	printf("\n");
}
void freenode(node* l)
{
	node* p=l->next;
	while(p!=NULL){
	node* temp=p->next;	
		free(p);
		p=temp;
	}
	free(l);
	l=NULL;
}

void tailinsert(node* l,int data){
	node* newnode=creatnode(data);
	node* p=l->next;
	if(l->next==NULL){
		l->next=newnode;
		newnode->prev=l;
		return;
	}
	while(p->next!=NULL){
		p=p->next;
	}
	node* tail=p;
	newnode->prev=tail;
	tail->next=newnode;

}
void posinsert(node* l,int data,int pos){
	node* newnode=creatnode(data);
	node* p=l;
	for(int i=0;i<=pos-1;i++){
		p=p->next;
		if(p==NULL){
			return;
		}
	}
	newnode->prev=p;
	newnode->next=p->next;
	p->next=newnode;
}
void deletenode(node* l,int pos){
		node* p=l;
	for(int i=0;i<pos;i++){
		if(p->next==NULL){
			return;
		}
		p=p->next;
	}
	node* q=p->next;
	p->next=q->next;
	if(q->next!=NULL){
	q->next->prev=p;}
	free(q);
}
int main(){
        node* l=headnode();
        inserthead(l,3);
        tailinsert(l,4);
        posinsert(l,9,1);
        deletenode(l,2);
        bianli(l);
        freenode(l);
}