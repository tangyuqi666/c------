#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,q=0,w;
/*	for(i=1;i<=9;i++){
		for(j=1;j<=i;j++){
			printf("%d*%d=%-3d",i,j,i*j);
		}
		printf("\n");*/
	for(i=2;i<=200;i++)
	{
		w=1;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				w=0;
				break;
			}
		}
		if(w==1)
		{
			printf("%d\t",i);
			q++;
			if(q%5==0)
				putchar('\n');
		}
	}
	return 0;
}