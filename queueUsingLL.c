#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node node;

void enqueue(node** head, node** tail, int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    if (*head == NULL) {
        *head = temp;
        *tail = temp;
        temp->next = NULL;
    }
    else {
        (*tail)->next = temp;
        *tail = temp;
        temp->next = NULL;
    }
}

int isEmpty(node* head) {
    if (head == NULL) {
        return 1;
    }
    return 0;
}

void display(node* head) {
    if (head == NULL) {
        printf("Nothing to Show!\n");
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
int dequeue(node** head) {
    int val;
    if (*head == NULL) {
        printf("Stack underflow!!\n");
        val = -1;
    }
    else {
        node* temp = *head;
        val = temp->data;
        *head = (*head)->next;
        free(temp);
        printf("Element popped : %d\n", val);
    }
    return val;
}
int main() {
    node* head = NULL;
    node* tail = NULL;

    enqueue(&head, &tail, 1);
    enqueue(&head, &tail, 2);
    enqueue(&head, &tail, 3);
    enqueue(&head, &tail, 4);
    enqueue(&head, &tail, 5);
    dequeue(&head);
    display(head);
}