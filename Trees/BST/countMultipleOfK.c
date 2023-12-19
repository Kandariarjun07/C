#include <stdio.h>
#include <stdlib.h>
#define MAX 100
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
void countMultipleRecursevely(node *root, int k, int *count)
{
    if (root == NULL)
    {
        return;
    }
    countMultipleRecursevely(root->left, k, count);
    if ((root->data) % k == 0)
    {
        (*count)++;
    }
    countMultipleRecursevely(root->right, k, count);
}
void countMultipleIteratevely(node *root, int k, int *count)
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
            if ((curr->data) % k == 0)
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
    int k;
    printf("Enter value of k : ");
    scanf("%d", &k);
    int count = 0;
    countMultipleRecursevely(root,k, &count);
    printf("\nCount using Recursion: %d\n", count);
    count = 0;
    countMultipleIteratevely(root,k, &count);
    printf("\nCount using Iteration: %d\n", count);
}