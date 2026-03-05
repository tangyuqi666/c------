#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	struct spot{
		char name[100];
		int count;
	};
    struct spot arr[4]={
    	{"A",0},{"B",0},{"C",0},{"D",0}};
    	int max;
    	srand(time(NULL));
    	for(int j=0;j<80;j++){
    int	k=rand()%4;
    	//	printf("%d\n",k);
    		arr[k].count++;
		 }
		 max=arr[0].count;
		for(int i=0;i<4;i++){
			struct spot jj=arr[i];
    	if(jj.count>max)
    	max=jj.count;
	
		}	printf("%d\n",max);
				for(int i=0;i<4;i++){
			struct spot jj=arr[i];
    	if(jj.count==max)
		printf("%s %d\n",jj.name,jj.count);
		}
		
    	
    	for(int i=0;i<4;i++){
    		struct spot temp=arr[i];
    		printf("%s %d\n",temp.name,temp.count);
		}
}