#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50

int stack[SIZE];
int top = -1;

void push(int elem) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = elem;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char* postfix) {
    int i = 0, op1, op2;
    char* token = strtok(postfix, " "); // Tokenize the input by spaces

    while (token != NULL) {
        if (isdigit(token[0])) { // If the token is an operand
            push(atoi(token)); // Convert string to integer and push
        } else { // If the token is an operator
            op2 = pop();
            op1 = pop();
            switch (token[0]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': 
                    if (op2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(op1 / op2);
                    break;
                default:
                    printf("Invalid operator: %c\n", token[0]);
                    exit(1);
            }
        }
        token = strtok(NULL, " "); // Move to the next token
    }

    return pop(); // The final result is at the top of the stack
}

int main() {
    char postfix[SIZE];

    printf("Enter a Postfix Expression (space-separated): ");
    fgets(postfix, SIZE, stdin); 

    // Remove trailing newline character from fgets
    postfix[strcspn(postfix, "\n")] = '\0';

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
