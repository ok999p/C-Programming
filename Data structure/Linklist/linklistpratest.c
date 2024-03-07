#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
}*head, *temp, *new, *ptemp;

void createnode();
void printdata();
void delete();
int main(){
    int ans;
    head = NULL;
    do
    {
        printf("****************************");
        printf("\n1.create node\n2.print data\n3.delete node\n4.insert node\n");
        printf("****************************");
        printf("\n=>");
        scanf("%d",&ans);
        switch (ans)
        {
        case 1:
        createnode();
            break;
        case 2:
        printdata();
            break;
        case 3:
        delete();
        break;
        default: printf("Enter 1-4");
            break;
        };
    } while (ans != 4);
    
}


void createnode(){
    int number;
    printf("Data : ");
    scanf("%d",&number);
    new = malloc(sizeof(struct node));
    new -> num = number;
    new -> next = head;
    head = new;
}

void printdata(){
    temp = head;
    while(temp != NULL){
        printf("%d\n",temp -> num);
        temp = temp -> next;
    }
}

void delete() {
    int data;
    temp = head;
    ptemp = NULL;
    printf("What data do you want to delete");
    scanf("%d",&data);
    while (temp != NULL){
        if(temp -> num == data){
            ptemp = temp;
            temp = temp -> next;
        }else
        break;
    }
    if(ptemp == head){
        head = temp ->next;  
    }else
    ptemp -> next = temp -> next;
    free(temp);
}