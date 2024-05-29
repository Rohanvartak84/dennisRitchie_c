/*
 *task : Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers. 
 *Author : Rohan Vartak
 *Created:
 */

/** REQUIRED HEADER FILE */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/** MACRO DEFINITION */
#define MAX_STACK_SIZE 100

/** GLOBAL VARIABLES */
char stack[MAX_STACK_SIZE];
int top = -1;

/** FUNCTION PROTOTYPE */
int isOperator(char);
int precedence(char);
int pop(void);
void push(int);
int evaluate(char *);


/** MAIN PROGRAM */
int main() {
	char expr[1024]; // Buffer for the expression

	printf("Enter the expression: ");
	fgets(expr, sizeof(expr), stdin); // Read expression from user

	// Remove trailing newline (if present)
	expr[strcspn(expr, "\n")] = '\0';

	int result = evaluate(expr);
	printf("Result: %d\n", result);

	return 0;
}/* end main() */

/** 
  isOperator():
 */ 
int isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch== '%');
}/* end isOperator */


/* 
   precedence():This function determines the precedence level of an operator. Higher precedence operators are evaluated first.
 */
int precedence(char ch) {
	switch (ch) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		default:
			return -1; // Not an operator
	}
}/* end precedence */

/*
   pop(): This function removes and returns the top element from the operand stack. It also handles stack underflow errors.
 */
int pop() {
	if (top == -1) {
		fprintf(stderr, "Stack underflow\n");
		exit(1);
	}
	return stack[top--];
}/* end pop() */

/* 
   push():his function pushes an operand (integer) onto the operand stack.It also handles stack overflow errors.
 */
void push(int val) {
	if (top == MAX_STACK_SIZE - 1) {
		fprintf(stderr, "Stack overflow\n");
		exit(1);
	}
	stack[++top] = val;
}/* end push() */

/* 
   evaluate(): This function evaluates the mathematical expression entered by the user. It uses a  shunting-yard algorithm to convert the infix expression to postfix and then evaluates the postfix expression using the stack.
 */
int evaluate(char *expr) {
	int len = strlen(expr);
	char *token = strtok(expr, " "); // Handle spaces

	while (token != NULL) {
		if (isdigit(*token)) {
			push(atoi(token));
		} else if (isOperator(*token)) {
			int val2 = pop();
			int val1 = pop();
			switch (*token) {
				case '+':
					push(val1 + val2);
					break;
				case '-':
					push(val1 - val2);
					break;
				case '*':
					push(val1 * val2);
					break;
				case '/':
					if (val2 == 0) {
						printf("Division by zero\n");
						exit(1);
					}
					push(val1 / val2);
					break;
				case '%':
					if (val2 != 0.0)
					{
						push(val1 % val2);
					}
					else
					{
						printf("Division by zero\n");
					}
					break;

				default:
					printf("Invalid operator\n");
					exit(1);
			}
		} else {
			printf("Invalid token: %s\n", token);
			exit(1);
		}
		token = strtok(NULL, " "); // Handle multiple spaces
	}

	if (top != 0) {
		printf("Invalid expression: Extra operands\n");
		exit(1);
	}

	return stack[top]; // The final result is at the top of the stack
}/* end evaluate */

