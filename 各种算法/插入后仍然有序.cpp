
#include<stdio.h>
#include<stdlib.h>
void insert(int arr[],int n,int num,int newarr[]){
	int i,j;
	int pos=n;
	for(i=0;i<n;i++){
	if(num<arr[i]){
		pos=i;
		break;
	}
}
for(i=0;i<pos;i++){
	newarr[i]=arr[i];
}
newarr[pos]=num;
for(j=pos;j<n;j++){
	newarr[j+1]=arr[j];
}
}
int main(){
int arr[]={2,5,8,9,10};
int n=sizeof(arr)/sizeof(int);
int num;
int newarr[100];
printf("要插入的数");
scanf("%d",&num);
insert(arr,n,num,newarr);
printf("插入后");
for(int i=0;i<n+1;i++){
	printf("%d",newarr[i]);
	printf("\n");
}
}