#include<stdio.h>
#include<stdlib.h>
int main()
{
	int select,num1,num2;
	double x,y;
	char ch_in,ch_out;
	int leave1=0;
	int leave2=0;
	int num3=0;
	float score,Ave_score,Sum_score,Max_score,Min_score;
	do{
		printf("*********************\n");
	printf("*     小小计算机    *\n");
	printf("* 1   算数运算        *\n");
	printf("* 2   逻辑运算      *\n");
	printf("* 3    转换运算         *\n");
	printf("* 4    成绩统计        *\n");
	printf("* 5    退出计算机     *\n");
	printf("***********************\n");
	printf("请选择：");
	scanf("%d",&select);
	switch(select){
		case 1:
	printf("*********************\n");
	printf("* 1    加法         *\n");
	printf("* 2    减法         *\n");
	printf("* 3    乘法         *\n");
	printf("* 4    除法         *\n");
	printf("* 5    返回上一级菜单 *\n");
	printf("***********************\n");
	leave2=0;
	do
	{
		printf("请选择：");
		scanf("%d",&select);
//		printf("请输入两个数");
	//	scanf("%lf%lf",&x,&y);
		switch(select){
			case 1:
				printf("请输入两个数");
		scanf("%lf%lf",&x,&y);
			printf("加法  %.6f+%.6f=%.6f\n",x,y,x+y);	
			break;
			case 2:
				printf("请输入两个数");
		scanf("%lf%lf",&x,&y);
			printf("减法  %.6f-%.6f=%.6f\n",x,y,x-y);
			break;
			case 3:
				printf("请输入两个数");
		scanf("%lf%lf",&x,&y);
			printf("乘法  %.6f*%.6f=%.6f\n",x,y,x*y);
			break;
			case 4:
				printf("请输入两个数");
		scanf("%lf%lf",&x,&y);
			printf("除法  %.6f/%.6f=%.6f\n",x,y,x/y);
			break;
			case 5:
				leave2=1;
				break;
			default:
				printf("输入有误");
				break;
		}
/*		if((select>=1)&&(select<=4)){
			printf("请输入两个数");
	scanf("%lf%lf",&x,&y);
	printf("\n");
		}
		else if(select==5){
			leave2=1;
		}
		else {
			printf("输入有误\n");}
	}*/}while(!leave2);
	 system("cls");
	break;
	   case 2:
	printf("*************");
	printf(" 1 逻辑运算 ");
//	pritnf(" 2 逻辑与运算");
//	pritnf(" 3 逻辑非运算");
    printf("4 返回上级菜单");
	printf("*************");
	leave2=0;
	do
	{
		printf("请选择");
		scanf("%d",&select);
		switch(select){
			case 1:
		int num1, num2;
    	char op;
    	printf("请输入两个整数和一个逻辑运算符（&&、||、! ），格式如：a op b 或!a ：");
    	if (scanf("%d %c %d", &num1, &op, &num2) == 3) {
        int result;
        if (op == '&') {
            result = num1 && num2;
            printf("%d && %d = %d\n", num1, num2, result);
        } else if (op == '|') {
            result = num1 || num2;
            printf("%d || %d = %d\n", num1, num2, result);
        } else {
            printf("不支持的运算符\n");
        }
    } else if (scanf("!%d", &num1) == 1) {
        int result =!num1;
        printf("!%d = %d\n", num1, result);
        break;
    } else {
        printf("输入格式错误会");}
        break;
            case 4:
        leave2=1;
        break;
			default:
				printf("输入有误\n");
				break;
			}	
	}while(!leave2);
	system("cls");
	break;
	case 3:
	printf("请输一个小写字母");
	getchar();
	ch_in=getchar();
	ch_out=ch_in-32;
	printf("%c对应的大写字母=%c\n",ch_in,ch_out);
	printf("%c对应的数字为%d\n",ch_in,ch_in);
	printf("请输一个大写字母");
	getchar();
	scanf("%c",&ch_in);
	ch_out=ch_in+32;
	printf("%c对应的小写字母=%c\n",ch_in,ch_out);
	printf("%c对应的数字为%d\n",ch_in,ch_in);
//	while(!leave2);
//	system("cls");
	break;
	case 4:
		int num;
	float score,max,min,ave,total;
	printf("请输入学生成绩，以最后一个成绩输入负数以结束输入\n");
	scanf("%f",&score);
	for(num=0;score>=0;num++){
		if(score>100){
			printf("输入有误，请重新输入");
			scanf("%f",&score);
			continue;
	    }
	    if(num==0){
	    	max=score;
	    	min=score;
		}
		else{
			if(score>max)
			{max=score;}
			if(score<min)
			{min=score;}
			}
		total+=score;
		scanf("%f",&score);
	}
		if(num){
			ave=total/num;
			printf("共输入%d个成绩，最大值为%.2f,最小值为%.2f,总和为%.2f,平均值为%.2f\n",num,max,min,total,ave);
				}
	while(!leave2);
	system("cls");
	break;
	case 5:
		leave1=1;
		break;
	default:
		system("cls");
}
	}while(!leave1);
	printf("程序结束!\n");
	return 0;
}