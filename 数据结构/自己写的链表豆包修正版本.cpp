#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;
node* initialnode(){
	node* head=(node*)malloc(sizeof(node));
	if(head==NULL) printf("申请空间失败");
	head->data=0;
	head->next=NULL;
	return head;
}
node* creatnode(int data){
	node* newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL) printf("申请空间失败");
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
void headinsert(node* l,int data){
	node* newnode=creatnode(data);
	newnode->next=l->next;
	l->next=newnode;
}
node* tracktail(node* l){
	node* p=l;
	while(p->next!=NULL) p=p->next;
	return p;
}
node* tailinsert(node* tail,int data){
	node* newtail=creatnode(data);
	tail->next=newtail;
	return newtail;
}

// 环检测：返回环入口节点；无环返回 NULL
node* findCycle(node* head){
	node* fast=head, *slow=head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			node* p=head;
			while(p!=slow){ p=p->next; slow=slow->next; }
			return p;
		}
	}
	return NULL;
}

void bianli(node* l){
	node* p=l->next;
	if(p==NULL) return;
	node* entry=findCycle(p);
	if(entry!=NULL){              // 有环：从环入口打印一圈，不死循环
		node* q=entry;
		do{ printf("%d ", q->data); q=q->next; }while(q!=entry);
		printf("(环)\n");
	}else{                        // 无环：正常打印
		while(p!=NULL){ printf("%d ", p->data); p=p->next; }
		printf("\n");
	}
}

void freenode(node* l){           // 修正：先存下一个，再释放当前
	node* p=l;
	while(p!=NULL){
		node* t=p->next;
		free(p);
		p=t;
	}
}

void seek(node* l,int k){
	node* fast=l->next, *slow=l->next;
	for(int i=0;i<k;i++){
		if(fast==NULL){ printf("k超出链表长度\n"); return; }
		fast=fast->next;
	}
	while(fast!=NULL){ fast=fast->next; slow=slow->next; }
	printf("倒数第%d个节点数值为：%d\n",k,slow->data);
}

node* invertnode(node* l){
	node *first=NULL, *second=l->next, *third;
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

int delmiddlenode(node* l){
	if(l->next==NULL || l->next->next==NULL) return 0;
	node* fast=l->next, *slow=l;
	while(fast!=NULL && fast->next!=NULL){
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
	node* tail=tracktail(l);
	tail=tailinsert(tail,1);
	tail=tailinsert(tail,2);
	tail=tailinsert(tail,3);
	tail=tailinsert(tail,4);
	tail=tailinsert(tail,5);
	tail=tailinsert(tail,6);
	tail=tailinsert(tail,7);
	tail=tailinsert(tail,8);
	tail=tailinsert(tail,9);

	// 注意：去掉造环后，下面这些操作才能在无环链表上正确执行。
	// 想单独测"环检测"：把节点3指针存下来，在9后接回 three，
	// 然后只调用 bianli，不要再调 delmid/seek/invert（会死循环）。

	bianli(l);        // 1 2 3 4 5 6 7 8 9
	delmiddlenode(l); // 删中间节点5
	bianli(l);        // 1 2 3 4 6 7 8 9
	seek(l,1);        // 倒数第1个=9
	node* r=invertnode(l);
	bianli(r);        // 9 8 7 6 4 3 2 1
	freenode(r);      // 释放反转链（含新头head2和全部数据节点）
	free(l);          // 释放原来的空头节点
	return 0;
}
