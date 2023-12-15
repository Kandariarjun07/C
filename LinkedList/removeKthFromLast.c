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
void removeKthFromLast(node **head, int k)
{
    if (head == NULL || *head == NULL || k <= 0)
    {
        return; 
    }
    node *fast = *head;
    node *slow = *head;
    node *prev = NULL;
    for (int i = 0; i < k; ++i)
    {
        if (fast == NULL)
        {
            return; 
        }
        fast = fast->next;
    }
    while (fast != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    
    if (prev == NULL)
    {
        *head = slow->next;
    }
    else
    {
        prev->next = slow->next;
    }

    free(slow); 
}

int getMiddle(node *head)
{
    node *fast = head;
    node *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insert(&head, &tail, 10);
    insert(&head, &tail, 20);
    insert(&head, &tail, 30);
    insert(&head, &tail, 40);
    insert(&head, &tail, 50);
    insert(&head, &tail, 60);
    insert(&head, &tail, 70);
    insert(&head, &tail, 80);
    display(head);
    removeKthFromLast(&head, 3);
    display(head);
}