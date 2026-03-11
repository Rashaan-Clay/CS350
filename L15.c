#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define MAX_SIZE 100


typedef struct node
{
    int value;
    struct node* nextPtr;
}node;

typedef struct queue
{
    struct node* frontPtr;
    struct node* rearPtr;
}mgmt;

mgmt* create_queue(int capacity)
{
    mgmt* queuePtr = malloc(sizeof(node));
    if (queuePtr == NULL)
    {
        puts("Cannot Allocate");
        exit(1);
    }

    queuePtr->frontPtr = NULL;
    queuePtr->rearPtr = NULL;
    return queuePtr;
}

int enqueue(mgmt* queuePtr, int value)
{
    if (isFull(queuePtr))
    {
        puts("Queue is full");
        return -1;
    }

    if (queuePtr == NULL)
    {
        puts("Invalid");
        return -1;
    }

    node* newPtr = (node*)malloc(sizeof(node));
    if (newPtr == NULL)
    {
        puts("Could not allocate memory");
        return -1;
    }

    newPtr->value = value;
    newPtr->nextPtr = NULL;

    if (queuePtr->rearPtr != NULL)
    {
        queuePtr->rearPtr->nextPtr = newPtr;
        queuePtr->rearPtr = newPtr;
    }
    else
    {
        queuePtr->frontPtr = newPtr;
        queuePtr->rearPtr = newPtr;
    }

    return 0;
    
}

int dequeue(mgmt* queuePtr)
{
    if (is_empty(queuePtr))
    {
        puts("NO items in queue");
        return INT_MIN;
    }

    int value = queuePtr->frontPtr->value;

    node* tempPtr = queuePtr->frontPtr;

    queuePtr->frontPtr = tempPtr->nextPtr;

    if(queuePtr->frontPtr == NULL)
    {
        queuePtr->rearPtr = NULL;
    }

    free(tempPtr);
    tempPtr = NULL;

    return queuePtr;
}

int is_empty(mgmt* queuePtr)
{
    if (queuePtr == NULL)
    {
        puts("Invalid queue.");
        exit(1);
    }

    return ((queuePtr->frontPtr == NULL) || (queuePtr->rearPtr == NULL));
}

bool isFull(mgmt* queuePtr)
{
    return (queuePtr->rearPtr == MAX_SIZE);
}

int main(void)
{
    mgmt q;
    create_queue(5);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 2);
    enqueue(&q, 2);
    enqueue(&q, 2);
    enqueue(&q, 2);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    return 0;
}