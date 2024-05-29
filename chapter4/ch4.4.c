/* task :Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack
Author: Rohan Vartak
Created: 2 May 2024
*/

/** REQUIRED HEADER FILE */ 
#include<stdio.h>
#include<stdlib.h>

/** MACRO DEFINITION */
#define MAX 50

/** GLOBAL VARIBALES */
int sS[MAX];
int iTop=-1;

/** FUNCTION PROTOTYPE */
void push();
void pop();
void display();
void clear();
void topTwoElements();
void duplicate();
void swap();

/** MAIN PROGRAM */
/*
*
*/
void main(){

	int iOp;
	while(1){
		printf("******************* Stack Manu *******************\n");
		printf("option: 1)push\t2)pop\t3)display\t4)clear\n\t5)print top two elements\t6)swap\t7)duplicate\n");
		scanf("%d",&iOp);

		switch(iOp){

			case 1:push();
			       break;
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:clear();
			       break;
			case 5:topTwoElements();
			       break;
			case 6:swap();
			       break;
			case 7:duplicate();
			       break;
			default: printf("enter correct option\n");
		}
	}
}/* end main() */

/*
* push(): push one element into array
*/
void push(){
	int iV;
	if(iTop==MAX-1){
		printf("stack is full\n");
	}
	printf("enter value\n");
	scanf("%d",&iV);
	iTop=iTop+1;
	sS[iTop]=iV;
}/* end push() */

/*
*pop(): pop one element from array.
*/
void pop(){
	if(iTop==-1){
		printf("stack is empty\n");
	}
	printf("digit removed: %d\n",sS[iTop]);
	sS[iTop--];

}/* end pop() */

/*
*display(): display content of array
*/
void display(){
	int iI;
	if(iTop == -1){
		printf("array is empty\n");
		return;
		}
	for(iI=0;iI<=iTop;iI++){
		printf("%d ",sS[iI]);
	}
	printf("\n");
}/* end display() */

/*
*clear(): delete all element from array
*/
void clear(){
	iTop=-1;
	printf("all data is cleared\n");
}/* end clear() */

/*
* topTwoElement(): print top 2 elements in array
*/
void topTwoElements(){
	if(iTop == -1){
		printf("array is empty\n");
		return;
		}
	printf("top element: %d\n",sS[iTop]);

	printf("second top element: %d\n",sS[iTop-1]);
}/* end topTwoElement */

/*
* swap(): swap top two element 
*/
void swap(){
	int iN=sS[iTop];
	sS[iTop]=sS[iTop-1];
	sS[iTop-1]=iN;
}/* end swap() */

/*
* duplicate: duplicate top element and store it in same array and increment the size of array by 1 
*/
void duplicate(){
	sS[iTop+1]=sS[iTop];
	iTop=iTop+1;
}/* end duplicate */

