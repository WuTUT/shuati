#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 105;
typedef long long ll;
int f[maxn][maxn];
int a[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;

    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1;i <= n;i++) {
        f[i][i] = a[i];
    }
    for (int len = 2;len <= n;len++) {
        for (int i = 1;i + len - 1 <= n;i++) {
            int j = i + len - 1;
            f[i][j] = max(f[i][j], f[i + 1][j] + a[i]);
            f[i][j] = max(f[i][j], f[i][j - 1] + a[j]);
            for (int k = i;k < j;k++) {
                f[i][j] = max(f[i][j], f[k + 1][j] + (k - i + 1) * abs(a[k] - a[i]));
            }
            for (int k = j;k > i;k--) {
                f[i][j] = max(f[i][j], f[i][k - 1] + (j - k + 1) * abs(a[k] - a[j]));
            }
            f[i][j] = max(f[i][j], abs(a[i] - a[j]) * (j - i + 1));
        }
    }
    printf("%d\n", f[1][n]);
    return 0;
}