#include <stdio.h>
#include <stdlib.h>

struct tree{
    struct tree *left;
    int info;
    struct tree *right;
};

struct tree* createroot(int data);
struct tree* insert(struct tree* root_node, int data);
void print(struct tree* root_node);


struct tree* createroot(int data){
    struct tree* node = (struct tree*)malloc(sizeof(struct tree));
    node -> info = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

struct tree* insert(struct tree* root_node, int data){
    if(root_node == NULL){
        return createroot(data);
    }if(data > root_node -> info){
        root_node -> right = insert(root_node -> right, data);
    }else if(data < root_node -> info){
        root_node -> left = insert(root_node -> left, data);
    }
    return root_node;
}

void print(struct tree* root_node){
    if(root_node != NULL){
    print(root_node -> left);
    printf("%d\n",root_node -> info);
    print(root_node -> right);
    }
}

int main(){
    struct tree* roottree = NULL;
    roottree = insert(roottree, 30);
    print(roottree);
}