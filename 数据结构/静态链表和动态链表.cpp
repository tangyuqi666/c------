#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
node* initelist(){
  node* head=(node*)malloc(sizeof(node));
  head->data=0;
  head->next=NULL;
  return head;
}
void inserthead(node* l,int q){//l永远作为头节点
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=q;
	newnode->next=l->next;
	l->next=newnode;
}
void bianli(node* l){
	node* p=l->next;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}printf("\n");//新写p是为了不改变节点的指针
}
//找到末尾节点
node* gtail(node* l){
	 node* p=l;
	 while(p->next!=NULL){
	 	p=p->next;
	 }
	 return p;
}
//尾插法
node* inserttail(node* tail,int q){
	node* p=(node*)malloc(sizeof(node));
	p->data=q;
	tail->next=p;//尾巴
	p->next=NULL;
	return p;
}
//指定位置插入
 int insertnode(node* l,int pos,int e){
 	node* p=l;//先遍历一遍
 	int i=0;
 	while(i<pos-1){//我们最终点要在指定位置的前一个插入，因此减一
 		p=p->next;
 		i++;
 		if(p==NULL){
 			return 0;
		 }
	 }
	 node* q=(node*)malloc(sizeof(node));
	 q->data=e;
	 q->next=p->next;
	 p->next=q;
	 return 1;
 }
 //删除节点
int deletenode(node* l,int pos){
	//要删除节点的前一个p
	node* p=l;
	int i=0;
	//遍历
	while(i<pos-1){
		p=p->next;
		i++;
		if(p==NULL){
		printf("要删除的位置错误");
			return 0;
		}
	}
	if(p->next==NULL){
		printf("要删除的位置错误");
	}
	node* q=p->next;//p->next为需要删除的节点
	//让要删除的节点的前一个指向需要删除节点的下一个
	p->next=q->next;//直接跳过q,然后把q释放了直接
	free(q);
	q=NULL;//释放删除的节点的空间
	return 1;
}
void freenode(node* l){
	node* p=l;
	while(p->next!=NULL){
		p=p->next;
		free(p);
	}
}
int main(){
	node* list=initelist();
	inserthead(list,10);
	inserthead(list,20);
	bianli(list);
	node* tail=gtail(list);
	tail=inserttail(tail,10);
		tail=inserttail(tail,20);
		bianli(list);
	insertnode(list,2,15);
	bianli(list);
	int k=deletenode(list,2);
	printf("%d\n",k);
	bianli(list);
	freenode(list);
	return 0;
}