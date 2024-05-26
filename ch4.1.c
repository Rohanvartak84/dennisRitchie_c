/*task: Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none. 
* Author: Rohan Vartak
* Created: 1 May 2024 
*/

/** REQUIRED HEADER FILE */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/** FUNCTION PROTOTYPE */
int strIndex(char sS[],char sT[]);

/* MAIN PROGRAM */
/*
*main(): In main we are 2 string. One string is for searching the sub-string from the another string. If sub-string found printing its index. 
*/
int main(){
char *sS;
char *sT;
int iOp;
sS=(char*)malloc(sizeof(char)*50);
sT=(char*)malloc(sizeof(char)*50);

printf("enter value in s\n");
scanf("%[^\n]%*c",sS);

printf("enter sub-string to search in s\n");
scanf("%[^\n]%*c",sT);

iOp=strIndex(sS,sT);

if(iOp!= -1)
	printf("sub-string found at index = %d\n",iOp+1);
else
	printf("sub-string not found\n");
}

/*
* strIndex(): This function returns the position of the rightmost occurrence of t in s, or -1 if there is none.
*/
int strIndex(char sS[],char sT[]){
	int iI;
	int iJ;
	int iK;
	for(iI=0;sS[iI]!='\0';iI++){
		for(iJ=iI,iK=0;sT[iK]!='\0' && sS[iJ]==sT[iK];iJ++,iK++);
		if(iK>0 && sT[iK]=='\0')
			return iI;
		}
	return -1;
}/* end strIndex() */











