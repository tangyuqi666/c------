#include<stdio.h>
int* qoo(int p[],int len);
int xiangjia(int q,int w);
int xiangjian(int q,int w);
int main(){
	int arr[4]={4,5,6,9};
	int len=sizeof(arr)/sizeof(int);
	int* p=qoo(arr,len);
	printf("%d\n",*p);
int (*j[2])(int,int)={xiangjia,xiangjian};
	printf("%d\n",j[0](6,9));
	
	}
int* qoo(int p[],int len){
	for(int i;i<len;i++){
		p[i]*=10;
	}
	return p;
}
int xiangjia(int q,int w){
	return q+w;
}
int xiangjian(int q,int w){
	return q-w;
}