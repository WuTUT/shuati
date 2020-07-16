#include <stdio.h>
#include <stdlib.h>
//使用指针作为函数的参数，指针没有被重新赋值的情况下，指针指向的值一定是会被同步更改的，但是如果指针作为一个变量，本身的值发生更改，那么参数源是不会发生改变的。
void func(int **p)
{
    *p = (int *)malloc(sizeof(int));
    **p = 10;
}
void func1(int *p) //a copy of pointer p in stack
{
    p = (int *)malloc(sizeof(int)); //change the copy of p but not p ,memory leak
    *p = 10;
}
void func_free(int **p)
{
    free(*p);
    *p = NULL;

    return;
}
void func_free1(int *p)
{
    free(p);
    //still wrong, p = NULL is ineffective
    return;
}
int main()
{
    int *a, b = 3;
    // *a = b; //compile ok ,but segmentation fault
    // printf("%d", *a);

    int *p = NULL;
    func(&p);
    func1(p);
    printf("%d", *p);
    return 0;
}
