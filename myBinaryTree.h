#ifndef LEETCODE_MYBINARYTREE_H
#define LEETCODE_MYBINARYTREE_H
#include <stddef.h>

struct TreeNode{
    void *val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct Array;
void* myInOrderTraversal(struct TreeNode const * root, int* returnSize, size_t elementSize);
void* myPreOrderTraversal(struct TreeNode* root, int* returnSize, size_t elementSize);
void* myPostOrderTraversal(struct TreeNode* root, int* returnSize, size_t elementSize);
int initBinaryTreeByArray(struct TreeNode* root, struct Array const *array, size_t elementSize);
#endif //LEETCODE_MYBINARYTREE_H
