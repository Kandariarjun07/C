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
        //creating a node and assigning it to root
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
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node*root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
typedef struct queue
{
    node *data;
    struct queue *next;
} queue;
queue *enqueue(queue *q, node *root)
{
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->data = root;
    temp->next = NULL;
    if (q == NULL)
    {
        q = temp;
    }
    else
    {
        queue *ptr = q;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return q;
}
node *dequeue(queue **q)
{
    if (*q == NULL)
    {
        return NULL;
    }
    node *temp = (*q)->data;
    queue *ptr = *q;
    *q = (*q)->next;
    free(ptr);
    return temp;
}
int isEmpty(queue *q)
{
    return q == NULL;
}
void levelOrdertraversal(node *root)
{
    if (root == NULL)
        return;
    queue *q = NULL;
    q = enqueue(q, root);
    while (!isEmpty(q))
    {
        node *temp = dequeue(&q);
        printf("%d ", temp->data);
        if (temp->left != NULL)
        {
            q = enqueue(q, temp->left);
        }
        if (temp->right != NULL)
        {
            q = enqueue(q, temp->right);
        }
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
    printf("\nInorder Traversal : ");
    inorder(root);
    printf("\nPreorder Traversal : ");
    preorder(root);
    printf("\nPostorder Traversal : ");
    postorder(root);
    printf("\nLevel Order Traversal : ");
    levelOrdertraversal(root);
    // 10 7 6 9 8 4 5 13 15 11 12 14 16 -1
    return 0;
}