#include<stdio.h>
int findmax(int n,int arr[][n]){
    int maxrow = -1;
   int i = 0;
   int j = n-1;
   while(j >=0 && i <n){
        if(arr[i][j] == 1){
                maxrow = 1;
                j--;

        }
        else{
            i++;
        }

   }
   return i;
}



int main(){
int arr[3][3];
printf("enter elements:");
for(int i = 0;i<3;i++){
for(int j = 0;j<3;j++){
   scanf("%d",&arr[i][j]);

}
}
int maxrow = findmax(3,arr);
printf("%d",maxrow+1);


return 0;}
