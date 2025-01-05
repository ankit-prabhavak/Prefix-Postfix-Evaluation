# Postfix and Prefix Expression Evaluator

This C program evaluates **Postfix** and **Prefix** expressions using a **stack** data structure. The program supports basic arithmetic operators: `+`, `-`, `*`, and `/`.

## Features

- Evaluates **Postfix** expressions (also known as Reverse Polish Notation).
- Evaluates **Prefix** expressions (also known as Polish Notation).
- Handles multi-digit numbers.
- Provides error handling for insufficient operands and unknown characters.
- Displays the result for both types of expressions.

## Files

- `postfix_prefix_evaluator.c`: The main source code file.
  
## Program Overview

The program takes two space-separated expressions from the user:
1. A **Postfix expression** (e.g., `2 3 * 5 +`).
2. A **Prefix expression** (e.g., `+ * 2 3 + 4 5`).

It evaluates both expressions and prints the result for each.

### Stack Data Structure

The stack used in this program is implemented using an array of size `100` (constant `MAX`) with the following operations:
- **Push**: Adds an element to the stack.
- **Pop**: Removes an element from the stack.

### Postfix Evaluation

In postfix notation, operators come after operands. The algorithm follows these steps:
1. Traverse the expression from left to right.
2. Push operands onto the stack.
3. When an operator is encountered, pop two operands from the stack, perform the operation, and push the result back onto the stack.
4. The final result will be the only element left in the stack.

### Prefix Evaluation

In prefix notation, operators come before operands. The algorithm follows these steps:
1. Traverse the expression from right to left.
2. Push operands onto the stack.
3. When an operator is encountered, pop two operands from the stack, perform the operation, and push the result back onto the stack.
4. The final result will be the only element left in the stack.

### Error Handling

The program includes error checks for the following scenarios:
- **Stack Overflow**: If more elements are pushed onto the stack than it can hold.
- **Stack Underflow**: If there are insufficient operands for an operator.
- **Unknown Characters**: If an invalid character is encountered in the expression.
- **Insufficient Operands**: If there are not enough operands for an operator.

## Functions

### `initStack(Stack* stack)`
Initializes the stack by setting the top index to `-1`.

### `push(Stack* stack, int value)`
Pushes the given value onto the stack.

### `pop(Stack* stack)`
Pops and returns the top element from the stack. If the stack is empty, it returns `-1` and prints "Stack Underflow".

### `evaluatePostfix(char* expression)`
Evaluates a postfix expression using a stack. It handles multi-digit numbers and arithmetic operators (`+`, `-`, `*`, `/`).

### `evaluatePrefix(char* expression)`
Evaluates a prefix expression using a stack. It handles multi-digit numbers and arithmetic operators (`+`, `-`, `*`, `/`).

### `removeNewline(char* str)`
Removes the newline character at the end of a string if it exists. This function is used to clean up input strings from `fgets()`.

### `main()`
The main function where the user is prompted to enter a postfix and prefix expression. It calls the respective evaluation functions and prints the results.

## Usage

1. Compile the program using a C compiler, such as `gcc`:
   ```sh
   gcc postfix_prefix_evaluator.c -o evaluator
