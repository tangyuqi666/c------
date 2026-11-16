
#include<stdio.h>
#include<stdlib.h>
char str[]="ABDH#K###E##CFI###G#J##";//
int idx;
typedef struct treenode{
	char data;
	struct treenode* lchild;
	struct treenode* rchild;
}treenode;
typedef treenode* bitree;
//前序遍历
void preorder(bitree t){
	if(t==NULL){
		return ;
	}
	printf("%c",t->data);
	preorder(t->lchild);
	preorder(t->rchild);
}
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
void inorder(bitree t){
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
}
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
        preorder(Q);
        printf("\n");
        inorder(Q);
         printf("\n");
        lastorder(Q);
       freetree(Q);
}

