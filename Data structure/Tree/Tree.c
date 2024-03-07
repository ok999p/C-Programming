#include <stdio.h>
#include <stdlib.h>

struct tree
{
    struct tree *left;
    int info;
    struct tree *right;
};

struct tree* roottree (int data);
struct tree* insert(struct tree* node , int data);
void print(struct tree *root_node);


int main(){
    struct tree *root_node = NULL;
    root_node = insert(root_node ,10);
    insert(root_node , 10);
    insert(root_node , 30);
    insert(root_node , 25);
    insert(root_node , 36);
    insert(root_node , 56);
    insert(root_node , 78);
    print(root_node);
}

void print(struct tree *root_node) {
    if(root_node != NULL){
        print(root_node -> left);
        printf("%d\n",root_node -> info);
        print(root_node -> right);        
    }
}

struct tree *roottree (int data) {
    struct tree *node = (struct tree*)malloc(sizeof (struct tree));
    node ->info = data;
    node ->left = NULL;
    node ->right = NULL;
    return node;
}

struct tree* insert(struct tree *node , int data) {
    if(node == NULL) return roottree(data);
    if(data < node ->info){
        node -> left = insert(node -> left , data);
    }else if(data > node -> info){
        node -> right = insert(node -> right , data);
    }
    return node;
}


