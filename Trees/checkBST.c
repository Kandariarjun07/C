#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool checkBSTFast(struct Node *root, int l, int h)
{
    if (root == NULL)
        return true;
    if (root->data > l && root->data < h)
    {
        bool left = checkBSTFast(root->left, l, root->data);
        bool right = checkBSTFast(root->right, root->data, h);
        return left && right;
    }
    else
    {
        return false;
    }
}

bool isBST(struct Node *root)
{
    return checkBSTFast(root, INT_MIN, INT_MAX);
}

struct Node *insert(struct Node *root)
{
    printf("Enter data: ");
    int data;
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }

    root = createNode(data);
    printf("Enter left value for %d: ", data);
    root->left = insert(root->left);
    printf("Enter right value for %d: ", data);
    root->right = insert(root->right);

    return root;
}

void postorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct Node *root = NULL;

    printf("Enter the sequence to build the binary tree (enter -1 for NULL):\n");
    root = insert(root);

    printf("Postorder traversal of the binary tree: ");
    postorderTraversal(root);
    printf("\n");

    if (isBST(root))
    {
        printf("The binary tree is a Binary Search Tree (BST).\n");
    }
    else
    {
        printf("The binary tree is NOT a Binary Search Tree (BST).\n");
    }

    return 0;
}
