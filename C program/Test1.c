#include<stdio.h>
int main(){
    int i;
    printf("Enter your number(0 for stop) : ");
    scanf("%d",&i);
    while (i != 0 )
    {
        printf("%d",i);
        scanf("%d",&i);
    }
}