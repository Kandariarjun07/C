#include<stdio.h>
#include<stdlib.h>

#define Max 5

void enqueue(int q[], int* front, int* rear, int val)
{
    if (*front == (*rear + 1) % Max) {
        printf("Queue full !!\n");
    }
    else {
        if (*front == -1)
            (*front)++;
        *rear = (*rear + 1) % Max;
        q[*rear] = val;
    }
}

int dequeue(int q[], int* front, int* rear)
{
    int temp;
    if (*front == -1) {
        printf("Stack underflow!!\n");
        temp = -1;
    }
    else if (*front == *rear) {
        temp = q[*front];
        *front = *rear = -1;
    }
    else {
        temp = q[*front];
        *front = (*front + 1) % Max;
    }
}

int getFirst(int q[], int front)
{
    if (front == -1) {
        return -1;
    }
    else {
        return q[front];
    }
}

void display(int q[], int front, int rear)
{
    if (front == -1) {
        printf("Nothing To Display!!\n");
    }
    else {
        while (front != rear) {
            printf("%d ", q[front]);
            front = (front + 1) % Max;
        }
        printf("%d ", q[front]);
        printf("\n");
    }
}

void main()
{
    int queue[Max];
    int front = -1;
    int rear = -1;

    enqueue(queue, &front, &rear, 1);
    enqueue(queue, &front, &rear, 2);
    enqueue(queue, &front, &rear, 3);
    enqueue(queue, &front, &rear, 4);
    enqueue(queue, &front, &rear, 5);
    display(queue, front, rear);
    dequeue(queue, &front, &rear);
    dequeue(queue, &front, &rear);
    display(queue, front, rear);
    enqueue(queue, &front, &rear, 4);
    enqueue(queue, &front, &rear, 5);
}