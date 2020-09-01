#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 105, maxm = 10005;
//int g[maxm], f[maxn][maxn][maxn], num[maxn], a[maxn][maxn], tmp[maxn][maxn];
int g[maxm], f[maxn][maxn], num[maxn], a[maxn][maxn], sum[maxn][maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &num[i]);
        for (int j = 1;j <= num[i];j++) {
            scanf("%d", &a[i][j]);
        }
    }
    // for (int k = 1;k <= n;k++) {
    //     for (int j = 1;j <= num[k];j++) {
    //         f[j][j][1] = a[k][j];
    //     }
    //     for (int len = 2;len <= num[k];len++) {
    //         for (int i = 1;i + len - 1 <= num[k];i++) {
    //             int j = i + len - 1;
    //             for (int l = 1;l <= num[k];l++) {
    //                 f[i][j][l] = max(f[i][j - 1][l - 1] + a[k][j], f[i + 1][j][l - 1] + a[k][i]);
    //             }
    //         }
    //     }
    //     for (int j = 0;j <= num[k];j++) {
    //         tmp[k][j] = f[1][num[k]][j];
    //     }
    // }O(n^4)
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= num[i];j++) {
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
        for (int j = 1;j <= num[i];j++) {
            for (int k = 0;k <= j;k++) {
                f[i][j] = max(f[i][j], sum[i][k] - sum[i][0] + sum[i][num[i]] - sum[i][num[i] - j + k]);
            }
        }
    }



    // for (int i = 1;i <= n;i++) {
    //     for (int j = 0;j <= num[i];j++)
    //         printf("%d ", tmp[i][j]);
    //     printf("\n");
    // }
    for (int i = 1;i <= n;i++) {
        for (int j = m;j > 0;j--) {
            for (int k = 0;k <= min(j, num[i]);k++) {
                //                g[j] = max(g[j], g[j - k] + tmp[i][k]);
                g[j] = max(g[j], g[j - k] + f[i][k]);

            }
            //  printf("iters:%d %d\n", i, g[m]);
        }
    }
    printf("%d\n", g[m]);
    return 0;
}
//看似区间dp但是其实以前缀和可以O(n^2)替代O(n^3);