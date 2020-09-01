#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 24;
int f[1 << maxn];
int d1[maxn], d2[maxn][maxn];
int inline dis(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
int x[maxn], y[maxn];
int g[1 << maxn][2];
void print(int i) {
    if (i == 0) {
        return;
    }
    if (g[i][0] != g[i][1]) {
        print(i - (1 << g[i][0]) - (1 << g[i][1]));
        printf("%d ", 0);
        printf("%d %d ", g[i][0] + 1, g[i][1] + 1);
    }
    else {
        print(i - (1 << g[i][0]));
        printf("%d ", 0);
        printf("%d ", g[i][0] + 1);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    int x0, y0;
    scanf("%d %d", &x0, &y0);
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 0;i < n;i++) {
        d1[i] = dis(x0, y0, x[i], y[i]);
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            d2[i][j] = dis(x[i], y[i], x[j], y[j]);
        }
    }
    memset(f, 0x7f, sizeof f);
    f[0] = 0;
    for (int i = 1;i < (1 << n);i++) {

        for (int j = 0;(1 << j) <= i;j++) {
            if ((i >> j) & 1) {
                for (int k = 0;(1 << k) <= i;k++) {
                    if ((i >> k) & 1) {
                        if (j == k) {

                            int nxt = f[i - (1 << j)] + d1[j] * 2;
                            if (nxt < f[i]) {
                                f[i] = nxt;
                                g[i][0] = g[i][1] = j;
                            }
                        }
                        else {
                            int nxt = f[i - (1 << j) - (1 << k)] + d1[j] + d1[k] + d2[j][k];
                            if (nxt < f[i]) {
                                f[i] = nxt;
                                g[i][0] = j, g[i][1] = k;
                            }
                        }
                    }
                }
                break;
            }

        }
    }
    printf("%d\n", f[(1 << n) - 1]);
    print((1 << n) - 1);
    printf("0\n");
    return 0;
}