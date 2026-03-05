#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,s,area;
	printf("请输入三角形的边长a,b,c\n");
	scanf("%f""%f""%f",&a,&b,&c);
	s=(a+b+c)/2;
	area=sqrt((s-a)*(s-b)*(s-c)*s);
	printf("三角形的面积为:\n");
	printf("%f",area);
	return 0;
}