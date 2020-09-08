#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 105;
int sum[maxn][maxn], a[maxn][maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            scanf("%d", &a[i][j]);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            for (int l = min(i, j);l > 0;l--) {
                int tmp = sum[i][j] - sum[i - l][j] - sum[i][j - l] + sum[i - l][j - l];
                if (tmp == l * l) {
                    ans = max(ans, l);
                    break;
                }
            }
        }
    }


    printf("%d\n", ans);


    return 0;
}