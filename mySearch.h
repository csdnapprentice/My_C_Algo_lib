#ifndef MYSEARCH_H
#define MYSEARCH_H
struct Array;
int myBinarySearch(void const* item, struct Array const* a, int (*func)(void const*, void const*));
#endif //MYSEARCH_H
