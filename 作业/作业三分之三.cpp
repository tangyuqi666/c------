#include <stdio.h>
int main()
{
    int x, y;
    while(1){
    printf("请输入x的值：");
    scanf("%d", &x);
    if (x < 1)
    {
        y = x;
        printf("y=%d\n", y);
    }
    else if (x >= 1 && x < 10)
    {
        y = 2 * x - 1;
        printf("y=%d\n",y);
    }
    else if (x >= 10)
    {
        y = 3 * x - 11;
        printf("y=%d\n", y);
    }
    else
    {
        printf("输入无效，请输入整数\n");
	}}
    return 0;
}
