#include<stdio.h>
#include<stdlib.h>
int find(int n,int arr[][n],int key){
int i = 0;
int j = n-1;
while(j >=0 && i <n){
    if(arr[i][j] == key){
        return 1;
    }
    else if(arr[i][j]>key){
        j--;
    }
    else{
        i++;

    }
}
return -1;
}
int main(){
int arr[4][4];
for(int i = 0;i<4;i++){
    for(int j = 0;j<4;j++){
        scanf("%d",&arr[i][j])
    }
}
 int ans = find(4,arr,key);
 if(ans == -1){
    printf("value not found:\n");

 }
 else{
    printf("value found");

 }
return 0;
}
