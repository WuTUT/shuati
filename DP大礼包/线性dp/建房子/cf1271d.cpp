#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 6015;
int f[maxn][maxn];
vector<int> v[maxn];
int fa[maxn];
int a[maxn], b[maxn], c[maxn];
bool cmp(int x1, int x2) {
    return c[x1] > c[x2];
}
int main() {
    freopen("data.in", "r", stdin);
    int n, m, k0;

    cin >> n >> m >> k0;
    int kmax = k0;
    for (int i = 1;i <= n;i++) { scanf("%d %d %d", &a[i], &b[i], &c[i]);kmax += b[i]; fa[i] = i; }
    for (int i = 0, fr, to;i < m;i++) {
        scanf("%d %d", &fr, &to);
        fa[to] = max(fa[to], fr);
    }
    for (int i = 1;i <= n;i++) {
        v[fa[i]].push_back(i);
        // printf("%d ", fa[i]);
    }
    // printf("\n");
    for (int i = 1;i <= n;i++) {
        sort(v[i].begin(), v[i].end(), cmp);
    }
    memset(f, -1, sizeof f);
    f[0][k0] = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j <= kmax - b[i + 1];j++) {
            if (f[i][j] == -1) continue;
            if (j >= a[i + 1]) {
                if (fa[i + 1] == i + 1) {
                    f[i + 1][j + b[i + 1]] = max(f[i + 1][j + b[i + 1]], f[i][j]);
                    if (j + b[i + 1] - 1 >= 0)
                        f[i + 1][j + b[i + 1] - 1] = max(f[i + 1][j + b[i + 1] - 1], f[i][j] + c[i + 1]);
                }
                else {
                    f[i + 1][j + b[i + 1]] = max(f[i + 1][j + b[i + 1]], f[i][j]);
                }
                int vsz = v[i + 1].size();
                if (vsz > 0) {
                    int sumall = 0;
                    for (int k = 1;k <= vsz;k++) {
                        sumall += c[v[i + 1][k - 1]];
                        if (j + b[i + 1] - k >= 0)
                            f[i + 1][j + b[i + 1] - k] = max(f[i + 1][j + b[i + 1] - k], f[i][j] + sumall);

                    }
                }
            }
        }
    }
    // for (int i = 0;i <= kmax;i++) printf("%2d ", i);
    // printf("\n");
    // for (int i = 1;i <= n;i++) {
    //     for (int j = 0;j <= kmax;j++) {
    //         printf("%2d ", f[i][j]);
    //     }
    //     printf("\n");
    // }
    int ans = -1;
    for (int j = 0;j <= kmax;j++) {
        ans = max(f[n][j], ans);
    }
    printf("%d\n", ans);

    return 0;
}