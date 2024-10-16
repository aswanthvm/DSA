#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100 // maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int x) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        top++;
        stack[top] = x;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        int x = stack[top];
        top--;
        return x;
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfixExp) {
    int i = 0;
    char item;
    int op1, op2, result;

    // Loop through each character of the postfix expression
    while ((item = postfixExp[i]) != '\0') {
        // If the item is an operand (digit), push it to the stack
        if (isdigit(item)) {
            push(item - '0'); // Convert char to int by subtracting '0'
        }
        // If the item is an operator, pop two operands from the stack, perform the operation, and push the result back
        else if (item == '+' || item == '-' || item == '*' || item == '/') {
            op2 = pop(); // Pop the second operand
            op1 = pop(); // Pop the first operand

            switch (item) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default:
                    printf("Invalid operator encountered\n");
                    exit(1);
            }
            push(result); // Push the result back to the stack
        } else {
            printf("Invalid character in expression\n");
            exit(1);
        }
        i++; // Move to the next character in the postfix expression
    }

    // The final result will be the only element left in the stack
    return pop();
}

// Main function
int main() {
    char postfixExp[] = "231*+9-";  // Example postfix expression: (2 + 3 * 1) - 9
    printf("Postfix Evaluation Result: %d\n", evaluatePostfix(postfixExp));
    return 0;
}
