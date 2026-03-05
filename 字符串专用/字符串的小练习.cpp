#include<stdio.h>
void strcopy(char s[],char t[]);
int main(){
	char s[]={"sfdfgksgns"};
	char t[]={"afgerasgsht"};
	strcopy(s,t);
    printf("%s",s);
}
void strcopy(char s[],char t[]){
	int i=0;
	while(t[i]!='\0'){
		s[i]=t[i];
		i++;
	}
}