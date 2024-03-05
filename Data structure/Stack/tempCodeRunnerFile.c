# include <stdio.h>
# include <stdlib.h>

struct stacknode{
    int data;
    struct stacknode* link;
}*new, *head, *temp;

unsigned capacity = 0;
int size = 0;

void create(int data) {
    new = malloc(sizeof(struct stacknode));
    new->data = data;
    new->link = NULL;
    if (head == NULL) {
        head = new;
    }
    else 
    {
        new->link = head;
    }
    head = new;
}

void push() {
    int data;
	if (capacity != size) {
        printf("Data: ");
        scanf("%d", &data);
        create(data);
        size++;
    }
}

void pop() {

}

int peek() {
    printf("%d", head->data);
    
}

int isEmpty() {
    
}

int main() {
    int n, a;
    printf("Enter capacity: ");
    scanf("%d", &n);
    unsigned capacity = n;
    while(1) {
        printf("4");
        switch (a)
        {
        case 1:
            push();
            break;
        case 2:
            peek();
        default:
            break;
        }
    }
}