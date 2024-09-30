#include<stdio.h>
#include<stdlib.h>
int top = -1;
int n;

int * create_stack(int size){
    n = size;
   int * arr = (int*)malloc(size*sizeof(int));
    if(arr == NULL){
       printf("error in creating stack");
        exit(1);
    }
    
        return arr;
  
}
int isfull(int *stack){
    if(top == n-1){
        return 1;

    }
    return 0;
}
int isempty(int *stack){
    if(top == -1){
        return 1;
    }
    return 0;
}
void push(int *stack) {
    if (isfull(stack)) { // Check overflow before taking input
        printf("stack overflow:\n");
        return;
    }
    int temp;
    printf("enter element to store in stack\n");
    scanf("%d", &temp);
    stack[++top] = temp; // Push the element onto the stack
}

int pop(int *stack){
    if(isempty(stack)){
        printf("underflow condition:\n");
        return -1;
    }
    return stack[top--];
}
int peek(int *stack){
    return stack[top];
}
void display(int *stack){
    printf("printing stack\n");
    for(int  i = 0;i<=top;i++){
        printf("%d >",stack[i]);
        
    }
    printf("\n");
}

int main(){
    int * stack = create_stack(5);
    while(1){
    int x;
    printf("enter choice:\n");
    printf("1: push element\n 2: pop element\n 3:peek element\n 4: display the stack\n 5: exit\n");
    scanf("%d",&x);
    if(x==5){
        printf("thankyou for visting:\n");
        break;
    }
    switch(x){
        case 1:
        push(stack);
        break;

        case 2:
        printf("poopig the elemnt : %d\n",pop(stack));
        break;

        case 3:
        printf("printing peek element : %d\n",peek(stack));
        break;
        case 4:
        display(stack);
        break;
        default:
        printf("please enter valid input\n");
        break;

    }

    }
    return 0;

}