#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *array;
};

void createQueue(struct Queue *q, int size) {

    q->size = size;
    q->front = q->rear = -1;
    q->array = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int value) {

    if (q->rear == q->size-1) {
        printf("Queue is full\n");
    }
    else {
        q->rear++;
        q->array[q->rear] = value;
    }

}

int dequeue(struct Queue *q) {

    int x=-1;
    if (q->front == q->rear) {
        printf("Queue is Empty.");
    }
    else {
        q->front++;
        x = q->array[q->front];
    }
    return x;
}

void display(struct Queue *q) {

    for (int i=q->front+1; i<=q->rear;i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

int main() {

    struct Queue q;
    createQueue(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);//full queue before deleting the first element

    dequeue(&q);

    display(&q);//after deleting the first element

    return 0;
}
