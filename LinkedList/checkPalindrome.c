#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, node **tail, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
void printList(node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
node*getMiddle(node*head){
    node *slow=head;
    node *fast=head;
    node *prev = NULL;
    while(fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast != NULL){
        return slow;
    }
    else{
        return prev;
    }
}
node*reverseLL(node*head){
    node*current = head;
    node*next = NULL;
    node*prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n;
    printf("Enter number of elements to insert : ");
    scanf("%d", &n);
    printf("Enter data seperated by space : ");
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        insert(&head, &tail, x);
    }
    printf("Given linked list : ");
    printList(head);

    node *middle = getMiddle(head);
    node *head2 = middle->next;
    middle->next = NULL;
    // for even number of elements(let n), both list will have n/2 elements
    //for odd number of elements, first list will have 1 extra element that is middle one
    head2 = reverseLL(head2);
    //now head and head2 are 2 seperate linked list
    int flag = 1;
    //comparing all elements of both list
    while (head != NULL && head2 != NULL)
    {
        //if any one of the element is not same, then flag = 0 that is not palindrome
        if (head->data != head2->data)
        {
            flag = 0;
            break;
        }
        head = head->next;
        head2 = head2->next;
    }
    if(flag == 0){
        printf("The list is not a palindrome!!\n");
    }
    else{
        printf("The list is a palindrome!!\n");
    }
}