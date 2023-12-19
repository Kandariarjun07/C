#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;
void push_front(node **head, node **tail, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else{
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void push_back(node **head, node **tail, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
void pop_back(node **head, node **tail)
{
    if (*tail == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        node *temp = *tail;
        if ((*head) == (*tail))
        {
            *head = NULL;
            *tail = NULL;
        }
        else
        {
            (*tail)->prev->next = NULL;
            *tail = (*tail)->prev;
        }
        temp->prev = NULL;
        free(temp);
    }
}
void pop_front(node **head, node **tail)
{
    if (*head == NULL)
    {
        printf("List is Empty \n");
    }
    else
    {
        node *temp = *head;
        if ((*head)->next)
        {
            (*head)->next->prev = NULL;
        }
        *head = (*head)->next;
        free(temp);
    }
}
void display(node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        while (head)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter element : ");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        push_back(&head, &tail, x);
    }
    pop_back(&head, &tail);
    pop_front(&head, &tail);
    display(head);
}