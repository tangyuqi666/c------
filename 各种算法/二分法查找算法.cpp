
#include<stdio.h>
#include<stdlib.h>
int binaryserach(int a[],int q,int len){
	int left=0;
	int right=len-1;
    while(left<=right){
    	int mid=(left+right)/2;
    	if(a[mid]==q){
    		return mid;
		}
	else if(a[mid]<q){
			left=mid+1;
		}
		else {
			right=mid-1;
		}
	}
}
int main(){
	int a[10]={0};
	for(int i=0;i<10;i++){
		a[i]=i;}
	for(int i=0;i<10;i++){
			printf("%d",a[i]);
		}
int w=binaryserach(a,3,10);
printf("%d",w+1);
}