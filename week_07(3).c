#include <stdio.h>
#include <stdlib.h>

int cur_size = 0;

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
    int size;
};

struct node *create_node(int x) {
    struct node *linked = (struct node *)malloc(sizeof(struct node));
    if (linked == NULL) {
        printf("Fatal error: Memory allocation failed\n");
        exit(1);
    }
    linked->data = x;
    linked->next = NULL;
    return linked;
}

struct queue *create_queue() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    int x;
    printf("Enter max size for queue:\n");
    scanf("%d", &x);
    q->size = x;
    cur_size = 0;
    return q;
}

int isfull(struct queue *q) {
    return cur_size == q->size;
}

int isempty(struct queue *q) {
    return cur_size == 0;
}

void enqueue(struct queue *q) {
    if (isfull(q)) {
        printf("Queue overflow condition\n");
        return;
    }
    int x;
    printf("Enter element to add in queue:\n");
    scanf("%d", &x);
    struct node *temp = create_node(x);

    if (isempty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    cur_size++;
}

int dequeue(struct queue *q) {
    if (isempty(q)) {
        printf("Queue underflow condition\n");
        return -1;
    }
    struct node *temp = q->front;
    int removed_data = temp->data;
    q->front = q->front->next;
    free(temp);
    cur_size--;

    if (q->front == NULL) { // If the queue becomes empty
        q->rear = NULL;
    }
    return removed_data;
}

void display(struct queue *q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = q->front;
    printf("Queue contents (front to rear):\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue *q = create_queue();
    int choice;
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enqueue(q);
                break;
            case 2: {
                int removed = dequeue(q);
                if (removed != -1) {
                    printf("Dequeued: %d\n", removed);
                }
                break;
            }
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}
