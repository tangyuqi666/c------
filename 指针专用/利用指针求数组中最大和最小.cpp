#include<stdio.h>
#include<stdlib.h>
void getmaxandmin(int arr[],int len,int* max,int* min);
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int len=sizeof(arr)/sizeof(int);
	int max=arr[0];
	int min=arr[0];
    getmaxandmin(arr,len,&max,&min);
	printf("最小值为%d\n",max);
	printf("最小值为%d\n",min);
}
void getmaxandmin(int arr[],int len,int* max,int* min){
	 *max=arr[0];
	 *min=arr[0];
	 for(int i=0;i<=len-1;i++){
	 if(arr[i]>*max){
	 *max=arr[i];	 }
	 if(arr[i]<*min){
	 
	 *min=arr[i];}
}}