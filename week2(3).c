#include<stdio.h>
#include<stdlib.h>
void clock(int n,int arr[][n]){
    int srow = 0;
    int erow = n-1;
    int scol = 0;
    int ecol = n-1;
    int cur;
    int pre = arr[1][0];
    while(srow <erow && scol <ecol)
{
     for(int i = scol;i<=ecol;i++){
         cur = arr[srow][i];
         arr[srow][i] = pre;
         pre = cur;
     }
     srow++;
     for(int i = srow;i<=erow;i++){
         cur = arr[i][ecol];
         arr[i][ecol] = pre;
         pre = cur;
     }
     ecol--;
     for(int i = ecol;i>=scol;i--){
         cur = arr[erow][i];
         arr[erow][i] = pre;
         pre = cur;
     }
     erow--;
     for(int i = erow;i>=srow;i--){
         cur = arr[i][scol];
         arr[i][scol] = pre;
         pre = cur;
     }
     srow++;

}
printf("matrix rotated clockwise:\n");
for(int i = 0;i<4;i++){
    for(int j =0;j<4;j++){
        printf("%d ",arr[i][j]);

    }
    printf("\n");
}
printf("");
}
int main(){
int arr[4][4] = { {11,12,13,14},
                   {15,16,17,18},
                   {19,20,21,22},
                   {23,24,25,26}
              };
clock(4,arr);


    return 0;

}
