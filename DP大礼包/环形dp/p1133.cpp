#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[2][3][2];
int a[100005][3];
int main() {
    freopen("data.in", "r", stdin);
    int n;


    cin >> n;
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }

    int ai, bi, ci;
    for (int si = 0;si < 3;si++) {
        memset(f, 0, sizeof f);
        f[1][si][0] = f[1][si][1] = a[1][si];
        for (int i = 2;i <= n;i++) {
            int p = i & 1;

            f[p][0][0] = max(f[p ^ 1][1][1], f[p ^ 1][2][1]) + a[i][0];
            f[p][1][0] = f[p ^ 1][2][1] + a[i][1];
            f[p][1][1] = f[p ^ 1][0][0] + a[i][1];
            f[p][2][1] = max(f[p ^ 1][1][0], f[p ^ 1][0][0]) + a[i][2];
        }
        if (si == 0) {
            ans = max(ans, max(f[n & 1][2][1], f[n & 1][1][1]));
        }
        else if (si == 1) {
            ans = max(ans, max(f[n & 1][0][0], f[n & 1][2][1]));
        }
        else {
            ans = max(ans, max(f[n & 1][0][0], f[n & 1][1][0]));
        }

    }
    printf("%d", ans);
    return 0;
}