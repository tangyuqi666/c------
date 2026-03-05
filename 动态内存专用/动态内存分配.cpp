#include<stdio.h>
#include<stdlib.h>
int* p(int a,int b);
int main(){
	printf("请输入");
	int* arr=NULL;
	int len=0;
	int k=4,temp;
	arr=(int*)malloc(k*sizeof(int));
	if(arr==NULL){
				printf("申请失败");
				return 1;}
	while(1){
		scanf("%d",&temp);
		if(temp==-1){
			break;
		}
		if(len>k){
			k*=2;
			arr=(int*)realloc(arr,k*sizeof(int));//内存扩展
			if(arr==NULL){
				printf("申请失败");
				return 1;
			}
		}
		arr[len]=temp;
		len++;
	}
	printf("长度%d",len);
	free(arr);
	arr=NULL;
	return 0;
}
	
