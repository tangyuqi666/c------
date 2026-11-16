
#include<stdio.h>
#include<stdlib.h>
char str[]="ABDH##I##EJ##CF##G##";
int idx=0;
typedef struct Threadnode{
	char data;
	struct Threadnode* lchild;
	struct Threadnode* rchild;
	int ltag;
	int rtag;
}Threadnode;
typedef Threadnode* Threadtree;
//前序遍历
/*void preorder(bitree t){
	if(t==NULL){
		return ;
	}
	printf("%c",t->data);
	preorder(t->lchild);
	preorder(t->rchild);
}*/
Threadtree prev=NULL;
//造树
void creattree(Threadtree *t){
	char ch;
	ch=str[idx++];
	if(ch=='#'){
		*t=NULL;
	}
	else{
		*t=(Threadtree)malloc(sizeof(Threadnode));
		(*t)->data=ch;
		(*t)->ltag=0;
	    (*t)->rtag=0;
		creattree(&(*t)->lchild);
	//	if((*t)->lchild!=NULL){
	//		(*t)->ltag=0;
	//	}
		creattree(&(*t)->rchild);
	//	if((*t)->rchild!=NULL){
	//		(*t)->rtag=0;
	//}
	
}}
void threading(Threadtree t){
	if(t!=NULL){
		threading(t->lchild);
		if(t->lchild==NULL){
			t->ltag=1;
			t->lchild=prev;
		}
	if(prev!=NULL&&prev->rchild==NULL){
		prev->rtag=1;
		prev->rchild=t;
	}
	prev=t;
	threading(t->rchild);
	}
}
void inorderThreading(Threadtree *head,Threadtree t){
      *head=(Threadtree)malloc(sizeof(Threadnode));
      (*head)->ltag=0;
      (*head)->rtag=1;
      (*head)->rchild=(*head);
      //头节点指向本身，使有用
      if(t==NULL){
      	(*head)->lchild=*head;
	  }
	  else{
	  	(*head)->lchild=t;
	  	//头节点的lchild指向树的根
	  	prev=*head;
	  	//prev是用来记录上一次访问的那个节点
		  threading(t);
		  //针对每一个节点加前驱和后继
		  prev->rchild=*head;
		  //最后一个节点访问后在prev中记录，并由prev
		  //进行将最后一个节点的rchid指向头节点
		  prev->rtag=1;
		(*head)->rchild=prev;
		//头节点右孩子指向最后一个节点
	  }
}
void inorder(Threadtree t){
	Threadtree curr;//当前的
	curr=t->lchild;
	while(curr!=t){//curr不等于头节点
		while(curr->ltag==0){
			curr=curr->lchild;
		}
		printf("%c",curr->data);
		while(curr->rtag==1&&curr->rchild!=t){
			curr=curr->rchild;
			printf("%c",curr->data);
		}
	
		curr = curr->rchild;
	}

}
/*void lastorder(bitree t){
	if(t==NULL){
		return;
	}
	lastorder(t->lchild);
	lastorder(t->rchild);
	printf("%c",t->data);
}*/
int main(){
        Threadtree head;
		Threadtree T;
        creattree(&T);
        //preorder(Q);
        printf("\n");
        inorderThreading(&head,T);
        inorder(head);
         printf("\n");
      //  lastorder(Q);
        return 0;
	
}



