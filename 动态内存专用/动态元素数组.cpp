#include<stdio.h>
#include<stdlib.h>
int* k(int n){
    int* arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL)
       { printf("申请失败");
        return NULL;}
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    return arr;
}
int main(){
    int len;
    printf("请输入数组长度");
	scanf("%d",&len);
	int* d=k(len);
    if(d!=NULL){
        printf("动态元素数组");
        for(int i=0;i<len;i++){
            printf("%d",d[i]);
        }
        printf("\n");
        free(d);
        d=NULL;//(使指针悬空)
    }
}

