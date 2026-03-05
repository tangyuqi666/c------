#include<stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	while(n!=0){
		n/2;
		if(n%2!=0){
		printf("no");
		}
		n=n/2;
	}
	printf("yes");
	return 0;
}