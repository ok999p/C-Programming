#include<stdio.h>
#include<stdlib.h>

struct StackAss{
    int data;
    struct StackAss *link;
}*head, *new, *temp;

void push(int num) {
    new = malloc(sizeof(struct StackAss));
    new -> data = num;
    new -> link = head;
    head = new;
}

void pop() {
    if(head == NULL){
        printf("This stack is empty\n");
    }else 
    temp = head;
    head = head->link;
    free(temp);
    printf("Delete Completed");
}

void display(){
    if(head == NULL){
        printf("This stack is empty\n");
    }
    temp = head;
    while(temp!=NULL){
        printf("%d\n",temp ->data);
        temp = temp->link;
    }
}

void peek() {
    if(head == NULL){
        printf("This stack is empty\n");
    }else
    printf("%d",head -> data);
}


int main() {
    int number,ans,count,time = 0;
    char ch[1];
    head = NULL;
    printf("How many times do you want to stacked : ");
    scanf("%d",&count);
    do{
        printf("\n>>>>>>>>>>>LIST<<<<<<<<<<<\n");
        printf("1. Add number in stact\n2. Del number in stack\n3. Display stack\n4.Peek Number \n5. Enter 5 to stop program");
        printf("\n>>>>>>>>>>>LIST<<<<<<<<<<<\n\n");
        printf("Enter your choise : ");
        scanf("%d",&ans);
        switch (ans)
        {
        case 1:
                if(time < count){
                printf("What number do you want to input to stack : ");
                scanf("%d",&number);
                push(number);
                time++;
                    }else 
                printf("Stack is fulll");
            break;
          case 2:
            pop();
            break;          
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("Exit program");
            break;
        default: printf("Plese Enter 1-4");
            break;
        }
    }while(ans != 4);
}