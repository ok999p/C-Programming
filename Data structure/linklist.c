#include <stdio.h>
#include <stdlib.h>
int main(){
    struct node {
        int DATA;
        struct node *LINK;
    };
    struct node *new = malloc(sizeof(struct node));
    struct node *head = malloc(sizeof(struct node));
    new->DATA = 50;
    new->LINK = NULL;
    printf("%d\n",new->DATA);
    head = new;
    head->DATA = 100;
    
    printf("Data of head node %d\n",new->DATA);
    printf("Memory address that head point to %p\n",head);
    printf("Memory address that new point to %p\n",new);
    free(head);
    free(new);
}




