#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1005;
int d[maxn][maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n, m, x1, y1, x2, y2;
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= m;i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        d[x2 + 1][y2 + 1]++, d[x1][y1]++, d[x1][y2 + 1]--, d[x2 + 1][y1]--;
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            d[i][j] = d[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    return 0;

}