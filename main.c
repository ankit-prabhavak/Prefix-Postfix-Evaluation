#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;  // Stack is initially empty
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 to indicate error
    }
    return stack->arr[stack->top--];
}

// Function to evaluate a postfix expression (supports space-separated characters)
int evaluatePostfix(char* expression) {
    Stack stack;
    initStack(&stack);
    int i = 0;
    int length = strlen(expression);

    while (i < length) {
        char ch = expression[i];

        // Skip whitespace
        if (ch == ' ' || ch == '\t') {
            i++;
            continue;
        }

        if (isdigit(ch)) {
            // Handle multi-digit numbers
            int num = 0;
            while (i < length && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            push(&stack, num);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // If the character is an operator
            if (stack.top < 1) {
                printf("Insufficient operands\n");
                return -1; // Not enough operands to apply the operator
            }
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default: 
                    printf("Unknown operator: %c\n", ch);
                    return -1;
            }

            push(&stack, result);
            i++;
        }
        else {
            printf("Unknown character: %c\n", ch);
            return -1;
        }
    }

    return pop(&stack);  // The final result will be the only element left in the stack
}

// Function to evaluate a prefix expression (supports space-separated characters)
int evaluatePrefix(char* expression) {
    Stack stack;
    initStack(&stack);

    int length = strlen(expression);

    // Traverse the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        char ch = expression[i];

        // Skip whitespace
        if (ch == ' ' || ch == '\t') {
            continue;
        }

        if (isdigit(ch)) {
            // Handle multi-digit numbers
            int num = 0;
            while (i >= 0 && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i--;
            }
            i++;  // Correct the loop counter
            push(&stack, num);
            continue;  // Skip incrementing i as it's already handled in the while loop
        }

        // If the character is an operator
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (stack.top < 1) {
                printf("Insufficient operands\n");
                return -1; // Not enough operands to apply the operator
            }
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
            int result;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default: 
                    printf("Unknown operator: %c\n", ch);
                    return -1;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);  // The final result will be the only element left in the stack
}

// Function to remove newline character if it exists (from fgets)
void removeNewline(char* str) {
    size_t length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

int main() {
    char postfix[MAX], prefix[MAX];

    // Get postfix expression from user (with space-separated characters)
    printf("Enter a postfix expression (e.g., 2 3 * 5 +): ");
    fgets(postfix, sizeof(postfix), stdin);
    removeNewline(postfix);  // Remove newline character if it exists
    
    // Evaluate and print result for postfix expression
    printf("Evaluating postfix expression: %s\n", postfix);
    int postfixResult = evaluatePostfix(postfix);
    if (postfixResult != -1) {
        printf("Result: %d\n", postfixResult);
    }

    // Get prefix expression from user (with space-separated characters)
    printf("Enter a prefix expression (e.g., + * 2 3 + 4 5): ");
    fgets(prefix, sizeof(prefix), stdin);
    removeNewline(prefix);  // Remove newline character if it exists

    // Evaluate and print result for prefix expression
    printf("Evaluating prefix expression: %s\n", prefix);
    int prefixResult = evaluatePrefix(prefix);
    if (prefixResult != -1) {
        printf("Result: %d\n", prefixResult);
    }

    return 0;
}


