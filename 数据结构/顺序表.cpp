#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
typedef struct shunxubiao{
	int* date;
	int length;
}s;
void initelist(s* l){
	l->length=0;
}
int add(s* l,int q){
	if(l->length>max){
		printf("顺序表已满");
		return 0;
	}
	l->date[l->length]=q;
	l->length++;
	return 1;
}
void bianli(s* l){
	for(int i=0;i<l->length;i++)
{
	printf("%d\t",l->date[i]);
}printf("\n");}
int insert(s* l,int start,int w){
	if(l->length>=max){
		printf("满了");
		return 0;
	}
	if(start<=l->length){
		for(int i=l->length;i>=start-1;i--){
			l->date[i+1]=l->date[i];
		}
		l->date[start-1]=w;
		l->length++;
	}return 1;
}
int deletelist(s* l,int start,int* e){
	if(l->length>=max){
		printf("满了");
		return 0;
	}
	*e=l->date[start-1];//把起点的地址赋值给e的地址。
	if(start<=l->length){
		for(int i=start;i<=l->length;i++){
			l->date[i-1]=l->date[i];
		}l->length--;
		return 1;
	}
}
int find(s* l,int q){
	for(int i=0;i<l->length;i++){
		if(l->date[i]==q){
			return i+1;
		}
	}
	return 0;
}
s* initlist(){//结构体指针内存动态分配初始化
	s* l=(s*)malloc(sizeof(s));
	l->date=(int*)malloc(sizeof(int)*max);
	l->length=0;
	return l;
}
void destroylist(s* l){
	if(l->date!=NULL){
		free(l->date);
		l->date=NULL;
	}
	l->length=0;
}
int main(){
//	s list;
//	initelist(&list);
    s* list=initlist();
	printf("占用长度%d",list->length);
	printf("字节长度%zu\n",sizeof(list->date));
    add(list,9);
//	printf("%d\n",k);
	add(list,76);
		add(list,75);	
		add(list,71);
	bianli(list);
	insert(list,2,99);
	bianli(list);
	int deldate;
	deletelist(list,3,&deldate);
	printf("%d\n",deldate);
	bianli(list);
	int o=find(list,99);
	printf("%d",o);
	destroylist(list);
}
	
