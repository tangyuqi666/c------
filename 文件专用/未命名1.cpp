#include<stdio.h>
int main(){
	FILE* file=fopen("C:\\Users\\tyq\\Desktop\\a.txt","r");
	char arr[1024];
	int n=fread(arr,1,1024,file);
	if(n!=0){
		printf("%s",arr);
	}
	while((n=fread(arr,1,1024,file))!=0){
		printf("%s",arr);
	}
//	printf("%c",c);
	fclose(file);
}