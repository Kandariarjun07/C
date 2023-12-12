#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
        printf("Nothing to display!\n");
        return;
    }
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
node *getMiddle(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *fast = head->next;
    node *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
node *merge(node *h1, node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    node *ans = (node *)malloc(sizeof(node));
    ans->data = -1;
    node *temp = ans;
    while (h1 && h2)
    {

        if (h1->data < h2->data)
        {
            temp->next = h1;
            temp = temp->next;
            h1 = h1->next;
        }
        else
        {
            temp->next = h2;
            temp = temp->next;
            h2 = h2->next;
        }
    }
    while (h1)
    {
        temp->next = h1;
        temp = temp->next;
        h1 = h1->next;
    }
    while (h2)
    {
        temp->next = h2;
        temp = temp->next;
        h2 = h2->next;
    }
    return ans->next;
}
node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *mid = getMiddle(head);
    node *right = mid->next;
    node *left = head;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insert(&head, &tail, 1);
    insert(&head, &tail, 1032);
    insert(&head, &tail, 123);
    insert(&head, &tail, -2332);
    insert(&head, &tail, 0);
    insert(&head, &tail, 0);
    display(head);
    head = mergeSort(head);
    display(head);
    return 0;
}