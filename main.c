#include <stdio.h>
#include "myArray.h"
#include "mySearch.h"

struct myPoint {
    int x;
    int y;
};
struct String {
    char str[100];
};
int func(void const *a, void const *b) {
    if(*(int *)a == *(int *)b) {
        return 0;
    }else if(*(int *)a<*(int *)b) {
        return 1;
    }
    return -1;
}
union number{
    int x;
    char z[4];
};
int main(void){
    // struct Array a;
    // printf("initArray(a,100)return:%d\n", initArray(&a,100));
    // printf("the max length of the array is %d\n", a.maxLength);
    // printf("the length of the array is %d now\n", a.length);
    // struct myPoint p1={0,1};
    // insertItem(&a,0,&p1,sizeof(struct myPoint));
    // printf("this element is (%d, %d)\n", ((struct myPoint*)a.item[0])->x, ((struct myPoint*)a.item[0])->y);
    // printf("the length of the array is %d now\n", a.length);
    // struct String str={"hello kity"};
    // insertItem(&a,1000,&str, sizeof(struct String));
    // printf("this element is (%d, %d)\n", ((struct myPoint*)a.item[0])->x, ((struct myPoint*)a.item[0])->y);
    // printf("this element is string:%s\n", ((struct String *)a.item[1])->str);
    // printf("the length of the array is %d now\n", a.length);
    // deleteItem(&a,1);
    // printf("this element is (%d, %d)\n", ((struct myPoint*)a.item[0])->x, ((struct myPoint*)a.item[0])->y);
    // //printf("this element is string:%s\n", ((struct String *)a.item[0])->str);
    // printf("the length of the array is %d now\n", a.length);
    // if(deleteItem(&a,0)) {
    //     printf("the length of the array is %d now\n", a.length);
    // }
    // if(deleteItem(&a,0)) {
    //     printf("the length of the array is %d now\n", a.length);
    // }else{
    //     printf("delete error!!!because the length of the array is %d now\n", a.length);
    // }
    // struct Array a;
    // initArray(&a, 100);
    // for(int i=0; i<10; i++) {
    //     insertItem(&a,0, &i, sizeof(i));
    // }
    // for(int i=0; i<100; i++) {
    //     printf("index = %d\n", myBinarySearch(&i, &a, func));
    // }
    union number n;
    n.z[0] = 'x';
    n.z[1] = 'y';
    n.z[2] = 'z';
    n.z[3] = '\0';
    printf("%d %d %x\n", &n.x, sizeof(n.x), n.x);
    printf("%d %d %x %x %x\n", &n.z, sizeof(n.z), n.z[0], n.z[1], n.z[2]);
    return 0;
}
