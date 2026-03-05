#include<stdio.h>
#include<math.h>
int main()
{
	
	float a,b,c,s,area,l;
	printf("请输入三角形的边长a,b,c\n");
	scanf("%f""%f""%f",&a,&b,&c);
	while((a+b<=c)||(b+c<=a)||(a+c<=b)){
		printf("它们不能组成三角形，请重新输入\n");
		scanf("%f""%f""%f",&a,&b,&c);
	}
	s=(a+b+c)/2;
	area=sqrt((s-a)*(s-b)*(s-c)*s);
	printf("三角形的面积为:\n");
	printf("%f",area);
	return 0;
}