#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1005;

int f[maxn][maxn];
int g[maxn][maxn];
int n, m;
const int mod = 1e5 + 3;
int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0, x, y;i < m;i++) {
        scanf("%d %d", &x, &y);
        g[x][y] = 1;
    }
    f[1][0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (g[i][j] == 0) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
                f[i][j] %= mod;
            }
        }
    }
    printf("%d\n", f[n][n]);
    return 0;
}