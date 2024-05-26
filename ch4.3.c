#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int mod(int dividend,int divisor);


int main(){
int dividend,divisor, op;
printf("enter 2 numbers\n");
scanf("%d%d",&dividend,&divisor);

op=mod(dividend,divisor);

	printf("%d\n",op);
}
int mod(int dividend,int divisor){
	if(divisor==0){
		printf("number cant be divide by 0");
		return -1;
	}
	int op;
	op = dividend % divisor;
//	if(op>0)
//		op= op+ abs(divisor);
return op;
}
