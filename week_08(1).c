#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *pre;
    struct node *next;
};
struct node *create_list(){
    struct node *ll = (struct node*)malloc(sizeof(struct node));
    if(ll == NULL){
        printf("error in allocating memory"\n);
        exit(1);
    }
    int x;
    printf("enter data to store in linked list\n");
    scanf("%d",&x);
    ll->data =x;
    ll->next = NULL;
    ll->pre =NULL;

}
int isempty(struct node *head){
    return head ==NULL;
}
void insert_front(struct node **head){
    struct node *temp = create_list();
     temp->next = *head;
     (*head)->pre = temp;
     *head = temp;
}
void insert_end(struct node **head){
    struct node *temp = create_list();
    struct node * temp2 = (*head);
    while(temp2->next){
        temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->pre = temp2;

}
int get_length(struct node *head){
    struct node * temp = head;
    int count  = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;

}
void insert(struct node **head){
    int pos;
    int last = get_length(&head);
    printf("enter position to insert\n");
    scanf("%d",&pos);
    if(pos ==1){
        insert_front(&head);

    }
    else if(pos == last){
        insert_end(&head);
    }
    else{
        struct node *temp = (*head);
        while(pos--){
        temp = temp->next;
        }
        struct node * temp2 = create_list();
        temp2->next = temp->next;
        temp->next = temp2;
        temp2->next->pre = temp2;
        temp2->pre = temp;
    }

}
void delete_front(struct node **head){
    if(!isempty(*head)){
    struct node * temp = (*head);
    (*head) = (*head)->next;
    free(temp);
    }
    else{
        printf("linked list is empty:\n");

    }
}
void delete_end(struct node **head){
    if(!isempty(*head)){
    struct node *temp = (*head);
    while(temp->next){
        temp = temp->next;

    }
    temp->pre = NULL;
    free(temp);
    return;
    }
    printf("linked list is empty:\n");

}
void delete(struct node **head){
    int pos;
    printf("enter postion you want to delete the node\n");
    scanf("%d",&pos);
    if(isempty(*head)){
        printf("can;t delete linked list is empty:\n");
        return;
    }
    if(pos == 1){
        delete_front(head);

    }
    else if(pos == get_length(*head)){
        delete_end(head);
    }
    else{
        struct node * temp = (*head);

        while(pos--){
         temp = temp->next;
         
        }
        struct node * temp2 =temp->next;
        temp->next = temp2->next;
        temp->next->pre = temp;
        temp2->next = NULL;
        temp2->pre = NULL;
        free(temp2);

    }
}
void print_list(struct node *head){
    if(isempty(head)){
        printf("list is empty\n");
        return;
    }
    struct node * temp = head;
    while(temp){
        printf("%d > ",temp->data);

    }

};
int find_middle(struct node *head ){
    struct node *temp = head;
    int n = get_length(head)/2;
    for(int i = 0;i<n;i++){
        temp = temp->next;
    }
    return temp->data;

}
int main() {
    struct node *link = NULL;  // Initialize the head pointer to NULL
    while (1) {
        int choice;
        printf("Menu:\n1. Insert at front\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete front\n5. Delete end\n6. Delete at position\n7. Print list\n8. Find middle\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: insert_front(&link); break;
            case 2: insert_end(&link); break;
            case 3: insert(&link); break;
            case 4: delete_front(&link); break;
            case 5: delete_end(&link); break;
            case 6: {
                int pos;
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_node(&link, pos);
                break;
            }
            case 7: print_list(link); break;
            case 8: printf("Middle element: %d\n", find_middle(link)); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}


