#include <stdio.h>
#include<stdlib.h>
int main()
{
    int p=1;
    while(p==1){
           printf("猜数字\n");
           float q;
           printf("请输入一个三位数字\n");
           scanf("%f",&q);
           if(q>=500){
               printf("该数字小于500，请按1开始重新输入");
               }
           else if ((200<=q&&q<=305)||(307<=q&&q<=500)){
               printf("该数在300到310之间，请按enter再试一次。");
               int m;
               scanf("%d",&m);
               switch(m){
               	case 300:
               	case 301:
               	case 302:
               	case 303:
               	case 304:
               	case 305:
               		printf("有误，请按1重新输入");
               		system("cls");
               		break;
               	case 306:
               		printf("正确");
               		break;
               	case 307:
               	case 308:
               	case 309:
               		printf("有误，请重新输入");
               		break;
				   default:
				   printf("有误，有误请按1重新输入");
				   break;
				   }
               }
            else if(q<=200){
                printf("不对，按1重新输入");}
            else if(q=306){
            	printf("答案正确，按1重新开始，按2结束游戏");
			}
        scanf("%d",&p);
        
        }
    return 0; 
}