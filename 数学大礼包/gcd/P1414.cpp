#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 10005, maxm = 1e6 + 5;
int a[maxn], f[maxm], g;
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        g = max(g, a[i]);
        for (int j = 1;j <= floor(sqrt(a[i]) + 0.5);j++) {
            if (a[i] % j == 0) {
                f[j]++;
                if (a[i] != j * j)
                    f[a[i] / j]++;
            }
        }
    }

    for (int i = 1;i <= n;i++) {
        for (int j = g;j >= 1;j--) {
            if (f[j] >= i) {
                g = j;
                break;
            }
        }
        printf("%d\n", g);
    }
    return 0;

}