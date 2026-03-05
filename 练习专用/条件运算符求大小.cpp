#include<stdio.h>
int main()
{
	int a,b,c,max;
    printf("请输入三个数\n");
	scanf("%d %d %d",&a,&b,&c);
	max=a>b?(a>c?a:b):(b>c?b:c);
	printf("max=%d",max);
	
}