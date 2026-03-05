#include<stdio.h>
int main(){
	int num1;
	int num2,k=0,g;
	printf("请录入两个整数\n");
	scanf("%d %d",&num1,&num2);
	if(num1>=num2){
		g=num1;
		num1=num2;
		num2=g;

	for(num1;num1<=num2;num1++){
		if((num1%6==0)&&(num1%8==0)){
			//printf("%d",num1);
			printf("\n");
			k++;
		//	printf("既能被6整除，又能被8整除的数字有%d个",k);
	}
	}
}
	printf("既能被6整除，又能被8整除的数字有%d个",k);
	return 0;
}