#include<stdio.h>
int main(){
    int P,size=0,count=0;
    scanf("%d",&size);
    int arr[size];
    while (count<size)
    {
        printf("Input number : ");
        scanf("%d",&arr[count]);
        count++;
    }
    
    printf("What position do you want to delete: ");
    scanf("%d",&P);
    for(int i = P-1; i < size; i++){
        arr[i] = arr[i+1];
    }
    size--;
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
}