#include <stdio.h>
#include <stdlib.h>
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
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }
    return root;
}
int getHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = getHeight(root->left) + 1;
    int right = getHeight(root->right) + 1;
    return (left > right) ? left : right;
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
    printf("Height of BST is : %d", getHeight(root));
    // 10 7 6 9 8 4 5 13 15 11 12 14 16 3 2 -1
    return 0;
}