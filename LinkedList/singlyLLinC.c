#include<stdio.h>
#include<stdlib.h>

// Singly LL

struct node {
    int data;
    struct node* next;
};
typedef struct node node;

void insert(node** head, int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}
void insertAtMiddle(node** head, int pos, int val) {
    if (pos == 1) {
        insert(head, val);
    }
    else {
        node* temp = *head;
        int cnt = 1, flag = 1;;
        while (cnt < pos - 1) {
            if (temp->next == NULL) {
                printf("invalid position\n");
                flag = 0;
            }
            temp = temp->next;
            cnt++;
        }
        if (flag) {
            node* newNode = (node*)malloc(sizeof(node));
            newNode->data = val;
            if (temp->next == NULL) {
                temp->next = newNode;
            }
            else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
        else {
            return;
        }
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
        printf("Empty");
        return;
    }
    do {
        printf("%d ", head->data);
        head = head->next;
    } while (head != NULL);
    printf("\n");
    free(head);
}
int deleteNode(node** head) {
    if (*head == NULL) {
        printf("Underflow");
        return -1;
    }
    node* temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    free(temp);
}
int main() {
    node* head = NULL;

    insert(&head, 10);
    display(head);

    insert(&head, 20);
    display(head);

    insert(&head, 30);
    display(head);

    insertAtMiddle(&head, 4, 35);
    display(head);

    insert(&head, 40);
    display(head);

}