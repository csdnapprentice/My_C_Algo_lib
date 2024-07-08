#include "myBinaryTree.h"
#include <stdlib.h>
#include <string.h>
#include "myArray.h"
#include "myQueue.h"
/*
 * Written by HengYuan Hu on April 27, 2024.
 * This function is used to traverse a binary tree and return a sequence representing the structure of the tree.
 * The time complexity depends on the number of nodes. It is O(n), where n is the number of nodes.
 */
void* myInOrderTraversal(struct TreeNode const * root, int* returnSize, size_t elementSize){
    if(root!=NULL){
        void* left = myInOrderTraversal(root->left, returnSize, elementSize);
        int leftLength = *returnSize;
        void* right = myInOrderTraversal(root->right, returnSize, elementSize);
        int rightLength = *returnSize;
        int num = leftLength + rightLength;
        void* answer = malloc(elementSize*(num+1));
        int k = 0;
        for (int i = 0; i < leftLength; i++) {
            memcpy(answer + k*elementSize, left + i*elementSize, elementSize);
            k++;
        }
        memcpy(answer+k*elementSize, root->val, elementSize);
        k++;
        for (int i = 0; i < rightLength; i++) {
            memcpy(answer + k*elementSize, right + i*elementSize, elementSize);
            k++;
        }
        free(left);
        free(right);
        left = NULL;
        right = NULL;
        *returnSize = num+1;
        return answer;
    }
    if(returnSize!=NULL) {
        *returnSize = 0;
    }
    return NULL;
}
/*
 * Written by HengYuan Hu on April 27, 2024.
 * This function is used to traverse a binary tree and return a sequence representing the structure of the tree.
 * The time complexity depends on the number of nodes. It is O(n), where n is the number of nodes.
 */
void* myPreOrderTraversal(struct TreeNode* root, int* returnSize, size_t elementSize){
    if(root!=NULL){
        void* left = myInOrderTraversal(root->left, returnSize, elementSize);
        int leftLength = *returnSize;
        void* right = myInOrderTraversal(root->right, returnSize, elementSize);
        int rightLength = *returnSize;
        int num = leftLength + rightLength;
        void* answer = malloc(elementSize*(num+1));
        int k = 0;
        memcpy(answer + k*elementSize, root->val, elementSize);
        k++;
        for (int i = 0; i < leftLength; i++) {
            memcpy(answer + k*elementSize, left + i*elementSize, elementSize);
            k++;
        }
        for (int i = 0; i < rightLength; i++) {
            memcpy(answer + k*elementSize, right + i*elementSize, elementSize);
            k++;
        }
        free(left);
        free(right);
        left = NULL;
        right = NULL;
        *returnSize = num+1;
        return answer;
    }
    *returnSize = 0;
    return NULL;
}
/*
 * Written by HengYuan Hu on April 27, 2024.
 * This function is used to traverse a binary tree and return a sequence representing the structure of the tree.
 * The time complexity depends on the number of nodes. It is O(n), where n is the number of nodes.
 */
void* myPostOrderTraversal(struct TreeNode* root, int* returnSize, size_t elementSize){
    if(root!=NULL){
        void* left = myInOrderTraversal(root->left, returnSize, elementSize);
        int leftLength = *returnSize;
        void* right = myInOrderTraversal(root->right, returnSize, elementSize);
        int rightLength = *returnSize;
        int num = leftLength + rightLength;
        void* answer = malloc(elementSize*(num+1));
        int k = 0;
        for (int i = 0; i < leftLength; i++) {
            memcpy(answer + k*elementSize, left + i*elementSize, elementSize);
            k++;
        }
        for (int i = 0; i < rightLength; i++) {
            memcpy(answer + k*elementSize, right + i*elementSize, elementSize);
            k++;
        }
        memcpy(answer+k*elementSize, root->val, elementSize);
        free(left);
        free(right);
        left = NULL;
        right = NULL;
        *returnSize = num+1;
        return answer;
    }
    *returnSize = 0;
    return NULL;
}
/*
 * Written by HengYuan Hu on April 28, 2024.Modify on May 6,2024
 * This function create a binary tree by an array, the array represent the binary tree's sequence traversal sequence
 * This function can let you init a binary tree very easy.
 */
int initBinaryTreeByArray(struct TreeNode* root, struct Array const *array, size_t elementSize){
    root->val = malloc(elementSize);
    if(root->val == NULL) {
        return 0;
    }
    memcpy(root->val, array->item[0], elementSize);
    struct Queue  q;
    myQueueInit(&q, array->length);
    myEnQueue(&q, (void *)root, elementSize, 0);
    int i = 1;
    while(i < array->length) {
        struct TreeNode * currentRoot = (struct TreeNode *)myDeQueue(&q);
        if(array->item[i] == NULL) {
            currentRoot->left = NULL;
        }else {
            currentRoot->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            if(currentRoot->left == NULL) {
                return 0;
            }
            currentRoot->left->val = malloc(elementSize);
            if(currentRoot->left->val == NULL) {
                return 0;
            }
            memcpy(currentRoot->left->val, array->item[i], elementSize);
            currentRoot->left->left = NULL;
            currentRoot->left->right = NULL;
            myEnQueue(&q, currentRoot->left, elementSize, 0);
        }
        i+=1;
        if(i<array->length) {
            if(array->item[i] == NULL) {
                currentRoot->right = NULL;
            }else {
                currentRoot->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                if(currentRoot->right == NULL) {
                    return 0;
                }
                currentRoot->right->val = malloc(elementSize);
                if(currentRoot->right->val == NULL) {
                    return 0;
                }
                memcpy(currentRoot->right->val, array->item[i], elementSize);
                currentRoot->right->left = NULL;
                currentRoot->right->right = NULL;
                myEnQueue(&q, currentRoot->right, elementSize, 0);
            }
        }else {
            currentRoot->right = NULL;
        }
        i+=1;
    }
    while(!myQueueEmpty(&q)) {
        struct TreeNode * currentRoot = (struct TreeNode *)myDeQueue(&q);
        currentRoot->left = NULL;
        currentRoot->right = NULL;
    }
    return 1;
}