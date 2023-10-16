#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
typedef struct node node;

void push(node** head, int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    if (*head == NULL) {
        temp->next = NULL;
        *head = temp;
    }
    else {
        temp->next = *head;
        *head = temp;
    }
}

int isEmpty(node* head) {
    if (head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void display(node* head) {
    if (head == NULL) {
        printf("Stack is Empty!!\n");
    }
    else {
        node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int pop(node** head) {
    int val;
    if (*head == NULL) {
        printf("Underflow\n");
        val = -1;
    }
    else {
        node* temp = *head;
        val = temp->data;
        *head = (*head)->next;
        free(temp);
    }
    return val;
}
int main() {
    node* head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    display(head);
    isEmpty(head) ? printf("Stack is empty!!\n") : printf("Stack isn't empty!!\n");

}