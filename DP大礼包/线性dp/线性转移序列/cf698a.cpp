#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e2 + 5;
int a[maxn];
int f[maxn][3];//xiu duan bi
               //0    1    2

int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    memset(f, 0x7f, sizeof f);
    f[0][0] = f[0][1] = f[0][2] = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] == 0) {
            f[i][0] = min(min(f[i - 1][0], f[i - 1][1]), f[i - 1][2]) + 1;
        }
        else if (a[i] == 1) {
            f[i][0] = min(min(f[i - 1][0], f[i - 1][1]), f[i - 1][2]) + 1;
            f[i][2] = min(f[i - 1][0], f[i - 1][1]);
        }
        else if (a[i] == 2) {
            f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
            f[i][1] = min(f[i - 1][0], f[i - 1][2]);
        }
        else {
            f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
            f[i][1] = min(f[i - 1][0], f[i - 1][2]);
            f[i][2] = min(f[i - 1][1], f[i - 1][0]);
        }
    }
    int ans = 0;
    ans = min(f[n][0], f[n][1]);
    ans = min(ans, f[n][2]);
    printf("%d\n", ans);
    return 0;
}
