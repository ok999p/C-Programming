#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// ให้มันรู้จักฟังชั่นก่อน
void create_node();
void traverse();
void delete_node();

struct node{
    int DATA;
    struct node *LINK;
}*HEAD, *NEW, *temp;   
// ประกาศตัวแปร HEAD, NEW, temp ให้เป็น pointer ชนิดข้อมูล struct node

int main(){
    int ans;
    char ch[1];
    printf("test\n");
    HEAD = NULL;
    do{
        printf("******************");
        printf("Singly Linked List: ");
        printf("******************\n");
        printf("1.Creating node\n2.Traversing the list\n3.Deleteing node");
        printf("\n**********************************************\n");
        printf("Enter your choice: ");
        scanf("%d",&ans);
        switch(ans){
            case 1:
            create_node();
            break;
            case 2:
            traverse();
            break;
            case 3:
            delete_node();
            break;
            default: printf("\nEnter correct choice");
        }
        printf("\nContinue [Y/N] : ");
        scanf("%s",ch);
    }while(ch[0] == 'y' || ch[0] == 'Y');
    printf("Exit from the program");
}

void create_node() {
    bool success = false;
    NEW = malloc(sizeof(struct node));

    printf("\n -------- Insertion ----------");
    printf("\nEnter new data: ");
    scanf("%d" ,&NEW->DATA);

    NEW->LINK = NULL;

    if (HEAD == NULL){
        HEAD = NEW;
        success = true;
    } else {
        temp = HEAD;
        while(temp->LINK != NULL){
            temp = temp->LINK;
        }
        temp->LINK = NEW;
        success = true;
    }
    if(success)
        printf("Insertion is completed");
    else
    printf("Insertion is not completed");
}

void traverse() {
    temp = HEAD;
    if(HEAD == NULL){
        printf("List is empty");
        return;
    }
    while(temp != NULL){
    printf("%d",temp->DATA);
    temp = temp->LINK;
    }
}

void delete_node(){
    int data;
    struct node *ptemp;
    bool success = false;

    printf("\n ----------Deletion ----------\n");
    printf("Enter data to delete: ");
    scanf("%d",&data);


    // Find the node to delete
    temp = HEAD;
    ptemp = NULL    ;
    while (temp != NULL){
        if(temp->DATA != data){
            ptemp = temp;
            temp = temp->LINK;
            }
        else {
            break;
        }
    }
    
if (temp == NULL) {
    printf("Node with data %d not found\n", data);
    return;
}

if (ptemp == NULL) {
    HEAD = temp->LINK;
} else {
    ptemp->LINK = temp->LINK;
}

free(temp);
success = true;
}