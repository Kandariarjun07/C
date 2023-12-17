#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

void insert(node **head, node **tail, int val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        *tail = temp;
    }
    else
    {
        (*tail)->next = temp;
        *tail = temp;
    }
}

int isEmpty(node *head)
{
    return head == NULL;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("Empty");
        return;
    }
    do
    {
        printf("%d ", head->data);
        head = head->next;
    } while (head != NULL);
    printf("\n");
    free(head);
}
int deleteNode(node **head)
{
    if (*head == NULL)
    {
        printf("Underflow");
        return -1;
    }
    node *temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    free(temp);
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insert(&head, &tail, 10);
    display(head);

    insert(&head, &tail, 20);
    display(head);

    insert(&head, &tail, 30);
    display(head);

    insert(&head, &tail, 40);
    display(head);
}