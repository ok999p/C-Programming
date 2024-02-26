# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

struct StackNode {
    int data;
    struct StackNode* next;
    struct StackNode* nextnode;
};

struct StackNode* Newnode(int data) {
    struct StackNode* stacknode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stacknode->data = data;
    stacknode->next = NULL;
    return stacknode;
};

int stacknextnode() {
    struct StackNode* tempstack = NULL;
    tempstack->nextnode;
    return tempstack;
}



int IsEmpty(struct StackNode* root) {
    return !root;
}

int push(struct StackNode** root, int data) {
    struct StackNode* stack = Newnode(data);
    stack->next = *root;
    *root = stack;
    printf("Push->%d\n", data);
}

int peek(struct StackNode* root) {
    if (IsEmpty(root)) return INT_MIN;
    return root->data;
}

int pop(struct StackNode** root) {
    if (IsEmpty(*root)) return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int main() {
    struct StackNode* root = NULL;
    printf("Pop->%d\n", pop(&root));
    printf("Peek->%d\n", peek(root));
    push(&root, 10);
    push(&root, 30);
    printf("pop->%d\n", pop(&root));
    printf("Peek->%d\n", peek(root));
    push(&root, 20);
    printf("Peek->%d\n", peek(root));
}