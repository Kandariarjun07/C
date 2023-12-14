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

typedef struct stackNode
{
    node *data;
    struct stackNode *next;
} stackNode;

typedef struct stack
{
    stackNode *top;
} stack;

stackNode *createNode(node *data)
{
    stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push(stack **s, node *data)
{
    stackNode *newNode = createNode(data);
    if ((*s) == NULL)
    {
        *s = (stack *)malloc(sizeof(stack));
        (*s)->top = newNode;
    }
    else
    {
        newNode->next = (*s)->top;
        (*s)->top = newNode;
    }
}
int isStackEmpty(stack *s) { return (s == NULL || s->top == NULL); }

node *pop(stack **s)
{
    if (isStackEmpty(*s))
        return NULL;
    node *res = (*s)->top->data;
    stackNode *temp = (*s)->top;
    (*s)->top = (*s)->top->next;
    free(temp);
    return res;
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

void preorderIterative(node *root)
{
    if (root == NULL)
        return;
    stack *Stack = NULL;
    push(&Stack, root);
    while (!isStackEmpty(Stack))
    {
        node *currentNode = pop(&Stack);
        printf("%d ", currentNode->data);

        if (currentNode->right != NULL)
        {
            push(&Stack, currentNode->right);
        }
        if (currentNode->left != NULL)
        {
            push(&Stack, currentNode->left);
        }
    }
}
void inorderItertive(node*root){
    if(root == NULL)
        return;
    stack* Stack=NULL;
    node* curr = root;
    while(curr != NULL || !isStackEmpty(Stack)){
        while(curr){
            push(&Stack, curr);
            curr = curr->left;
        }
        curr = pop(&Stack);
        printf("%d ", curr->data);
        curr = curr->right;
    }
}
void postorderIterative(node *root){
    if (root == NULL)
        return;
    stack *Stack1 = NULL;
    stack *Stack2 = NULL;
    push(&Stack1, root);

    while (!isStackEmpty(Stack1))
    {
        node *currentNode = pop(&Stack1);
        push(&Stack2, currentNode);
        if (currentNode->left != NULL)
        {
            push(&Stack1, currentNode->left);
        }
        if (currentNode->right != NULL)
        {
            push(&Stack1, currentNode->right);
        }
    }
    while (!isStackEmpty(Stack2)){
        node* temp=pop(&Stack2);
        printf("%d ", temp->data);
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
    printf("\nInorder Traversal Iterative : ");
    inorderItertive(root);
    printf("\nPreorder Traversal Iterative : ");
    preorderIterative(root);
    printf("\nPostorder Traversal Iterative : ");
    postorderIterative(root);
    printf("\nLevel Order Traversal : ");
    levelOrdertraversal(root);
    // 10 7 6 9 8 4 5 13 15 11 12 14 16 -1
    return 0;
}