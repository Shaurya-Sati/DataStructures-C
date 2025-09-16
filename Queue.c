#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *arr;
};

void create(struct queue *q,int size) {
    q->size=size;
    q->front=q->rear=-1;
    q->arr=(int*)malloc(sizeof(int) * q->size);
}

int isfull(struct queue *q) {
    return q->rear==q->size-1;
}

int isempty(struct queue *q) {
    return q->front==q->rear;
}

void enqueue(struct queue *q,int val) {
    if (isfull(q)) {
        printf("Queue overflow\n");
    } else {
        q->rear++;
        q->arr[q->rear]=val;
    }
}

int dequeue(struct queue *q) {
    int x=-1;
    if (isempty(q)) {
        printf("Queue underflow\n");
    } else {
        q->front++;
        x=q->arr[q->front];
    }
    return x;
}

void display(struct queue *q) {
    if (isempty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue Elements\n");
    for (int i=q->front+1;i<=q->rear;i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct queue q;
    int size,choice,val;
    printf("Enter size of queue: ");
    scanf("%d" , &size);
    create(&q,size);
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. check is queue is empty\n4. check if queue is full\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d" , &choice);
        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d" , &val);
                enqueue(&q,val);
                break;
            case 2: {
                int x=dequeue(&q);
                printf("%d element dequeued", x);
                break;
            }
            case 3: {
                int y=isempty(&q);
                if (y==1) printf("Queue is empty\n");
                else printf("Queue is not empty\n");
                break;
            }
            case 4: {
                int z=isfull(&q);
                if (z==1) printf("Queue is full\n");
                else printf("Queue is not full\n");
                break;
            }
            case 5: 
                display(&q);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!=6);
    free(q.arr);
    return 0;
}