#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1005, mod = 1e8;
typedef long long ll;
int f[maxn * 2][maxn];
int a[maxn * 2];
int n, g;
int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> g;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    f[1][0] = 1;
    f[1][a[1] % g] = 1;
    for (int i = 1;i < n;i++) {
        for (int j = 0;j < g;j++) {
            f[i + 1][(j + a[i + 1]) % g] = (f[i + 1][(j + a[i + 1]) % g] + f[i][j]) % mod;
            f[i + 1][j] = (f[i + 1][j] + f[i][j]) % mod;
        }
    }
    printf("%d", f[n][0] - 1);
    return 0;
}
