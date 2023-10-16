#include <stdio.h>
#include <stdlib.h>

#define Max 5

void push(int st[], int* top, int val) {
    if (*top == Max - 1) {
        printf("Stack overflow !!\n");
    }
    else {
        st[++(*top)] = val;
        printf("Pushed %d\n", val);
    }
}

int pop(int st[], int* top) {
    int val;
    if (*top == -1) {
        printf("Stack underflow !!\n");
        val = -1;
    }
    else {
        val = st[(*top)--];
    }
    return val;
}

int getTop(int st[], int top) {
    if (top == -1) {
        return -1;
    }
    else {
        return st[top];
    }
}

void display(int st[], int top) {
    if (top == -1) {
        printf("Nothing to display !!\n");
    }
    else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", st[i]);
        }
        printf("\n");
    }
}

int main() {
    int stack[Max];
    int top = -1;
    push(stack, &top, 1);
    push(stack, &top, 2);
    push(stack, &top, 3);
    push(stack, &top, 4);
    push(stack, &top, 5);
    push(stack, &top, 6); // This will cause a stack overflow.
    display(stack, top);

    return 0;
}