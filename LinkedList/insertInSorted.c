#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

void insertInSortedWay(node **head, int val)
{
    node *insertNode = (node *)malloc(sizeof(node));
    insertNode->data = val;

    if (*head == NULL || val < (*head)->data)
    {
        insertNode->next = *head;
        *head = insertNode;
    }
    else
    {
        node *temp = *head;
        while (temp && temp->next)
        {
            if (temp->next->data > val || temp == NULL)
            {
                break;
            }
            temp = temp->next;
        }
        insertNode->next = temp->next;
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
    do
    {
        printf("%d ", head->data);
        head = head->next;
    } while (head != NULL);
    printf("\n");
    free(head);
}
void deleteNode(node **head, int val)
{
    if (*head == NULL)
    {
        printf("Nothing to Delete!!\n");
        return;
    }
    node *temp = *head;
    if (temp->data == val)
    {
        node *temp2 = *head;
        *head = (*head)->next;
        free(temp2);
        return;
    }
    while (temp->next && temp->next->data != val)
    {
        temp = temp->next;
    }

    if (temp->next != NULL)
    {
        node *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = NULL;
        free(temp2);
    }
    else
    {
        printf("Element not found in List!!\n");
    }
}

int main()
{
    node *head = NULL;

    insertInSortedWay(&head, 11);
    insertInSortedWay(&head, 202);
    insertInSortedWay(&head, 3);
    insertInSortedWay(&head, 14);
    deleteNode(&head, 13);
    display(head);
}