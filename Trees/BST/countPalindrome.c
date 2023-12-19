#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *insertInBST(node *root, int data)
{
    if (root == NULL)
    {
        // creating a node and assigning it to root
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data) // Lesser value goes to left
    {

        root->left = insertInBST(root->left, data);
    }
    else // Greater value goes to right side
    {
        root->right = insertInBST(root->right, data);
    }
    return root;
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
void countpalindromeRecursively(node *root, int *count)
{
    if (root == NULL)
    {
        return;
    }
    countpalindromeRecursively(root->left, count);
    if (isPalindrome(root->data))
    {
        (*count)++;
    }
    countpalindromeRecursively(root->right, count);
}
void countpalindromeItratively(node *root, int *count)
{
    node *stack[MAX];
    int top = -1;
    node *curr = root;
    while (curr != NULL || top != -1)
    {
        while (curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }
        if (top != -1)
        {
            curr = stack[top--];
            if (isPalindrome(curr->data))
            {
                (*count)++;
            }
        }
        curr = curr->right;
    }
}

int main()
{
    node *root = NULL;
    int data;
    printf("Enter Data and Enter -1 to Stop : ");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        root = insertInBST(root, data);
    }
    int count = 0;
    countpalindromeRecursively(root, &count);
    printf("\nCount of Palindromic Nodes Recursively are %d ", count);
    count = 0;
    countpalindromeItratively(root, &count);
    printf("\nCount of Palindromic Nodes Iteratively are %d \n", count);
}
// 121 90 99 70 130 125 141 -1