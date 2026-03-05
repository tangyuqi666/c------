#include<stdio.h>
int main()
{
	double x,y;
	char ch_in,ch_out;
	printf("*********************\n");
	printf("*     小小计算机    *\n");
	printf("* 1    加法         *\n");
	printf("* 2    减法         *\n");
	printf("* 3    乘法         *\n");
	printf("* 4    除法         *\n");
	printf("* 5    字母转换     *\n");
	printf("***********************\n");
	printf("请输入两个数");
	scanf("%lf%lf",&x,&y);
	printf("加法  %.6f+%.6f=%.6f\n",x,y,x+y);
	printf("减法  %.6f-%.6f=%.6f\n",x,y,x-y);
	printf("乘法  %.6f*%.6f=%.6f\n",x,y,x*y);
	printf("除法  %.6f/%.6f=%.6f\n",x,y,x/y);
	printf("\n");
	printf("请输一个小写字母");
	getchar();
	ch_in=getchar();
	ch_out=ch_in-32;
	printf("%c对应的大写字母=%c\n",ch_in,ch_out);
	printf("请输一个大写字母");
	getchar();
	scanf("%c",ch_in);
	ch_out=ch_in+32;
	printf("%c对应的小写字母=%c\n",ch_in,ch_out);
	return 0;
}
