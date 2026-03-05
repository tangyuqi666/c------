#include<stdio.h>
int main(){
	int i=1;
	q:
	printf("看看看看%d\n",i);
	i++;
	if(i==15){
		goto b;
	}
goto q;
	b:
		printf("sb");
}