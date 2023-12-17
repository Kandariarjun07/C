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
    int n1, n2, ele1, ele2;
    printf("Enter number of elements for first list : ");
    scanf("%d", &n1);
    printf("Enter the elements of first list: ");
    for (int i = 0; i < n1; i++){
        scanf("%d", &ele1);
        insert(&head1, &tail1, ele1);
    }
    printf("Enter number of elements for second list : ");
    scanf("%d", &n2);
    printf("Enter the elements of second list: ");
    for (int j = 0; j < n2; j++){
        scanf("%d", &ele2);
        insert(&head2, &tail2, ele2);
    }
    printf("First linked list : ");
    display(head1);
    printf("Second linked list : ");
    display(head2);
    node *mergeHead = NULL;
    node *mergeTail = NULL;
    merge(&mergeHead, &mergeTail, head1, head2);
    printf("Merged Linked List is : ");
    display(mergeHead);
}