#define maxsize 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
	int* data;
	int top;
}stack;
typedef enum contenttype
{
	left_pare,right_pare,
	add,sub,mul,DIV,mod,
	EOS,num
}contenttype;
char expr[]="x/(i-j)*y";
stack* initstack(){
	stack* s=(stack*)malloc(sizeof(stack));
	s->data=(int*)malloc(sizeof(int)*maxsize);
	s->top=-1;
	return s;
}
int isempty(stack* s){
	if(s->top==-1){
		printf("空的");
		return 1;
	}
	else {
	return 0;
	}
}
int push(stack* s,int e){
	if(s->top>=maxsize){
		printf("满了");
	}
	s->top++;
	s->data[s->top]=e;
	return 1;
}
int pop(stack* s,int *e){
	if(s->top==-1){
		printf("空了");
	}
	*e=s->data[s->top];
	s->top--;
	return 1;
}
int gettop(stack* s,int*e){
		if(s->top==-1){
		printf("空了");
	}
	*e=s->data[s->top];
	return 1;
}
contenttype gettoken(char *symble,int *index)
{
	*symble=expr[*index];
	*index=*index+1;
	switch(*symble){
		case '(':
			return left_pare;
		case ')':
			return right_pare;
		case '+':
			return add;
		case '-':
			return sub;
		case '*':
			return mul;
		case '/':
			return DIV;
		case '%':
			return mod;
		case '\0':
			return EOS;
		default:
		return num;
	}
}
int print_token(contenttype token){
	switch(token){
		case add:
			printf("+");
			break;
		case sub:
			printf("-");
			break;
		case mul:
			printf("*");
			break;
		case DIV:
			printf("/");
			break;
		case mod:
			printf("%");
			break;
		case EOS:
			printf("\0");
			break;
		default:
			return 0;
	}
	return 1;
}
char* postfix(stack* s){
	static char newexpr[100];
	int i=0;
	int in_stack[]={0,19,12,12,13,13,13,0
	};
	int out_stack[]={20,19,12,12,13,13,13,0
	};
	contenttype token;
	int index=0;
	char symble;
	int e;
	push(s,EOS);
	token=gettoken(&symble,&index);
	while(token!=EOS){
		if(token==num){
			printf("%c",symble);
			newexpr[i]=symble;
		     i++;
		}
		else if(token==right_pare){
			while(s->data[s->top]!=left_pare){
				pop(s,&e);
				print_token((contenttype)e);
			newexpr[i]=e;
		     i++;
				//输出
			}//栈顶不是左括号就一直弹出
			pop(s,&e);//再把左括号弹出但不输出
		}
		else{
			while(in_stack[s->data[s->top]]>=out_stack[token])
		{//这个用来并比较栈内外优先级,如果里面大就弹出并打印
				pop(s,&e);
			print_token((contenttype)e);
			newexpr[i]=e;
		     i++;
			}
		}
		push(s,token);//这是默认如果外面大，就直接压栈
		token=gettoken(&symble,&index);//重复进行就行
	}
	newexpr[i] = '\0';
	return newexpr;
}
void calculate(stack* s,char* expr){
	int i=0;
	int e1;
	int e2;
	int e;
	char symble;
	while(expr[i]!='\0'){
		symble=expr[i];
		i++;
		switch(symble){
		case '+':{pop(s,&e1);
			pop(s,&e2);
			int q=e2+e1;
			push(s,q);
			break;
		}
			
		case '-':{
			pop(s,&e1);
			pop(s,&e2);
			int q=e2-e1;
			push(s,q);
			break;
		}
			
		case '*':{pop(s,&e1);
			pop(s,&e2);
			int q=e2*e1;
			push(s,q);
			break;
		}
			
		case '/':{pop(s,&e1);
			pop(s,&e2);
			int q=e2/e1;
			push(s,q);
			break;
		}
			
		case '%':{
				pop(s,&e1);
			pop(s,&e2);
			int q=e2%e1;
			push(s,q);
			break;
		}
		
		default:
	         push(s,symble-'0');
	}}
	pop(s,&e);
	printf("结果是%d",e);

}
int main(int argc,char const *argv[]){
       stack* s=initstack();
       printf("%s\n",expr);
	   //postfix(s);
	   char* newexpr=postfix(s);
	   int k=strlen(newexpr);
	   for(int i=0;i<k;i++){
	   	printf("%c",newexpr[i]);
	   }
	   printf("\n");
	   stack* s2=initstack();
	   calculate(s2,newexpr);
	   free(s->data);
	   free(s);
	   return 0;
}

