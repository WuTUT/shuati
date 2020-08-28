#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 505;
int f[maxn][maxn];
int tmp[maxn];
int sx, dx, sy, dy, co;
void rotate1(int x, int y, int r) {
    for (int j = 1;j <= r;j++) {
        int nx = x - j, ny = y - j;
        for (int k = 0;k < 2 * j + 1;k++) {
            tmp[k] = f[nx][ny + k];
        }
        sx = x - j, sy = y - j;
        dx = x - j, dy = y + j;
        co = 0;
        while (co < 2 * j + 1) {
            f[dx][dy] = f[sx][sy];
            dy--;sx++;
            co++;
        }
        co = 0;
        sx = x + j, sy = y - j;
        dx = x - j, dy = y - j;
        while (co < 2 * j + 1) {
            f[dx][dy] = f[sx][sy];
            dx++;sy++;
            co++;
        }
        co = 0;
        sx = x + j, sy = y + j;
        dx = x + j, dy = y - j;
        while (co < 2 * j + 1) {
            f[dx][dy] = f[sx][sy];
            dy++;sx--;
            co++;
        }
        co = 0;
        dx = x - j, dy = y + j;
        while (co < 2 * j + 1) {
            f[dx][dy] = tmp[co];
            dx++;
            co++;
        }
    }
}
void rotate2(int x, int y, int r) {
    for (int j = 1;j <= r;j++) {
        int nx = x - j, ny = y - j;
        for (int k = 0;k < 2 * j + 1;k++) {
            tmp[k] = f[nx][ny + k];
        }
        sx = x - j, sy = y + j;
        dx = x - j, dy = y - j;
        co = 0;
        while (co < 2 * j + 1) {
            f[dx][dy] = f[sx][sy];
            sx++;dy++;
            co++;
        }
        co = 0;
        sx = x + j, sy = y + j;
        dx = x - j, dy = y + j;
        while (co < 2 * j + 1) {
            f[dx][dy] = f[sx][sy];
            dx++;sy--;
            co++;
        }
        co = 0;
        sx = x + j, sy = y - j;
        dx = x + j, dy = y + j;
        while (co < 2 * j + 1) {
            f[dx][dy] = f[sx][sy];
            dy--;sx--;
            co++;
        }
        co = 0;
        dx = x + j, dy = y - j;
        while (co < 2 * j + 1) {
            f[dx][dy] = tmp[co];
            dx--;
            co++;
        }
    }
}
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int cnt = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            f[i][j] = cnt++;
        }
    }

    int x, y;
    int r, z;
    for (int i = 1;i <= m;i++) {
        cin >> x >> y;
        cin >> r >> z;
        if (z == 0) {
            rotate1(x, y, r);
        }
        else {
            rotate2(x, y, r);
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            printf("%d ", f[i][j]);
        }
        printf("\n");
    }
    return 0;
}