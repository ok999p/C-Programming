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
int delete(struct tree** root, int data);
struct tree* findmin(struct tree* root);

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
    printf("\n");
    delete(&root_node, 30);
    print(root_node);
}

void print(struct tree *root_node) {
    if(root_node != NULL){
        print(root_node -> left);
        printf("%d ",root_node -> info);
        print(root_node -> right);        
    }
}

struct tree* roottree (int data) {
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

struct tree* findmin(struct tree* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

int delete(struct tree** root, int data) {
    if ((*root) == NULL) return 0;
    if ((*root)->info == data) {
        // printf("%d", data);
        if ((*root)->right == NULL && (*root)->left == NULL) {
            free(*root);
            *root = NULL;
            return 1;
        }
        if ((*root)->left == NULL) {
            struct tree* temp = *root;
            (*root) = (*root)->right;
            return 1;
        }
        if ((*root)->right == NULL) {
            struct tree* temp = *root;
            (*root) = (*root)->left;
            return 1;
        }
        struct tree* temp = findmin((*root)->right);
        (*root)->info = temp->info;
        delete(&(*root)->right, temp->info);
    }
    if (delete(&(*root)->right, data) || delete(&(*root)->right, data)) {
        return 1;
    }
    return 0;
}