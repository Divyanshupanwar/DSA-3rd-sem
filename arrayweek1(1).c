#include<stdio.h>
void reverse(int arr[],int s,int e){

    while(s<=e){
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }

}
void leftrotate(int arr[],int n,int k){
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
    printf("rotated array successfully:\n");
    

}

int main(){
    int n,k;
    printf("enter size:\n");
    scanf("%d",&n);
    printf("enter k:\n");

    scanf("%d",&k);

    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    leftrotate(arr,n,k);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
        
    }
    return 0;
    
}