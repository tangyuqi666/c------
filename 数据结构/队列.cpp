#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
//一边进一边出横向排列，出的一边叫队头，进的一边叫队尾
//可以分为顺序结构，链表结构，队头叫front,尾部叫rear
//总的来讲，先进的先出
typedef struct queue{
	int data[MAXSIZE];
	int front;
	int rear;
}queue;/*队列的意思*/
void initqueue(queue* Q){
     Q->front=0;
	Q->rear=0;
}//初始化
int isempty(queue* Q){
     if(Q->front==Q->rear){
     	printf("空的");
     	return 1;
	 }
     else{
     	return 0;
	 }
}//判断队列是否为空
int queuefull(queue* Q){
	if(Q->front>0){
		int step=Q->front;
		for(int i=Q->front;i<=Q->rear;i++){
			Q->front=0;
			Q->rear=Q->rear-step;
			return 1;
		}
		
	}
	else {
			printf("满了");
		}
}//用于去判断队列是否满了
int dequeue(queue* Q){
	if(Q->front==Q->rear){
     	printf("空的\n");
     	return 0;
	 }
	 int e=Q->data[Q->front];
	 Q->front++;
	 return e;
}//出队
int equeue(queue* Q,int e){
	if(Q->rear>=MAXSIZE){
		if(!queuefull(Q)){
			return 0;
		}
	}
	Q->data[Q->rear]=e;
	Q->rear++;
	return 1;
}//在没满的情况下从队尾入队

int gethead(queue *Q,int *e){
	if(Q->front==Q->rear){
		printf("满了");
		return 0;
	}
	*e=Q->data[Q->front];
	return 1;
}//获取队头数据
int main(){
	    queue Q;
       initqueue(&Q);
       equeue(&Q,10);
       equeue(&Q,20);
        equeue(&Q,30);
        equeue(&Q,40);
       equeue(&Q,50);
       printf("%d",dequeue(&Q));
      printf("%d",dequeue(&Q));
      printf("%d",dequeue(&Q));
       int e;
       gethead(&Q,&e);
       printf("%d\n",e);
       return 0;
       
}