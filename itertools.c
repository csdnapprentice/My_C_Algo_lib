#include "itertools.h"
#include <stdlib.h>
#include "myStack.h"
#include <string.h>
/*
 * Written by HengYuan Hu on April 26, 2024.
 * This function is used to find the maximum index that can be used in this array.
 * The time complexity depends on the length of the array, which is O(n), where n is the length of the array.
 */
int myMaxArrIndexValidate(int const * arrFlag, int size){
    int max = 0;
    for(int i=0; i<size; i++){
        if(arrFlag[i] == 1&&max<i){
            max = i;
        }
    }
    return max;
}
/*
 * Written by HengYuan Hu on April 26, 2024.
 * This function computes the permutation number. It can be used in certain situations.
 * This function is not suitable for situations where n is greater than 10.
 */
int myComputePermutationNumber(int maxSize, int size){
    if(maxSize <= 0|| maxSize<size || size < 0){
        return 0;
    }
    int ans = 1;
    for(int i=maxSize; i>maxSize - size; i--){
        ans *= i;
    }
    return ans;
}
/*
 * Written by HengYuan Hu on April 26, 2024.
 * This function is used to generate permutations.
 * The time complexity is O(n^n), which is very high.
 * Note that 'ans' is a pointer that points to a memory block.
 * Please remember to free it in the function that calls this function.
 */
void **myGeneratePermutations(int maxSize, int size, void const *arr, size_t elementSize, int *returnSize){
    int ansSize = myComputePermutationNumber(maxSize, size);
    *returnSize = ansSize;
    if(ansSize == 0||size == 0){
        return NULL;
    }
    void **ans = (void **)malloc(sizeof(void *)*ansSize);
    for(int i=0; i<ansSize; i++){
        ans[i] = malloc(elementSize*size);
    }
    int *arrFlag = (int *)malloc(sizeof(int)*maxSize);
    for(int i=0; i<maxSize; i++){
        arrFlag[i] = 1;
    }
    struct Stack s;
    myStackInit(&s, size);
    while (myStackLength(&s) != size) {
        int *num = (int *) malloc(sizeof(int));
        for (int j = 0; j < maxSize; j++) {
            if (arrFlag[j]) {
                arrFlag[j] = 0;
                *num = j;
                break;
            }
        }
        myStackPush(&s, (void *) num);
    }
    int start = 0;
    for(int i=0; i<ansSize; i++) {
        for(int j=0; j<size; j++){
            memcpy(ans[i]+elementSize*j,arr+(*((int *)s.item[j]))*elementSize, elementSize);
        }
        void *p = myStackPop(&s);
        arrFlag[*(int *)p] = 1;
        start = *(int *)p;
        free(p);
        while(start == myMaxArrIndexValidate(arrFlag, maxSize)&& myStackLength(&s)!=0){
            p = myStackPop(&s);
            arrFlag[*(int *)p] = 1;
            start = *(int *)p;
            free(p);
        }
        while (myStackLength(&s) != size) {
            int *num = (int *) malloc(sizeof(int));
            for (int j = start + 1; j < maxSize; j++) {
                if (arrFlag[j]) {
                    arrFlag[j] = 0;
                    *num = j;
                    break;
                }
            }
            myStackPush(&s, (void *) num);
            if (myStackLength(&s) != size) {
                start = -1;
            }
        }
    }
    free(arrFlag);
    return ans;
}
/*
 * Written by HengYuan Hu on April 26, 2024.
 * This function is used to compute the combination number.
 * It is not suitable for situations where n is greater than 10, similar to the function used to compute permutation numbers.
 */
int myComputeCombinationNumber(int maxSize, int size){
    if(maxSize <= 0|| maxSize<size || size < 0){
        return 0;
    }
    int ans = 1;
    for(int i=maxSize; i>maxSize - size; i--){
        ans *= i;
    }
    int frac = 1;
    for(int i=1; i<=size; i++){
        frac *= i;
    }
    return ans/frac;
}
/*
 * Written by HengYuan Hu on April 26, 2024.
 * This function can generate combinations according to the given array.
 * The time complexity depends on the length of array, which is O(n), where n is the length of the array.
 */
void **myGenerateCombinations(int maxSize, int size, void const *arr, size_t elementSize, int *returnSize){
    int ansSize = myComputeCombinationNumber(maxSize, size);
    *returnSize = ansSize;
    if(ansSize == 0||size == 0){
        return NULL;
    }
    void **ans = (void **)malloc(sizeof(void *)*ansSize);
    for(int i=0; i<ansSize; i++){
        ans[i] = malloc(elementSize*size);
    }
    int *arrFlag = (int *)malloc(sizeof(int)*maxSize);
    for(int i=0; i<maxSize; i++){
        arrFlag[i] = 1;
    }
    struct Stack s;
    myStackInit(&s, size);
    while (myStackLength(&s) != size) {
        int *num = (int *) malloc(sizeof(int));
        for (int j = s.top; j < maxSize; j++) {
            if (arrFlag[j]) {
                arrFlag[j] = 0;
                *num = j;
                break;
            }
        }
        myStackPush(&s, (void *) num);
    }
    int start = 0;
    for(int i=0; i<ansSize; i++) {
        for(int j=0; j<size; j++){
            memcpy(ans[i]+elementSize*j,arr+(*((int *)s.item[j]))*elementSize, elementSize);
        }
        void *p = myStackPop(&s);
        arrFlag[*(int *)p] = 1;
        start = *(int *)p;
        free(p);
        while(start == maxSize - (size - s.top)&& myStackLength(&s)!=0){
            p = myStackPop(&s);
            arrFlag[*(int *)p] = 1;
            start = *(int *)p;
            free(p);
        }
        while (myStackLength(&s) != size) {
            int *num = (int *) malloc(sizeof(int));
            for (int j = start+1; j < maxSize; j++) {
                if (arrFlag[j]) {
                    arrFlag[j] = 0;
                    *num = j;
                    break;
                }
            }
            myStackPush(&s, (void *) num);
            if (myStackLength(&s) != size) {
                start = start + 1;
            }
        }
    }
    free(arrFlag);
    return ans;
}
