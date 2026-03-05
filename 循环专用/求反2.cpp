#include<stdio.h>
int main(){
	int num,k=0;
	scanf("%d",&num);
	while(num!=0){
		int g=num%10;
		num=num/10;
		k=k*10+g;
	}
	printf("%d",k);
	}
	