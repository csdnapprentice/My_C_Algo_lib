#include "mySearch.h"
#include "myArray.h"
/*
 * Written by HengYuan Hu on May 9, 2024.
 */
int myBinarySearch(void const* item, struct Array const* a, int (*func)(void const*, void const*)) {
    int left = 0;
    int right = a->length-1;
    int middle = (left - right)/2 + right;
    while(left <= right) {
        int mark = func(item, a->item[middle]);
        switch(mark) {
            case 1: {
                left = middle + 1;
                middle = (left - right)/2 + right;
                break;
            }
            case 0: {
                return middle;
            }
            case -1: {
                right = middle - 1;
                middle = (left - right)/2 + right;
                break;
            }
            default: {
                break;
            }
        }
    }
    return -1;
}
