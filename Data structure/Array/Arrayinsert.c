#include<stdio.h>
int main(){
    int P,a;
    int arr[10] = {40,84,50,21,14,77};
    printf("What position do you want to insert: ");
    scanf("%d",&P);
    for(int i = P-1; i > 10; i--){
        arr[i + 1] = arr[i];
    }
    arr[P] = 60;
    for(int i = 0; i < 9; i++){
        printf("%d ",arr[i]);
    }
}