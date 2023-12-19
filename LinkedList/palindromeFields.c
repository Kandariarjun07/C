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
int isPalindrome(int num)
{
    if (num < 0 || num / 10 == 0)
    {
        return 0;
    }
    int temp = num, reverse = 0;
    while (num != 0)
    {
        int rem = num % 10;
        reverse = reverse * 10 + rem;
        num /= 10;
    }
    if (temp == reverse)
        return 1;
    else
        return 0;
}
void countPalindrome(node *head, int *count)
{
    if(head == NULL)
        return;
    while(head != NULL){
        if(isPalindrome(head->data)){
            (*count)++;
        }
        head = head->next;
    }
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n, data;
    printf("Enter number of elements to add : ");
    scanf("%d", &n);
    printf("Enter element to be added: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert(&head, &tail, data);
    }
    int count = 0;
    countPalindrome(head, &count);
    printf("\nNumber of palindromic numbers in the list are :%d\n", count);
}