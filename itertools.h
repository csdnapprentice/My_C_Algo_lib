#ifndef LEETCODE_ITERTOOLS_H
#define LEETCODE_ITERTOOLS_H
#include <stddef.h>
int myMaxArrIndexValidate(int const * arrFlag, int size);
int myComputePermutationNumber(int maxSize, int size);
void **myGeneratePermutations(int maxSize, int size, void const *arr, size_t elementSize, int *returnSize);
int myComputeCombinationNumber(int maxSize, int size);
void **myGenerateCombinations(int maxSize, int size, void const *arr, size_t elementSize, int *returnSize);
#endif //LEETCODE_ITERTOOLS_H
