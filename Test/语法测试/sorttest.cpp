#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int n = 125;
int a[n];
bool cmp(int x1, int x2) {
    return x1 >= x2;//sometimes runtime error
    // return true; //always runtime error
}
int main() {
    for (int i = 10;i < n;i++) {
        a[i] = 2;
    }
    sort(a, a + n, cmp);
    for (int i = 0;i < 10;i++) {
        printf("%d ", a[i]);
    }
    return 0;
}