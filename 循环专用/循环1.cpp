#include<stdio.h>
int main()
{
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
	return 0;
}