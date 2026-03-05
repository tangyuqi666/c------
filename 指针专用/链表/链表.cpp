#include<stdio.h>
#include<stdlib.h>
	typedef struct ListNode{
		int date;
		struct ListNode* next;
	}ListNode;
ListNode* creatNode(int date){
		ListNode* newNode=(ListNode*)malloc(sizeof(ListNode));
	if(newNode==NULL){
		printf("申请失败");
		return NULL;
	}
	newNode->date=date;
	newNode->next=NULL;
	return newNode;}//创造链表首节
void interTail(ListNode* *head,int date){//插入以头指针的指针为向导
	ListNode* newNode=creatNode(date);//函数复用
	if(newNode==NULL){
		printf("申请失败");
	return ;}
	if(*head==NULL){//如果头节点为空，则创造一个头节点+
	
		*head=newNode;
		return;
	}
	ListNode* temp=*head;
	while(temp->next!=NULL){
		temp=temp->next;//不等于空时，疯狂指针下指
	}
	temp->next=newNode;
}//尾插法
void traverseList(ListNode* head){
	ListNode* temp=head;
	printf("链表内容");
	while(temp!=NULL){
		printf("%d",temp->date);
		temp=temp->next;
	}printf("\n");
}
void headinsert(ListNode** head,int data){
	ListNode* newNode=creatNode(data);
	if(*head==NULL){
		*head=newNode;
	}
	newNode->next=*head;
	*head=newNode;	
}
void posinsert(ListNode**head,int pos,int data){
	ListNode* newNode=creatNode(data);
	if(*head==NULL){
		*head=newNode;
	}
	ListNode* temp=*head;
	for(int i=0;i<pos-1;i++){
		temp=temp->next;
	}
	newNode->next=temp->next;
	temp->next=newNode;
}
void freeList(ListNode** head){
	ListNode* temp;
	while(*head!=NULL){
		temp=*head;
		*head=(*head)->next;
		free(temp);
		temp=NULL;
	}
}
int main(){
	//ListNode* head=NULL;
	ListNode* head=creatNode(3);
	interTail(&head,10);
	interTail(&head,20);
	interTail(&head,30);
	headinsert(&head,99);
	posinsert(&head,4,85);
	traverseList(head);
	freeList(&head);
	head=NULL;
	return 0;}