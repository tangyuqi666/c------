#include<stdio.h>
void geek(void* p1,void* p2,int len);
int main(){
	int a=10,b=20;
	int* p1=&a;
	int* p2=&b;
	//printf("%d",*p1);
//	printf("%d",*p2);
	geek(&a,&b,4);
	printf("转换后a=%d,b=%d",a,b);
}
void geek(void* p1,void* p2,int len){
	char* i=(char *)p1;
	char* q=(char *)p2;
	for(int j=0;j<len;j++){
		int temp=*i;
		*i=*q;
		*q=temp;
		i++;
		q++;
	}
	
}





