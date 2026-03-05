#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num,q=0;
	scanf("%d",&num);
	int w=num;
	while(num!=0){
		int g=num%10;
		num=num/10;
		q=g+10*q;
		}
	printf("%d",q);
	if(q==w){
		printf("是");
	}
	else {
		printf("不是");
	}
	
	
	
	
}