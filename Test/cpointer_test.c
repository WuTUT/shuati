#include <stdio.h>
int main(){
    int *a , b=3;
    *a = b;//compile ok ,but segmentation fault
    printf("%d",*a);
    return 0;
}