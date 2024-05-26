/* 
*task : Write a recursive version of the function reverse(s), which reverses the string s in place.
*Author : Rohan Vartak
*Created : 2 May 2024
*/

/** REQUIRED HEADER FILE */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/** FUNCTION PROTOTYPE */
void reverse(char sS[]);

/** MAIN PROGRAM */
/*
* main(): passing string to reverse function and printing it reverse on screen 
*/
void main(){
	char *sS;

	sS=(char*)malloc(sizeof(char)*50);

	printf("enter a string\n");
	scanf("%[^\n]%*c",sS);

	printf("before: %s\n",sS);

	reverse(sS);

	printf("after: %s\n",sS);

	free(sS);
}/* end main() */

/*
* reverse(): reverse the string using recursion
*/
void reverse(char sS[]){
	static int iI=0;
	static int iJ=0;

	if(sS[iI]!='\0')
	{
		char cC=sS[iI++];
		reverse(sS);
		sS[iJ++]=cC;

	}
}/* end reverse() */
