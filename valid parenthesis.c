#include <stdio.h>
#include<string.h>
void push(int st[], int* top, int size, int val) {
    if (*top == size) return;
    else {
        st[++(*top)] = val;
    }
}
void pop(int st[], int* top) {
    if (*top == -1) return;
    else {
        (*top)--;
    }
}
int getTop(int st[], int top) {
    if (top == -1) return -1;
    else return st[top];
}
int isEmpty(int top) {
    if (top == -1) return 1;
    else return 0;
}
int isValidParentheses(char str[]) {
    int stack[100];
    int top = -1;
    int i;
    int size = strlen(str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            push(stack, &top, size, 1);
        else if (str[i] == '[')
            push(stack, &top, size, 2);
        else if (str[i] == '{')
            push(stack, &top, size, 3);
        else {
            if (isEmpty(top)) {
                return 0;
            }
            else {
                if (str[i] == ')' && getTop(stack, top) != 1 || str[i] == '}' && getTop(stack, top) != 2 || str[i] == ']' && getTop(stack, top) != 3) {
                    return 0;
                }
            }
            pop(stack, &top);
        }
    }

    return isEmpty(top);
}

int main() {
    char str[10000];

    printf("Enter a string with parentheses: ");
    gets(str);

    if (isValidParentheses(str)) {
        printf("Valid parentheses!\n");
    }
    else {
        printf("Invalid parentheses!\n");
    }

    return 0;
}
