#include <stdio.h>
#include <stdlib.h>

// Singly LL

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
    }
    *tail = temp;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("Empty");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void merge(node **head, node **tail, node *h1, node *h2)
{
    if (h1 == NULL)
    {
        *head = h2;
        return;
    }
    if (h2 == NULL)
    {
        *head = h1;
        return;
    }
    while (h1 && h2)
    {
        if (h1->data > h2->data)
        {
            insert(head, tail, h2->data);
            h2 = h2->next;
        }
        else
        {
            insert(head, tail, h1->data);
            h1 = h1->next;
        }
    }
    while (h1)
    {
        insert(head, tail, h1->data);
        h1 = h1->next;
    }
    while (h2)
    {
        insert(head, tail, h2->data);
        h2 = h2->next;
    }
}
int main()
{
    node *head1 = NULL;
    node *tail1 = NULL;
    node *head2 = NULL;
    node *tail2 = NULL;

    insert(&head1, &tail1, 1);
    insert(&head1, &tail1, 3);
    insert(&head1, &tail1, 5);
    insert(&head1, &tail1, 7);
    insert(&head2, &tail2, 2);
    insert(&head2, &tail2, 4);
    insert(&head2, &tail2, 6);
    insert(&head2, &tail2, 8);
    node *mergeHead = NULL;
    node *mergeTail = NULL;
    merge(&mergeHead, &mergeTail, head1, head2);
    display(mergeHead);
}