#include "myArray.h"
#include <stdlib.h>
#include <string.h>
/*
 * Written by HengYuan HU on the eighteenth of April 2024.
 * this function can obtain an array's length. Sometimes will be useful.
 * the Time complexity is O(1),this is indicates that the function can finish in the const time.
 *
 * ----------Comment was modified by ChatGpt----------
 *
 * Written by HengYuan HU on the eighteenth of April 2024.
 * This function can obtain the length of an array, which can be useful at times.
 * The time complexity is O(1), indicating that the function can finish in constant time.
*/
int arrayLength(int size, int type_size){
    int length = size / type_size;
    return length;
}
/*
 * Written by HengYuan Hu on April 24, 2024.
 * This function can init the array.if init is successful then return 1, otherwise return 0.
 */
int initArray(struct Array *a, int maxSize){
    a->item = (void **)malloc(sizeof(void *)*maxSize);
    if(a->item==NULL){
        return 0;
    }
    a->maxLength = maxSize;
    a->length = 0;
    for(int i = 0; i < a->maxLength; i++){
        a->item[i] = NULL;
    }
    return 1;
}
/*
/* Written by HengYuan Hu on May 2, 2024.
 * This function inserts an element into the array.
 * If the index is greater than the current maximum index of the array,
 * the element will be inserted at the tail of the array.
 * the time complexity is O(n), that n is the length of the array.
 */
int insertItem(struct Array *a, int index, void const * element, size_t elementSize){
    if(index<0) {
        index = 0;
    }
    if(a->length < a->maxLength) {
        if(index < a->length) {
            for(int i=a->length; i>index; i--) {
                a->item[i] = a->item[i-1];
            }
            void * a_element = malloc(elementSize);
            memcpy(a_element, element, elementSize);
            a->item[index] = a_element;
        }else {
            void * a_element = malloc(elementSize);
            memcpy(a_element, element, elementSize);
            a->item[a->length] = a_element;
        }
        a->length++;
        return 1;
    }
    return 0;
}
int deleteItem(struct Array *a, int index){
    if(index >= a->length|| index<0) {
        return 0;
    }
    if(a->length>=1) {
        free(a->item[index]);
        for(int i=index; i<a->length-1; i++) {
            a->item[i] = a->item[i+1];
        }
        a->item[a->length-1] = NULL;
        a->length--;
        return 1;
    }
    return 0;
}