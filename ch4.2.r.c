/* task: Extend atof to handle scientific notation of the form 
 	 123.45e-6 
	 where a floating-point number may be followed by e or E and an optionally signed exponent. 
* Author: Rohan Vartak
* Created: 1 May 2024
*/

/** REQUIRED HEADER FILE */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

/** FUNCTION PROTOTYPE */
int myAtof(char *sS);

/** MAIN PROGRAM */
/*
*main(): in main we are passing float string to myAtof function. After converting printing it on screen.
*/
void main(){
	char *sStr;
	double dOp;
	sStr=malloc(sizeof(char)*50);
	printf("enter floating point number\n");
	scanf("%[^\n]%*c",sStr);
	dOp=myAtof(sStr);
	printf("converted number: %lf\n",dOp);
}/* end main() */

/*
* myAtof(): extended version of ACSII to float 
*/
int myAtof(char *sS){
	double dVal=0.0;
	double dPow=1.0;
	int iI=0;
	int iSign=1;
	int iExpsign=1;
	int iExp=0;

	/* spacing white space */
	for(iI=0;isspace(sS[iI]);iI++);	
	
	/* Handling sign */
	iSign= (sS[iI] == '-')?-1:1;
	if(sS[iI]=='+' || sS[iI]=='-')
		iI++;

	/* converting character into decimal before decimal point*/
	for(dVal=0.0;isdigit(sS[iI]);iI++)
		dVal=dVal*10.0+(sS[iI]-'0');

	/* skipping decimal point */
	if(sS[iI]=='.')
		iI++;

	/*converting character into decimal after decimal pointer*/
	for(dPow=1.0;isdigit(sS[iI]);iI++){
		dVal=dVal*10.0+(sS[iI]-'0');
		dPow=dPow*10.0;
	}
	dVal=iSign*dVal/dPow;
	

	/* skipping exponent */
	if(sS[iI]=='e' || sS[iI]=='E'){
		iI++;

	iExpsign=(sS[iI]=='-')?-1:1;

	/* Handling sign */
	if(sS[iI]=='-' || sS[iI]=='+')
		iI++;
	/* handling exponent part */
	for(iExp=0;isdigit(sS[iI]);iI++)
		iExp=iExp*10+(sS[iI]-'0');

	if(iExpsign==1)
		while(iExp-- > 0)
			dVal=dVal*10.0;
	
	else
		while(iExp-- > 0)
			dVal=dVal/10.0;
	
}
	return dVal; 

}/* end myAtof() */


	









