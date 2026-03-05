#include<stdio.h>
int main(){
    printf("请输入百分制成绩（-1结束输入）\n");
    int a;
    while(1){
        scanf("%d",&a);
        if(a == -1){
            break;
        }
        if(a < 0 || a > 100){
            printf("成绩输入错误，请输入0-100之间的整数\n");
            continue;
        }
        switch(a/10){
            case 10:
            case 9:
                printf("成绩等级A\n");
                break;
            case 8:
                printf("成绩等级B\n");
                break;
            case 7:
                printf("成绩等级C\n");
                break;
            case 6:
                printf("成绩等级D\n");
                break;
            default:
                printf("成绩等级E\n");
                break;
        }
    }
    return 0;
}
