#include <stdio.h>

#define MAX_SIZE 100

void push(int stack[], int* top, int value) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    (*top)++;
    stack[*top] = value;
}

int pop(int stack[], int* top) {
    if (*top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    int value = stack[*top];
    (*top)--;
    return value;
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[MAX_SIZE];
    int top = -1;

    int temp, val;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &temp);
        switch (temp) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(stack, &top, val);
            break;
        case 2:
            val = pop(stack, &top);
            if (val != -1)
                printf("Popped element: %d\n", val);
            break;
        case 3:
            display(stack, top);
            break;
        case 4:
            printf("Are you sure you want to exit? (1 for Yes, 0 for No): ");
            scanf("%d", &temp);
            if (temp == 1)
                return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (1);
    return 0;
}
