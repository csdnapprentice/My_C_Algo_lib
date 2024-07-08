#ifndef STRING_MYSTRING_H
#define STRING_MYSTRING_H

void myStringCatch(const char *s1, const char *s2, int *returnSize, char ** result);
void intToChar(int num, int *returnSize, char ** result);
void summaryRanges(const int* nums, int numsSize, int* returnSize, char ***result);
char *myStringCopy(char const *s);
void myStringRemoveSubSequence(char *s, char const *c);
int myStringLength(char const* s);
#endif //STRING_MYSTRING_H
