#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

void insertInSortedWay(node **head, node **tail, int val)
{
    node *insertNode = (node *)malloc(sizeof(node));
    insertNode->data = val;

    if (*head == NULL)
    {
        *head = insertNode;
        *tail = insertNode;
        insertNode->next = insertNode;
        return;
    }
    node *temp = *head;
    if (val <= temp->data)
    {
        insertNode->next = *head;
        (*tail)->next = insertNode;
        *head = insertNode;
        return;
    }
    while (val > temp->next->data && temp != *tail)

        temp = temp->next;

    insertNode->next = temp->next;
    temp->next = insertNode;
    if (temp == *tail)
        *tail = insertNode;
}
void display(node *head)
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Empty");
        return;
    }
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
    free(head);
}
void deleteNode(node **head, node **tail, int val)
{
    if (*head == NULL)
    {
        printf("Nothing to Delete!!\n");
        return;
    }
    node *temp = *head;
    if (temp->next == *head)
    {
        if (temp->data == val)
        {
            node *temp2 = *head;
            *head = (*head)->next;
            free(temp2);
        }
        return;
    }
    if (temp->data == val)
    {
        node *temp2 = *head;
        *head = (*head)->next;
        temp2->next = NULL;
        free(temp2);
        (*tail)->next = *head;
        return;
    }
    while (temp != *tail && temp->next->data != val)
        temp = temp->next;

    if (temp != *tail)
    {
        node *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = NULL;
        free(temp2);
        if (temp->next == *head)
        {
            *tail = temp;
        }
    }
    else
    {
        printf("Element not found in List!!\n");
    }
}
int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertInSortedWay(&head, &tail, 1);
    insertInSortedWay(&head, &tail, 2);
    insertInSortedWay(&head, &tail, 3);
    insertInSortedWay(&head, &tail, -84);
    insertInSortedWay(&head, &tail, 500);
    insertInSortedWay(&head, &tail, -6);
    deleteNode(&head, &tail, 500);
    display(head);
}