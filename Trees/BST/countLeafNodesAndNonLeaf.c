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
// queue creation of LevelOrder traversal
typedef struct queue
{
    // since it will hold node so pointer to node is required
    node *data;
    struct queue *next;
} queue;
queue *enqueue(queue *q, node *treeNode)
{
    // creating node and assigning it incoming node value
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->data = treeNode;
    temp->next = NULL;
    if (q == NULL)
    {
        q = temp;
    }
    else
    {
        queue *ptr = q;
        // looping till we reach last node
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
    // temporarily storing root value in temp
    node *temp = (*q)->data;
    // for freeing front pointer
    queue *ptr = *q;
    // dequeing
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
    // storing first element
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
void countLeaveNodes(node *root, int *cnt)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        (*cnt)++;
    countLeaveNodes(root->left, cnt);
    countLeaveNodes(root->right, cnt);
}
void countNonLeaveNodes(node *root, int *cnt)
{
    if (root == NULL)
        return;
    if (!(root->left == NULL && root->right == NULL))
        (*cnt)++;
    countNonLeaveNodes(root->left, cnt);
    countNonLeaveNodes(root->right, cnt);
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
    levelOrdertraversal(root);
    // 10 7 6 9 8 4 5 13 15 11 12 14 16 -1
    int cntLeaves = 0, cntNonLeaves = 0;
    countLeaveNodes(root, &cntLeaves);
    printf("\n%d", cntLeaves);
    countNonLeaveNodes(root, &cntNonLeaves);
    printf("\n%d", cntNonLeaves);
    return 0;
}