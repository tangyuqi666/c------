#include<stdio.h>
int main(){
	int arr[6]={4,5,6,9,1,2};
//	int (*p)[3];
//	p=arr;
	for(int i=0;i<5;i++){
		int k=i,temp;
		for(int j=i+1;j<6;j++){
		if(arr[j]>arr[k]){
			k=j;
		}}
		temp=arr[i];
		arr[i]=arr[k];
		arr[k]=temp;
	}
	for(int i=0;i<6;i++){
		printf("%d",arr[i]);
	}
	return 0;
}
