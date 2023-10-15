#include<stdio.h>
#include<stdlib.h>

#define Max 5

void enqueue(int q[], int* front, int* rear, int val) {
    if (*rear == Max - 1) {
        printf("Queue is full !!\n");
        return;
    }
    else if (*front == -1)
        *front = 0;
    (*rear)++;
    q[*rear] = val;
}

int dequeue(int q[], int* front, int* rear) {
    int val;
    if (*front == Max) {
        printf("queue is empty !!\n");
        val = -1;
    }
    else {
        val = q[*front];
        (*front)++;
    }
    return val;
}

int getFirst(int q[], int front) {
    if (front == -1 || front == Max) {
        return -1;
    }
    else {
        return q[front];
    }
}

void display(int q[], int front) {
    if (front == -1 || front == Max) {
        printf("Nothing to display !!\n");
    }
    else {
        while (front != Max) {
            printf("%d ", q[front++]);
        }
        printf("\n");
    }
}

void main() {
    int queue[Max];
    int front = -1;
    int rear = -1;
    enqueue(queue, &front, &rear, 1);
    enqueue(queue, &front, &rear, 2);
    enqueue(queue, &front, &rear, 3);
    enqueue(queue, &front, &rear, 4);
    enqueue(queue, &front, &rear, 5);
    dequeue(queue, &front, &rear);
    display(queue, front);
    printf("First element is : %d\n", getFirst(queue, front));
}