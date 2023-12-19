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
void countLeafRecursevely(node *root, int *count)
{
    if (root == NULL)
    {
        return;
    }
    countLeafRecursevely(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        (*count)++;
    }
    countLeafRecursevely(root->right, count);
}
void countLeafIteratevely(node *root, int *count)
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
            if (curr->left == NULL && curr->right == NULL)
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
    countLeafRecursevely(root, &count);
    printf("\nCount using Recursion: %d\n", count);
    count = 0;
    countLeafIteratevely(root, &count);
    printf("\nCount using Iteration: %d\n", count);
}