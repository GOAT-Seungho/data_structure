#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue * pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue * pq) {
    if (pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue * pq, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (QIsEmpty(pq)) {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue * pq) {
    if(QIsEmpty(pq)) {
        printf("Queue Memory Error !");
        exit(-1);
    }

    Node * rnode = pq->front;
    Data rdata = rnode->data;

    pq->front = pq->front->next;

    free(rnode);
    return rdata;
}