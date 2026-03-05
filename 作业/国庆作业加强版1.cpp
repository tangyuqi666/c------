#include<stdio.h>
#include<math.h>
int main()
{
	int g=1;
	while(g==1){
	
	float a,b,c,s,area,l;
	printf("请输入三角形的边长a,b,c\n");
	scanf("%f""%f""%f",&a,&b,&c);
	if((a+b<=c)||(b+c<=a)||(a+c<=b)){
		printf("它们不能组成三角形，请输入1重新输入");
		
	}
	
	else{
	s=(a+b+c)/2;
	area=sqrt((s-a)*(s-b)*(s-c)*s);
	printf("三角形的面积为:\n");
	printf("%f",area);
}
    scanf("%d",&g);
	}
	return 0;
}