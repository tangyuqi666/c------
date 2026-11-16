
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;
typedef struct treenode{
	char data;
	struct treenode* lchild;
	struct treenode* rchild;
}treenode;
typedef treenode* bitree;
//前序遍历
typedef struct{//结构体队列(队列里的数组装的元素是
//树中的一个节点
	bitree *data;
	int front;
	int rear;
}Queue;
/*void preorder(bitree t){
	if(t==NULL){
		return ;
	}
	printf("%c",t->data);
	preorder(t->lchild);
	preorder(t->rchild);
}*/
void creattree(bitree *t){//指针的指针（t是)
	char ch;
	ch=str[idx++];
	if(ch=='#'){
		*t=NULL;
	}
	else{
		*t=(bitree)malloc(sizeof(treenode));
		(*t)->data=ch;//用下面的函数不断赋值，这个是用前序的顺序造的树。
		creattree(&(*t)->lchild);
		creattree(&(*t)->rchild);
	}	
}
Queue* initQueue(){
	Queue *q=(Queue*)malloc(sizeof(Queue));
	q->data=(bitree*)malloc(sizeof(bitree)*MAXSIZE);
	q->front=0;
	q->rear=0;
	return q;
}
int isempty(Queue *q){
	if(q->front==q->rear){
	   printf("是空的");
	   return 1;
	}
	else{
		return 0;
	}
}
int equeue(Queue *q,bitree e){
	if((q->rear+1)%MAXSIZE==q->front){
		printf("满了");
		return 0;
	}
	q->data[q->rear]=e;
	q->rear=(q->rear+1)%MAXSIZE;//可以防止溢出
	return 1;
}//e是一个节点
int dequeue(Queue* q,bitree *e){
	if(q->front==q->rear){
		printf("空的");
		return 0;
	}
	*e=q->data[q->front];
	q->front=(q->front+1)%MAXSIZE;
	return 1;
}
int gethead(Queue* q,bitree *e){
	if(q->front==q->rear){
		printf("空的");
		return 0;
	}
	*e=q->data[q->front];
	return 1;
}
int queuesize(Queue* q){
	if(!isempty(q)){
		return q->rear-q->front;
	}
	else{
		return 0;
	}
}
int maxdepth(treenode* root){
	if(root==NULL){
		return 0;
	}
	int depth=0;
	Queue* q=initQueue();
	equeue(q,root);//入队的第一个节点指针，也可以代表这个树
	while(!isempty(q)){
		int count=queuesize(q);
		while(count>0){
			treenode* curr;//对于特定的每一层的一个节点，
			dequeue(q,&curr);//将队列q中的这一层选定的的这个节点去除，用curr这个临时节点来存放
			if(curr->lchild!=NULL){//对临时节点中的左右孩子进行操作，防止改变原来的树的节点。
				equeue(q,curr->lchild);
			}//先入队左孩子
			if(curr->rchild!=NULL){
				equeue(q,curr->rchild);
			}//再入队右孩子
			count--;
		
		}//一个循环走完一层
		depth++;
	}
	return depth;//depth是层数
}

/*void inorder(bitree t){
	if(t==NULL){
		return;
	}
	inorder(t->lchild);
	printf("%c",t->data);
	inorder(t->rchild);
}
void lastorder(bitree t){
	if(t==NULL){
		return;
	}
	lastorder(t->lchild);
	lastorder(t->rchild);
	printf("%c",t->data);
}*/
void freetree(bitree T){
	if(T==NULL){
		return;
	}
	freetree(T->lchild);
	freetree(T->rchild);
	free(T);
}
int main(){
        treenode T;
		bitree Q=&T; 
        creattree(&Q);
       // preorder(Q);
       // printf("\n");
       // inorder(Q);
        // printf("\n");
       // lastorder(Q);
       printf("%d",maxdepth(Q));
       freetree(Q);
}

