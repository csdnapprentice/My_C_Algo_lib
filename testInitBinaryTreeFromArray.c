#include "myArray.h"
#include "myBinaryTree.h"
#include <stdio.h>
int main() {
    struct Array a;
    initArray(&a, 100);
    int x[100];
    for(int i = 0; i<7; i++) {
        x[i] = i;
        insertItem(&a, 0, (void *)&x[i], sizeof(int));
    }
    struct TreeNode root;
    initBinaryTreeByArray(&root, &a, sizeof(int));
    int returnSize = 0;
    int* b = (int *)myInOrderTraversal(&root, &returnSize, sizeof(int));
    int* c = (int *)myPostOrderTraversal(&root, &returnSize, sizeof(int));
    int* d = (int *)myPreOrderTraversal(&root, &returnSize, sizeof(int));
    printf("this is binary tree's InOrderTraversal!!!\n");
    for(int i=0; i<returnSize; i++) {
        printf("%d\n", *(b+i));
    }
    printf("this is binary tree's PostOrderTraversal!!!\n");
    for(int i=0; i<returnSize; i++) {
        printf("%d\n", *(c+i));
    }
    printf("this is binary tree's PreOrderTraversal!!!\n");
    for(int i=0; i<returnSize; i++) {
        printf("%d\n", *(d+i));
    }
    return 0;
}