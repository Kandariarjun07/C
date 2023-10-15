#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;
void insertInSortedWay(node **head, int val)
{
    node *insertNode = (node *)malloc(sizeof(node));
    insertNode->data = val;
    if (*head == NULL || val < (*head)->data)
    {
        insertNode->next = *head;
        insertNode->prev = NULL;
        if (*head != NULL)
            (*head)->prev = insertNode;
        *head = insertNode;
    }
    else
    {
        node *temp = *head;
        while (temp && temp->next && temp->next->data < val)
            temp = temp->next;
        insertNode->next = temp->next;
        insertNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = insertNode;
        temp->next = insertNode;
    }
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
void deleteNode(node **head, int val)
{
    if (*head == NULL)
    {
        printf("Nothing to Delete!!\n");
        return;
    }
    node *temp = *head;
    while (temp != NULL && temp->data != val)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Element not found in List!!\n");
        return;
    }
    if (temp == *head)
        *head = (*head)->next;
    else
    {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }
    free(temp);
}
int main()
{
    node *head = NULL;
    insertInSortedWay(&head, 1);
    insertInSortedWay(&head, 2000);
    insertInSortedWay(&head, -2000);
    insertInSortedWay(&head, 200);
    insertInSortedWay(&head, 150);
    insertInSortedWay(&head, -4);
    insertInSortedWay(&head, 5);
    insertInSortedWay(&head, -6);
    deleteNode(&head, -6);
    display(head);
    return 0;
}
