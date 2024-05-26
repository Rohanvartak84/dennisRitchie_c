#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double custom_atof(const char *str) {
    double result = 0.0;
    double power = 1.0;
    int sign = 1;
    int exponent_sign = 1;
    int exponent = 0;
    int i = 0;

    // Skip leading whitespaces
    while (isspace(str[i]))
        i++;

    // Handle sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Parse integer part
    while (isdigit(str[i])) {
        result = result * 10.0 + (str[i] - '0');
        i++;
    }

    // Parse fractional part
    if (str[i] == '.') {
        i++;
        while (isdigit(str[i])) {
            result = result * 10.0 + (str[i] - '0');
            power *= 10.0;
            i++;
        }
    }

    result = sign * result / power;

    // Handle scientific notation
    if (str[i] == 'e' || str[i] == 'E') {
        i++;
        // Handle exponent sign
        if (str[i] == '-') {
            exponent_sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        // Parse exponent
        while (isdigit(str[i])) {
            exponent = exponent * 10 + (str[i] - '0');
            i++;
        }
        // Apply exponent
        while (exponent > 0) {
            if (exponent_sign == 1) {
                result *= 10.0;
            } else {
                result /= 10.0;
            }
            exponent--;
        }
    }

    return result;
}

int main() {
    char input[50];

    // Read the input string from the user
    printf("Enter a floating-point number: ");
    scanf("%s", input);

    // Convert the input string to a double using custom_atof
    double number = custom_atof(input);

    // Print the converted number
    printf("Converted number: %lf\n", number);

    return 0;
}

