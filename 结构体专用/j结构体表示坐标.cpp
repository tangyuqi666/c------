#include<stdio.h>
int main()
{
	struct Point{double x,y;};
	struct Point p1,p2;
	printf("请输入一个坐标\n");
	scanf("x=%lf" "y=%lf",&p1.x,&p2.y);
	//getchar();
	struct Point p3,p4;
	printf("请输入一个坐标\n");
	scanf("x=%lf" "y=%lf",&p3.x,&p4.y);
	struct Point p5,p6;
	p5.x=(p1.x+p3.x)/2;
	p6.y=(p2.y+p4.y)/2;
	printf("它们的中点坐标为:\n");
	printf("%lf\n""%lf\n",p5.x,p6.y);
}