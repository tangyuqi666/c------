
#include<stdio.h>
#include<stdlib.h>
struct student{
	char id[20];
	char name[20];
	float score[30];
};
float avg(struct student s){
	float sum=0;
	for(int i=0;i<3;i++){
		sum+=s.score[i];
	}
	return sum/3;
}
int main(){
	int n;
	printf("输入学生数量");
	scanf("%d",&n);
	struct student students[n];
		for(int i=0;i<n;i++){
			printf("输入%d个学生的信息（学号 姓名 语文成绩 数学成绩 英语成绩）\n",i+1);
			scanf("%s%s%f%f%f",students[i].id,students[i].name,&students[i].score[0],&students[i].score[1],&students[i].score[2]);
		}
	for(int i=0;i<n;i++){
		float av=avg(students[i]);
		printf("%s(%s)的平均成绩为%f",students[i].name,students[i].id,av);
	}
return 0;
}