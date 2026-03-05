#include<stdio.h>
#include<string.h>
int main(){
	 struct message{
		  char number[1000];
		  char mail[1000];
		  
	};
	
	typedef struct student {
		  char name[1000];
		  int age;
		  int height;
		  struct message mes;
	}s;
	
	s stu;

	strcpy(stu.name,"aaa");
	strcpy(stu.mes.number,"15616164613");
	strcpy(stu.mes.mail,"156161643");
	scanf("%s %d %d",stu.name,&stu.age,&stu.height);
	printf("%s %d %d\t",stu.name,stu.age,stu.height);
	printf("%s %s",stu.mes.number,stu.mes.mail);
	return 0;
}