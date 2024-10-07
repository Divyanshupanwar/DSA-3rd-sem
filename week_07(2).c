#include <stdio.h>
#include <stdlib.h>

int cur_size = 0;

struct node {
    int data;
    struct node *next;
};

struct stack {
    struct node *top;
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

struct stack *create_stack() {
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->top = NULL;
    int x;
    printf("Enter max size for stack:\n");
    scanf("%d", &x);
    st->size = x;
    cur_size = 0;
    return st;
}

int isfull(struct stack *st) {
    return cur_size == st->size;
}

void push(struct stack *st) {
    if (isfull(st)) {
        printf("Can't push, stack overflow\n");
        return;
    }
    int x;
    printf("Enter data to push to stack:\n");
    scanf("%d", &x);
    struct node *temp = create_node(x);
    if (st->top == NULL) {
        st->top = temp;
    } else {
        temp->next = st->top;
        st->top = temp;
    }
    cur_size++;
}

int isempty(struct stack *st) {
    return st->top == NULL;
}

int pop(struct stack *st) {
    if (isempty(st)) {
        printf("Stack is empty, can't pop\n");
        return -1;
    }
    struct node *temp = st->top;
    int popped_data = temp->data;
    st->top = st->top->next;
    free(temp);
    cur_size--;
    return popped_data;
}

int get_peek(struct stack *st) {
    if (isempty(st)) {
        printf("Stack underflow condition\n");
        return -1;
    }
    return st->top->data;
}

// Display function to show the stack contents
void display(struct stack *st) {
    if (isempty(st)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents (top to bottom):\n");
    struct node *temp = st->top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct stack *st = create_stack();
    int choice;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\n5. Display and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                push(st);
                break;
            case 2: {
                int popped = pop(st);
                if (popped != -1) {
                    printf("Popped: %d\n", popped);
                }
                break;
            }
            case 3: {
                int top = get_peek(st);
                if (top != -1) {
                    printf("Top element: %d\n", top);
                }
                break;
            }
            case 4:
                printf("Exiting program.\n");
                exit(0);
            case 5:
                display(st);
                printf("Exiting program after displaying stack.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
