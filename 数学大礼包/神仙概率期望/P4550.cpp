#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    double f = 0, g = 0;
    for (int i = n - 1;i >= 0;i--) {
        double tmp = f;
        f = f + n * 1.0 / (n - i);
        g = n * 1.0 / (n - i) + i * 1.0 / (n - i) * f + g + tmp;
    }
    printf("%.2lf", g);
    return 0;
}