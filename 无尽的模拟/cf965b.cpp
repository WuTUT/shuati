#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 105;
int f[maxn][maxn];
char ch[maxn];
int n, k;
int g[maxn][maxn];
int pre[maxn][maxn];
int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        scanf(" %s", ch + 1);
        for (int j = 1;j <= n;j++) {
            if (ch[j] == '.') {
                f[i][j] = 1;
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            pre[i][j] = pre[i][j - 1] + f[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = k;j <= n;j++) {
            if (pre[i][j] - pre[i][j - k] == k) {
                for (int l = j - k + 1;l <= j;l++) {
                    g[i][l]++;
                }
            }
        }
    }
    memset(pre, 0, sizeof 0);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            pre[i][j] = pre[i - 1][j] + f[i][j];
        }
    }
    // for (int i = 1;i <= n;i++) {
    //     for (int j = 1;j <= n;j++) {
    //         cout << pre[i][j] << " ";

    //     }
    //     cout << endl;
    // }
    // cout << "------" << endl;
    for (int j = 1;j <= n;j++) {
        for (int i = k;i <= n;i++) {
            if (pre[i][j] - pre[i - k][j] == k) {
                for (int l = i - k + 1;l <= i;l++) {
                    g[l][j]++;
                }
            }
        }
    }
    int maxd = 0;
    int ansi, ansj;
    ansi = ansj = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (g[i][j] > maxd) {
                ansi = i;
                ansj = j;
                maxd = g[i][j];
            }
        }
    }
    // for (int i = 1;i <= n;i++) {
    //     for (int j = 1;j <= n;j++) {
    //         cout << g[i][j] << " ";

    //     }
    //     cout << endl;
    // }
    printf("%d %d\n", ansi, ansj);
    return 0;
}