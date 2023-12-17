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
node *reverse(node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    int i = 0;
    while (i < k && curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    if (next != NULL)
        head->next = reverse(curr, k);
    return prev;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    printf("Enter numbers of elements to insert : ");
    int n, ele;
    scanf("%d", &n);
    printf("Enter data seperated by space : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        insert(&head, &tail, ele);
    }
    printf("Enter k : ");
    int k;
    scanf("%d", &k);
    if(k>n){
        printf("Invalid value of K\n");
    }
    else{
        head=reverse(head,k);
    }
    printf("List after reversing in k groups : ");
    display(head);
}