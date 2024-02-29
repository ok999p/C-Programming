#include <stdio.h>
#include <stdlib.h>

typedef struct Anumber *number;
struct Anumber
{
    int number;
    number next;
};

typedef struct Div7number *Divnumber;
struct Div7number
{
    int divnumber;
    Divnumber next;
};


number createlist(number link){
    number newnode;
    int i;
    printf("Enter your number(0 for stop) : ");
    scanf("%d",&i);
    while (i != 0 )
    {
        newnode = (number)malloc(sizeof(struct Anumber));
        newnode->number = i;
        newnode->next = link;
        link = newnode;
        scanf("%d",&i);
    }
    return link;
}

Divnumber createdivlist(Divnumber link, number list){
    Divnumber newnode;
    number temp = list;

    while(temp != NULL){
        if(temp->number%7==0){
            newnode = (Divnumber)malloc(sizeof(struct Div7number));
            newnode->divnumber = temp->number;
            newnode->next = link;
            link = newnode;
        }
        temp = temp->next;
    }
    return link;
}


void display(number link){
    number temp = link;
    printf("\n");
    while (temp != NULL){
        printf("%d ", temp->number);
        temp = temp->next;
    }
}


void displaydiv7(Divnumber link){
    Divnumber temp = link;
    printf("\n");
    while (temp != NULL){
        printf("%d ", temp->divnumber);
        temp = temp->next;
    }
}

int main(){
    printf("Test1\n");
    number give = NULL;
    printf("Test2\n");
    // Divnumber give2;
    // give2 = NULL;
    give = createlist(give);
    // give2 = createdivlist(give2,give);
    display(give);
    // displaydiv7(give2);
}