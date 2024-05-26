#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Include the math library

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '%':
                op2 = pop();
                push(pop() - op2 * (int)(pop() / op2));
                break;
            case 's': // Handle sin
                push(sin(pop()));
                break;
            case 'e': // Handle exp
                push(exp(pop()));
                break;
            case 'p': // Handle pow
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '\n':
                printf("Result: %.2f\n", pop());
                break;
            default:
                printf("Error: Unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

