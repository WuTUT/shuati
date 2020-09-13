#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxm = 1005;
int f[maxm][maxm];
int n, m, x;
int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> m >> x;
    for (int i = 1, ai, bi, ci;i <= n;i++) {
        scanf("%d %d %d", &ai, &bi, &ci);
        for (int j = m;j >= bi;j--) {
            for (int k = x;k >= ci;k--) {
                f[j][k] = max(f[j][k], f[j - bi][k - ci] + ai);
            }
        }
    }
    printf("%d", f[m][x]);
    return 0;
}
//P1910