#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

struct stack *create(int size)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    if (st == NULL)
    {
        printf("Error creating stack!\n");
        exit(1);
    }
    st->size = size;
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));
    if (st->arr == NULL)
    {
        printf("Error allocating memory for stack array!\n");
        free(st); // Free the previously allocated memory for the stack structure
        exit(1);
    }
    return st;
}

int isempty(struct stack *st)
{
    return st->top == -1;
}

int isfull(struct stack *st)
{
    return st->top == st->size - 1;
}

void push(struct stack *st,int x)
{
    if (isfull(st))
    {
        printf("Stack overflow!\n");
        return;
    }
   
   
    st->arr[++st->top] = x;
}

void  pop(struct stack *st)
{
    if (!isempty(st))
    {
        st->top--;
        return;
    }
   printf("underflow:\n");
}
char peek(struct stack *st)
{
    if (isempty(st))
    {
        return -1;
    }
    return st->arr[st->top];
}

void printstack(struct stack *st)
{
    printf("printing stack :\n");
    for (int i = 0; i <= st->top; i++)
    {
        printf("%c ", st->arr[i]);
    }
    printf("\n");
}
bool check_valid(char *str){
    int n = strlen(str);

    struct stack *st = create(n);
    while(*str != '\0'){
        if(*str == '(' || *str == '[' || *str == '{'){
            push(st,*str);
        }
        else{
          if(*str == '}' && peek(st) == '{'){
            pop(st);
          }
          else if(*str == ')' && peek(st) == '('){
             pop(st);
          }
          else if(*str == ']' && peek(st) == '['){
             pop(st);
          }
          else{
              free(st->arr);
                free(st);
            return false;
          }
        }
        str++;
    }
   bool isValid = isempty(st);

    free(st->arr);
    free(st);
    return isValid;
}

int main()
{
    
    char str[100];
    printf("enter string to check for valid parantheis:\n");
    scanf("%s",str);
    bool ans  = check_valid(str);
    if(ans){
        printf("string is valid :\n");

    }
    else{
        printf("string is not valid \n");
    }

    return 0;
}
