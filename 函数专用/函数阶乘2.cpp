#include<stdio.h>
int funl(int);
int fun2(int,int);
int main(){
	int i,x,y;
	scanf("%d",&i);
	funl(i);
	printf("%d",funl(i));
	printf("\n");
	scanf("%d%d",&x,&y);
	fun2(x,y);
	printf("%d",fun2(x,y));
}





int fun2(int i,int k){
	int q;
	q=funl(i)/(funl(k)*funl(i-k));
	return q;
}















int funl(int i){
	int j;
	if(i==1){
		j=1;
	}
	else if(i<=0){
		printf("错误");
	}
	else if(i==0)
	j=0;
	else{
	j=i*funl(i-1);
	}
	return j;
}