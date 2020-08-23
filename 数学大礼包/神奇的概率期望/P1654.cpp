#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;

int main() {

    int n;
    scanf("%d", &n);

    long double len = 0.0;
    long double len2 = 0.0;
    long double f = 0.0;
    double p;
    for (int i = 1;i <= n;i++) {
        scanf("%lf", &p);
        f = f + p * (len2 * 3.0 + len * 3 * 1.0 + 1.0);
        long double tmp = len;
        len = p * (len + 1.0);
        len2 = (len2 + 2.0 * tmp + 1) * p;

    }
    printf("%.1Lf\n", f);
    return 0;
}