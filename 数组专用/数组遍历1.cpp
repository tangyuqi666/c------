#include<stdio.h>
void printfarr(int arr[],int len){
	for(int i=0;i<len;i++){
		printf("%d\n",arr[i]);
	}
}

int main(){
	int arr[]{5,6,4,8,9,};
	int len=sizeof(arr)/sizeof(arr[0]);
	printfarr(arr,len);
//	printf("%d\n",arr[i]);
    char akk[15]="hello word";
  //  int len1=sizeof(akk)/sizeof(akk[0]);
  for(int i=0;i<len;i++){
    printf("%c",akk[i]);}
    return 0;
}