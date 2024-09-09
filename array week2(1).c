#include<stdio.h>
#include <stdbool.h>
bool bs(int n,int arr[][n],int i,int key){
    int s = 0;
    int e = n-1;

    while(s<e){
        int mid = s + (e-s)/2;
        if(arr[mid][i] == key){
            return true;
        }
        else if(arr[mid][i] > key){
            e = mid-1;

        }
        else{
            s = mid+1;
        }
    }
    return true;
}


bool find(int n,int arr[][n],int key){
    for(int i = 0;i<n;i++){
        if(arr[0][i] < key && arr[n-1][i] > key){
        return bs(n,arr,i,key);
        
    }
    return false;
}
}
int main(){
    int n;
    printf("engter size:\n");
    scanf("%d",&n);
    int arr[n][n];
    for(int i = 0 ;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int key;
    printf("enter key to check:\n");
    scanf("%d",&key); 
    bool ans  = find(n,arr,key);
    if(ans){
        printf("value is presnet ");

    }
    else{
        printf("value is not present");
    }
    return 0;   
}