#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create_node()
{
    int x;
    printf("enter data to store in linked list\n");
    scanf("%d", &x);
    struct node *linked = (struct node *)calloc(1, sizeof(struct node));
    if (linked == NULL)
    {
        printf("fatal error\n");
        exit(1);
    }
    linked->data = x;
    linked->next = NULL;
    return linked;
}
int get_length(struct node *head)
{
    struct node *temp = head;
    int count = 0;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void insert_head(struct node **head)
{

    struct node *temp = create_node();
    temp->next = *head;
    *head = temp;
}
void insert_tail(struct node **head)
{
    struct node *temp = create_node();
    struct node *tail = *head;
    while (tail->next)
    {
        tail = tail->next;
    }
    tail->next = temp;
}
void insert_random(struct node **head, int pos)
{
    int x;
    printf("enter data to store in linked list\n");
    scanf("%d", &x);
    int size = get_length(*head);
    if (pos <= 1)
    {
        insert_head(&(*head));
    }
    else if (pos >= size)
    {
        insert_tail(&(*head));
    }
    else
    {
        struct node *newnode = NULL;

        struct node *temp = *head;
        while (pos--)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void print_list(struct node *head)
{
    printf("printing the linked list:\n");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node *head = create_node();
    while (1)
    {
        printf("=============================================================\n");
        int x;
        printf("enter choice\n");
        printf("1: insert at head\n 2: insert at tail\n 3: insert at any position\n 4: display the linked list and exit\n");
        scanf("%d", &x);
        if (x == 4)
        {
            print_list(head);
            break;
        }
        switch (x)
        {
        case 1:
            insert_head(&head);
            break;
        case 2:
            insert_tail(&head);
            break;
        case 3:
            insert_random(&head, 2);
            break;
        default:
            printf("please enter valid input:\n");
            break;
        }
    }

    return 0;
}
