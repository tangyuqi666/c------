
#include<stdio.h>
#include<stdlib.h>
int compare(char*s1,char*s2){
	while(*s1!='/0'&&*s2!='/0'&&*s1==*s2){
		s1++;
		s2++;
	}
	return *s1-*s2;
}
int main(){
	char a[100];
	char b[100];
	scanf("%s",a);
	scanf("%s",b);
	int k=compare(a,b);
	if(k<0){
		printf("%s<%s",a,b);
	}
	else if(k==0){
		printf("%s=%s",a,b);
	}
	else {
		printf("%s>%s",a,b);
	}
	
}