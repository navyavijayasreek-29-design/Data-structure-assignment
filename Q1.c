#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[100];
    int i;

    printf("Enter string: ");
    scanf("%s", str);

    for(i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    printf("Reversed string: ");
    for(i = 0; i < strlen(str); i++) {
        printf("%c", pop());
    }

    return 0;
}
