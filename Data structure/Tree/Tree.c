#include <stdio.h>
#include <stdlib.h>

struct tree
{
    struct tree *left;
    int info;
    struct tree *right;
};


struct tree *treenode (int data) {
    struct tree *node = (struct tree*)malloc(sizeof (struct tree));
    if(node != NULL){
    node ->info = data;
    node ->left = NULL;
    node ->right = NULL;
    }
}


int main(){
    struct tree *root = treenode(1);
}

