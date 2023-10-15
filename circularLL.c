#include<stdio.h>
#include<stdlib.h>

// Singly LL

struct node {
    int data;
    struct node* next;
};
typedef struct node node;

void insertAtHead(node** head, node** tail, int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    if (*head == NULL) {
        *head = temp;
        *tail = temp;
    }
    else {
        *head = temp;
        temp->next = (*tail)->next;
        *tail = temp;
    }
}
void insertAtTail(node** head, node** tail, int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    if (*head == NULL) {
        *head = temp;
        *tail = temp;
    }
    else {
        (*tail)->next = temp;
        temp->next = *head;
        *tail = *head;
    }
}
void display(node* head) {
    if (head == NULL) {
        printf("Nothing to show !!\n");
    }
    else {
        node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp->next != head);
    }
    printf("\n");
}
int main() {
    node* head = NULL;
    node* tail = NULL;
    insertAtHead(&head, &tail, 1);
    display(head);
}