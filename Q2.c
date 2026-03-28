#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    char expr[MAX];
    int i;

    printf("Enter an expression: ");
    scanf("%s", expr);

    for (i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

         if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                printf("Not Balanced Expression\n");
                return 0;
            }

            char popped = pop();
            
            if (!isMatchingPair(popped, ch)) {
                printf("Not Balanced Expression\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("Balanced Expression\n");
    else
        printf("Not Balanced Expression\n");

    return 0;
}
