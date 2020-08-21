#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1005;
typedef long long ll;
ll f[maxn][maxn];
ll g[maxn];
int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    g[1] = 1, g[2] = 1;
    for (int i = 3;i <= n * n;i++) {
        g[i] = g[i - 1] + g[i - 2];
    }
    int li = 1, ri = 1, cnt = n * n;
    while (!f[li][ri]) {
        while (ri <= n && !f[li][ri]) {
            f[li][ri++] = g[cnt--];
        }
        ri--;li++;
        while (li <= n && !f[li][ri]) {
            f[li++][ri] = g[cnt--];
        }
        li--;ri--;

        while (ri > 0 && !f[li][ri]) {
            f[li][ri--] = g[cnt--];
        }
        ri++;li--;
        while (li > 0 && !f[li][ri]) {
            f[li--][ri] = g[cnt--];
        }
        li++;ri++;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            printf("%lld ", f[i][j]);
        }
        printf("\n");
    }
    return 0;
}