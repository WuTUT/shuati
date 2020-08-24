#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 3e5 + 5;
char s[maxn];
long double f = 0.0;
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    scanf(" %s", s);
    long double len = 0.0;

    for (int i = 1;i <= n;i++) {
        if (s[i - 1] == 'o') {
            f = f + 2.0 * len + 1.0, len = len + 1.0;
        }
        else if (s[i - 1] == 'x') {
            f = f, len = 0.0;
        }
        else {
            f = f + len + 0.5, len = (len + 1) / 2.0;
        }
    }
    printf("%.4Lf\n", f);
    return 0;
}