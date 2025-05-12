#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char elem) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = elem;
}

char pop() {
    if (top == -1) {
        return '\0'; // Empty stack
    }
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int checkBalancedParentheses(char* expr) {
    int i = 0;
    char ch;

    while ((ch = expr[i++]) != '\0') {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char openBracket = pop();
            if (!isMatchingPair(openBracket, ch)) {
                return 0; // Not balanced
            }
        }
    }

    return top == -1; // Stack should be empty if balanced
}

int main() {
    char expr[50];

    printf("Enter an Expression: ");
    scanf("%s", expr);

    if (checkBalancedParentheses(expr)) {
        printf("Parentheses are Balanced\n");
    } else {
        printf("Parentheses are NOT Balanced\n");
    }

    return 0;
}
