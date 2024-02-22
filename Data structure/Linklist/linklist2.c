  #include<stdio.h>
  #include<stdlib.h>
  struct node{
    int DATA;
    struct node *LINK;
  };
  int main(){
    struct node *node1 = malloc(sizeof(struct node));
    struct node *node2 = malloc(sizeof(struct node));
    struct node *node3 = malloc(sizeof(struct node));
    node1 -> DATA = 5;
    node2 -> DATA = 10;
    node3 -> DATA = 15;
    node3 -> LINK = NULL;
    printf("Data of node1 : %d\n",node1->DATA);
    struct node *HEAD;
    node1->LINK = node2;
    node2->LINK = node3;
    HEAD = node1;
    struct node *temp = malloc(sizeof(struct node));
    temp = HEAD;
    printf("Data of each node : ");
    
    while(temp != NULL){
        printf("%d\n",temp->DATA);
        temp = temp -> LINK;
    }
  }