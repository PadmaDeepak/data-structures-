#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

char stack[MAX];
int top = -1;

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to push an item onto the stack
void push(char item) {
    if (top < MAX - 1) {
        stack[++top] = item;
    }
}

// Function to pop an item from the stack
char pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return '\0'; // Return null character if stack is empty
}

// Valid Parentheses Function
bool isValid(char* s) {
    // Reset top for each new string check
    top = -1; 
    
    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];
        
        if (current == '(' || current == '{' || current == '[') {
            push(current);
        } else {
            if (isEmpty()) {
                return false; // No matching open bracket
            }
            char topChar = pop();
            if ((current == ')' && topChar != '(') ||
                (current == '}' && topChar != '{') ||
                (current == ']' && topChar != '[')) {
                return false; // Mismatched brackets
            }
        }
    }
    
    return isEmpty(); // Valid if no unmatched open brackets left
}

