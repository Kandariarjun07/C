#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void insertInSortedWay(node **head, node **tail, int val)
{
    node *insertNode = (node *)malloc(sizeof(node));
    insertNode->data = val;

    if (*head == NULL || *head != NULL && val <= ((*head)->data))
    {
        insertNode->next = *head;
        insertNode->prev = *tail;
        if (*head != NULL)
        {
            (*head)->prev = insertNode;
            (*tail)->next = insertNode;
        }
        else
            *tail = insertNode;
        *head = insertNode;
        return;
    }
    node *temp2 = *head;
    while (temp2->next != *head && temp2->next->data < val)
        temp2 = temp2->next;
    if (temp2->next == *head)
    {
        insertNode->next = *head;
        insertNode->prev = temp2;
        temp2->next = insertNode;
        *tail = insertNode;
        (*head)->prev = insertNode;
        return;
    }
    insertNode->next = temp2->next;
    insertNode->prev = temp2;
    temp2->next->prev = insertNode;
    temp2->next = insertNode;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("Empty");
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
}

void deleteNode(node **head, node **tail, int val)
{
    if (*head == NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    if (*head == *tail && (*head)->data == val)
    {
        *head = NULL;
        *tail = NULL;
        return;
    }
    node *temp = *head;
    while (temp != *tail && temp->data != val)
        temp = temp->next;
    if (temp->data != val)
    {
        printf("Element Not Found\n");
        return;
    }
    if (temp == *head)
    {
        *head = temp->next;
        (*head)->prev = *tail;
        (*tail)->next = *head;
    }
    else if (temp == *tail)
    {
        *tail = temp->prev;
        (*tail)->next = *head;
        (*head)->prev = *tail;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    temp->next = temp->prev = NULL;
    free(temp);
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertInSortedWay(&head, &tail, 1);
    insertInSortedWay(&head, &tail, -1);
    insertInSortedWay(&head, &tail, 0);
    insertInSortedWay(&head, &tail, 10);
    insertInSortedWay(&head, &tail, -2);

    deleteNode(&head, &tail, 1);
    display(head);
    return 0;
}
