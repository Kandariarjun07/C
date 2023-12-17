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

void LevelOrderEasy(node *root)
{
    if (root == NULL)
        return;
    node *queue[MAX];
    int f = 0, r = -1;
    queue[++r] = root;
    queue[++r] = NULL;
    while (f <= r)
    {
        node *currNode = queue[f++];
        if (currNode == NULL)
        {
            if (f <= r)
            {
                printf("\n");
                queue[++r] = NULL;
            }
        }
        else
        {
            printf("%d ", currNode->data);
            if (currNode->left != NULL)
            {
                queue[++r] = currNode->left;
            }
            if (currNode->right != NULL)
            {
                queue[++r] = currNode->right;
            }
        }
    }
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
node *findMax(node *root)
{
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}
node *findMin(node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}
node *deleteNode(node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            // node* minNode = findMin(root->right);
            // root->data = minNode->data;
            // root->right = deleteNode(root->right,minNode->data);
            node *maxNode = findMax(root->left);
            root->data = maxNode->data;
            root->left = deleteNode(root->left, maxNode->data);
        }
    }
    return root;
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
    printf("InOrder Traversal: ");
    inorder(root);
    printf("\n");

    printf("LevelOrder Traversal:\n");
    LevelOrderEasy(root);
    printf("\n");

    printf("Enter Value to delete : ");
    scanf("%d", &data);
    root = deleteNode(root, data);

    printf("InOrder Traversal: ");
    inorder(root);
    printf("\n");
    
    printf("LevelOrder Traversal:\n");
    LevelOrderEasy(root);
    printf("\n");
    // 10 7 6 9 8 4 5 13 15 11 12 14 16 -1

    return 0;
}