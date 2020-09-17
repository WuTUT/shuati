#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 125;
int a[maxn][maxn], sum[maxn][maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    int ans = -0x7f7f7f7f;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            for (int k = i;k <= n;k++) {
                for (int l = j;l <= n;l++) {
                    ans = max(ans, sum[k][l] + sum[i - 1][j - 1] - sum[i - 1][l] - sum[k][j - 1]);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}