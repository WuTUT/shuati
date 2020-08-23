#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxm = 1005, maxn = 105;
double f[2][maxn * maxm], sum[maxn * maxm];
int c[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    int sc = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &c[i]);
        sc += c[i];
    }
    //sum[0] = 1.0;
    //f[0][0] = 1.0;
    double dv = 1.0 / (m - 1);
    // for (int i = 1;i <= n;i++) {
    //     int p = i & 1;
    //     for (int j = i;j <= i * m;j++) {
    //         int L = max(j - m, i - 1), R = min(j - 1, (i - 1) * m);
    //         f[p][j] = sum[R];
    //         if (L > 0) f[p][j] -= sum[L - 1];
    //         if (L <= j - c[i] && j - c[i] <= R) {
    //             f[p][j] -= f[p ^ 1][j - c[i]];
    //         }
    //         f[p][j] *= dv;
    //     }
    //     for (int j = i;j <= i * m;j++) sum[j] = sum[j - 1] + f[p][j];
    // }
    sum[0] = 0.0;
    for (int i = 1;i <= m;i++) {
        f[1][i] = 1.0 * dv;
        if (i == c[1]) f[1][i] = 0;
        sum[i] = sum[i - 1] + f[1][i];
    }
    for (int i = 2;i <= n;i++) {
        int p = i & 1;
        for (int j = i;j <= i * m;j++) {
            int L = max(j - m, i - 1), R = min(j - 1, (i - 1) * m);
            f[p][j] = sum[R];
            if (L > 0) f[p][j] -= sum[L - 1];
            if (j - c[i] <= R && j - c[i] >= L) f[p][j] -= f[p ^ 1][j - c[i]];
            f[p][j] *= dv;
        }
        for (int j = 1;j <= i * m;j++) sum[j] = sum[j - 1] + f[p][j];
    }

    double ans = 0.0;
    for (int i = n;i < sc;i++) {
        ans += f[n & 1][i];
    }
    printf("%.16lf\n", ans * (m - 1) + 1.0);
    return 0;
}