#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int w;
    int y;
    // char z;
    //double x;
    int x;
    // printf("%p %p %p %p\n", &w, &y, &z, &x);
    printf("%p %p %p\n", &w, &y, &x);
    int a[4];
    int b[4];
    for (int i = 0;i < 4;i++) {
        printf("%p ", &a[i]);
    }
    printf("\n");
    for (int i = 0;i < 4;i++) {
        printf("%p ", &b[i]);
    }
    return 0;
}