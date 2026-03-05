
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;
node* initialnode(){
	node* head=(node*)malloc(sizeof(node));
	if(head==NULL){
		printf("申请空间失败");
	}
	head->data=0;
	head->next=NULL; 
	return head;
}
node* creatnode(int data){
	node* newnode=(node*)malloc(sizeof(node));
		if(newnode==NULL){
		printf("申请空间失败");
	}
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
void headinsert(node* l,int data){
	node* newnode=creatnode(data);
	newnode->next=l->next;
	l->next=newnode;
}
node* tracktail(node*l){
	node* p=l;
	while(p->next!=NULL){
	p=p->next;
	}
	return p;
}
node* tailinsert(node* tail,int data){
	node* newtail=creatnode(data);
	tail->next=newtail;
	return newtail;
}
void bianli(node* l){
	node* p=l->next;
	if(p==NULL){
		return;
	}
	node* fast=p;
	node* slow=p;
	int hascycle=0;
    while(fast!=NULL&&fast->next!=NULL){
    	fast=fast->next->next;
    	slow=slow->next;
    	if(fast==slow){
    		hascycle=1;
    		break;
		}
	}
	if(hascycle){
		node* start=p;
		do{
			printf("%d",p->data);
			p=p->next;
		}while(p!=start);
	}
	else{
	while(p!=NULL){
		printf("%d",p->data);
		p=p->next;
	}}
}
void freenode(node* l){
	node* p=l;
	while(p!=NULL){
		p=p->next;
		free(p);
		free(l);
		l=NULL;
	}
}
void seek(node* l,int k)//查找倒数第n个数的快慢双数组使用
{
	node* fast=l->next;
	node* slow=l->next;
	for(int i=0;i<k;i++){
		fast=fast->next;
	}
	while(fast!=NULL){
		fast=fast->next;
		slow=slow->next;
	}
	printf("倒数第%d个节点数值为：%d\n",k,slow->data);
}
node*  invertnode(node* l){//反转链表
	node *first =NULL;
	node *second=l->next;
	node* third;
	while(second!=NULL){
		third=second->next;
		second->next=first;
		first=second;
		second=third;
	}
	node* head2=initialnode();
	head2->next=first;
	return head2;
}
int delmiddlenode(node* l){//快慢指针用来删除中间的节点
	node* fast=l->next;
	node* slow=l;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	node* q=slow->next;
	slow->next=q->next;
	free(q);
    return 1;
}

int main(){
	node* l=initialnode();
/*	headinsert(l,1);
	headinsert(l,2);
	headinsert(l,3);
	headinsert(l,4);
	headinsert(l,5);
	headinsert(l,6);
	headinsert(l,7);
	headinsert(l,8);
	headinsert(l,9);*/
   node* tail=tracktail(l);
   tail=tailinsert(tail,1);
   tail=tailinsert(tail,2);
   tail=tailinsert(tail,3);
   node* three=tail;
    tail=tailinsert(tail,4);
    tail=tailinsert(tail,5);
    tail=tailinsert(tail,6);
    tail=tailinsert(tail,7);
    tail=tailinsert(tail,8);
    tail=tailinsert(tail,9);
    tail->next=three;
	bianli(l);
	printf("\n");
//	bianli(k);	
	delmiddlenode(l);
	printf("\n");
	bianli(l);
	seek(l,1);
	bianli(invertnode(l));
	freenode(l);

}