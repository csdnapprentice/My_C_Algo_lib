#include "myMath.h"
#include <stdlib.h>
/*
 * Written by HengYuan Hu on April 26, 2024.
 * This function can add two big numbers and return the result.
 * The time complexity depends on the length of the numbers.
 * It is O(n), where n is the length of the numbers.
 */
int* positiveBigNumberAdd(int const *arr1, int const* arr2, int arr1Size, int arr2Size, int radix, int *returnSize){
    int size1 = arr1Size>arr2Size?arr1Size:arr2Size;
    int size2 = arr1Size+arr2Size-size1;
    int *ans = (int *)malloc(sizeof(int)*(size1+1));
    for(int i=size1-1,j=size2-1; i>=0&&j>=0; i--, j--){
        ans[i+1] = arr1[i] + arr2[j];
    }
    ans[0] = 0;
    for(int i=size1; i>=0; i--){
        if(ans[i]>=radix){
            ans[i-1] += ans[i]/radix;
            ans[i] = ans[i]%radix;
        }
    }
    *returnSize = size1+1;
    if(ans[0] == 0){
        for(int i=0; i<size1; i++){
            ans[i] = ans[i+1];
        }
        *returnSize = size1;
    }
    return ans;
}
/*
 * Written by HengYuan Hu on April 28, 2024.
 * This function can effective to obtain the sqrt root of a number.
 */
double mySqrt(double x){
    int count = 0;
    double y=1;
    while(count!=20)
    {
        y=(y+x/y)*0.5;
        count++;
    }
    return y;
}