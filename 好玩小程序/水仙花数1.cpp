#include <stdio.h>
int main()
{
	 int num, num1, num2, num3;
	 printf("请输入一个三位整数：");
	 scanf("%d", &num);
	 if((num>=100)&&(num<1000))
	 {
	 	num3=num/100;
	 	num2=(num%100)/10;
	 	num1=num%10;
	 	if((num1*num1 + num2*num2 + num3*num3)==num)
	 	{
	 		printf("%d是水仙花数！\n", num );
		 }
		 while((num1*num1 + num2*num2 + num3*num3)!=num)
		 {
		 	printf("%d不是水花仙数\n", num);
		 	printf("请重新输入");
		 	scanf("%d",&num);
		 }
	 }
	 else
	 {
	 	printf("%d不是水花仙数，水花仙数应该是三位整数\n", num);
	 }
	// printf("按1重新输入，其余数退出");

	 return 0;}