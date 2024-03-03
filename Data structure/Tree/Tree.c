#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    struct Tree *left;
    int info;
    struct Tree *right;
};
