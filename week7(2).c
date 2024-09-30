#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct stack
{
    struct node *top;
}

struct node *
create_node(int x)
{
    struct node *linked = (struct node *)malloc(sizeof(struct node));
    if (linked == NULL)
    {
        printf("Fatal error: Memory allocation failed\n");
        exit(1);
    }
    linked->data = x;
    linked->next = NULL;

    return linked;
}
struct stack *create_stack()
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->top = NULL;
    return st;
}
void push(struct stack *st, int x)
{
    struct node *temp = create_node(x);
    if (st->top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}
int pop(stuct stack *)

    int main()
{

    return 0;
}