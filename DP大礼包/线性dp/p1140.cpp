#include <cstring>
#include <cstdio>

#include <iostream>
using namespace std;
const int maxn = 105;
int f[maxn][maxn];
char s[maxn], t[maxn];
int table[5][5] = {
    5, -1, -2, -1, -3,
    -1, 5, -3, -2, -4,
    -2, -3, 5, -2, -2,
    -1, -2, -2, 5, -1,
    -3, -4, -2, -1, -0x3f3f3f3f
};
inline int to(char c) {
    if (c == 'A') return 0;
    else if (c == 'C') return 1;
    else if (c == 'G') return 2;
    else if (c == 'T') return 3;
    else return 4;
}
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    cin >> n;
    scanf(" %s", s + 1);
    cin >> m;
    scanf(" %s", t + 1);
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1;i <= n;i++) {
        f[i][0] = f[i - 1][0] + table[to(s[i])][4];
    }
    for (int i = 1;i <= m;i++) {
        f[0][i] = f[0][i - 1] + table[4][to(t[i])];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            f[i][j] = max(f[i - 1][j - 1] + table[to(s[i])][to(t[j])], f[i - 1][j] + table[to(s[i])][4]);
            f[i][j] = max(f[i][j], f[i][j - 1] + table[4][to(t[j])]);
        }
    }
    printf("%d", f[n][m]);
}