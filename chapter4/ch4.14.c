/*
* task : Define a macro swap(t,x,y) that interchanges two arguments of type t.
* Author : Rohan Vartak
* Created : 2 May 2024
*/

/** FUNCTION PROTOTYPE */
#include<stdio.h>

/** MACRO DEFINITION */
#define swap(t,x,y) { t temp;temp=x;x=y;y=temp;} /* swapping two numbers */

/** MAIN PROGRAM */
int main(){
int cA;
int cB;

printf("enter value for a and b\n");
scanf("%d %d",&cA,&cB);

printf("a= %d b= %d\n",cA,cB);

swap(char,cA,cB);

printf("a= %d b= %d\n",cA,cB);
}
