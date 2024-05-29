/* task : Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.
*Author: Rohan Vartak
*Created : 2 May 2024
*/

/** REQUIRED HEADER FILE */
#include<stdio.h>
#include<stdlib.h>

/** FUNCTION PROTOTYPE */
void itoa(int iN,char sS[]);

/** MAIN PROGRAM */
/*
* main(): passing interger value and an char array to itoa function and printing converted value on screen
*/
int main(){
	int iN; 
	char *sS;

	printf("enter number\n");
	scanf("%d",&iN);

	sS=(char*)malloc(sizeof(char)*50);

	itoa(iN,sS);

	printf("integer into string = %s\n",sS);

	free(sS);
}/* end main() */

/*
* itoa(): convert integer to ASCII using recursion
*/
void itoa(int iN,char sS[]){

	static int iI=0;
	if(iN){
		if(iN<0){
			iI=0;
			sS[iI++]='-';	
			iN=iN*-1;
		}

		int iD=iN%10;
		iN=iN/10;

		itoa(iN,sS);

		sS[iI++]=iD+'0';

		sS[iI]='\0';
	}
}/* end itoa() */
