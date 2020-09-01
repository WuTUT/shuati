#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 38;
ll f[maxn][maxn], g[maxn];
int main() {
    int n, h;
    cin >> n >> h;
    f[0][0] = 1;
    for (int i = 1;i < maxn;i++) {
        f[0][i] = 1;
    }
    f[1][0] = 0, f[1][1] = 1;
    for (int i = 2;i < maxn;i++) {
        f[1][i] = 1;
    }
    g[0] = 1, g[1] = 1;
    for (int i = 2;i <= n;i++) {
        for (int j = 0;j < i;j++) {
            g[i] += g[j] * g[i - j - 1];
        }
    }
    for (int i = 2;i <= n;i++) {
        for (int j = 1;j <= i;j++) {
            for (int k = 0;k < i;k++) {
                f[i][j] += f[k][j - 1] * f[i - k - 1][j - 1];
            }
        }
        for (int j = i + 1;j < maxn;j++) {
            f[i][j] = f[i][j - 1];
        }
    }
    // for (int i = 2;i <= n;i++) {
    //     for (int j = 0;j <= 5;j++) {
    //         printf("%lld ", f[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%lld\n", g[n] - f[n][h - 1]);
    return 0;
}