#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char x;

    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        // If the token is an operand, add it to the output
        if (isalnum(token)) {
            postfix[j++] = token;
        } 
        // If the token is '(', push it to the stack
        else if (token == '(') {
            push(token);
        } 
        // If the token is ')', pop and add to output from the stack until '(' is found
        else if (token == ')') {
            while (top != -1 && (x = pop()) != '(') {
                postfix[j++] = x;
            }
        } 
        // If the token is an operator
        else if (isOperator(token)) {
            while (top != -1 && precedence(peek()) >= precedence(token)) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
