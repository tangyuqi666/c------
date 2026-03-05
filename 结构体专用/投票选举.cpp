#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
struct person
   {
   	char name[20];
   	int count;
};
int main(){
	int i;
	struct person p[3]={"Li",0,"zhang",0,"Fun",0};
	srand(time(NULL));
	printf("请输入投票人数");
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int g=rand()%3;
		if(g==0){
			p[0].count++;
		}
		else if(g==1){
			p[1].count++;
		}
		else if(g==2){
			p[2].count++;
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3-i-1;j++){
			int temp=0;
			if(p[j].count<p[j+1].count){
				temp=p[j].count;
			p[j].count=p[j+1].count;
				p[j+1].count=temp;
				char tempname[20];
				strcpy(tempname,p[j].name);
				strcpy(p[j].name,p[j+1].name);
				strcpy(p[j+1].name,tempname);
			}}}
	for(int i=0;i<3;i++){
		printf("%s\t",p[i].name);
		printf("%d\n",p[i].count);
		
		}
	printf("%s",p[0].name[1]);
}
