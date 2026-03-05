#include<stdio.h>
/*int sum(int q,int w){
		int s;
		s=q+w;
		return s;
	                }
int Max(int q,int w){
	return(q>w?q:w);
                    }*/
void DisplayTri(int n){
	int i;
	for(i=1;i<=2*n-1;i++)
	printf("*");
	printf("\n");    }
int main()
{
	int i,n;
	printf("请输入三角形高度:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{DisplayTri(i);}
	return 0;
}