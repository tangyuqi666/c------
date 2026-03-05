#include<stdio.h>
long long nul(int n){
		long double p;
		if(n>1){
			p=n*nul(n-1);}
		else{
			p=1;}
			return(p);
		}
int main(){
	int m;
	long long k;
	
	while(m>=0){
		if(m<0){break;}
		scanf("%d",&m);
	k=nul(m);
	printf("%d的阶乘为:%lld\n",m,k);}
	return 0;
}