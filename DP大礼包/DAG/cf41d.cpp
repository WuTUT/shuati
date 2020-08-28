#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
const int maxn = 105;
int f[2][maxn][12];
//int f[maxn][maxn][12];
int a[maxn][maxn];
int path[maxn][maxn][12];
int main() {

    freopen("data.in", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k; k++;
    char ch;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {

            scanf(" %c", &ch);
            a[i][j] = ch - '0';
        }
    }
    memset(f, -0x3f, sizeof f);
    for (int j = 1;j <= m;j++) {
        f[1 & 1][j][a[1][j] % k] = a[1][j];
    }
    for (int i = 1;i <= n;i++) {
        int p = i & 1;
        memset(f[p ^ 1], -0x3f, sizeof f[0]);
        for (int j = 1;j <= m;j++) {
            for (int l = 0;l < k;l++) {
                if (j + 1 <= m) {
                    int& ne = f[p ^ 1][j + 1][(l + a[i + 1][j + 1]) % k];
                    if (f[p][j][l] + a[i + 1][j + 1] > ne) {
                        ne = f[p][j][l] + a[i + 1][j + 1];
                        path[i + 1][j + 1][(l + a[i + 1][j + 1]) % k] = j;
                    }
                    // if (f[i][j][l] + a[i + 1][j + 1] > f[i + 1][j + 1][(l + a[i + 1][j + 1]) % k]) {
                    //     f[i + 1][j + 1][(l + a[i + 1][j + 1]) % k] = f[i][j][l] + a[i + 1][j + 1];
                    //     path[i + 1][j + 1][(l + a[i + 1][j + 1]) % k] = j;
                    // }
                }
                if (j - 1 > 0) {
                    int& ne = f[p ^ 1][j - 1][(l + a[i + 1][j - 1]) % k];
                    if (f[p][j][l] + a[i + 1][j - 1] > ne) {
                        ne = f[p][j][l] + a[i + 1][j - 1];
                        path[i + 1][j - 1][(l + a[i + 1][j - 1]) % k] = j;
                    }
                    // if (f[i][j][l] + a[i + 1][j - 1] > f[i + 1][j - 1][(l + a[i + 1][j - 1]) % k]) {
                    //     f[i + 1][j - 1][(l + a[i + 1][j - 1]) % k] = f[i][j][l] + a[i + 1][j - 1];
                    //     path[i + 1][j - 1][(l + a[i + 1][j - 1]) % k] = j;
                    // }
                }
            }
        }
    }
    int ans = -1;
    int st = -1;
    for (int i = 1;i <= m;i++) {
        if (ans < f[n & 1][i][0]) {
            ans = f[n & 1][i][0];
            st = i;
        }
        // if (ans < f[n][i][0]) {
        //     ans = f[n][i][0];
        //     st = i;
        // }
    }
    if (ans == -1) {
        cout << -1 << endl;
        return 0;
    }
    else {
        cout << ans << endl << st << endl;
    }
    int ny = st;int le = 0;
    for (int i = n;i > 1;i--) {
        int nny = path[i][ny][le];
        if (nny - ny == 1) {
            printf("R");
        }
        else {
            printf("L");
        }
        for (int j = 0;j < k;j++) {
            if ((j + a[i][ny]) % k == le) {
                le = j;
                break;
            }
        }
        ny = nny;
    }
    printf("\n");
    return 0;
}