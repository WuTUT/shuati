#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 2005;
int f[maxn][maxn];
char s[maxn], t[maxn];
int n, m;
int main() {
    freopen("data.in", "r", stdin);
    s[0] = t[0] = '0';
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    //printf("%s %s\n", s + 1, t + 1);
    int d;
    scanf("%d", &d);
    int n = strlen(s) - 1;
    int m = strlen(t) - 1;
    for (int i = 1;i <= n;i++) {
        f[i][0] = f[i - 1][0] + d;
    }
    for (int j = 1;j <= m;j++) {
        f[0][j] = f[0][j - 1] + d;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            f[i][j] = min(f[i][j - 1] + d, f[i - 1][j] + d);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (int)abs(s[i] - t[j]));
        }
    }
    printf("%d", f[n][m]);
    return 0;
}