#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1005;
int f[maxn];
int a[105];
int n, m;
int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    f[0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = m;j >= a[i];j--) {
            //if (f[j - a[i]] > 0)
            f[j] += f[j - a[i]];
        }
    }
    printf("%d", f[m]);
    return 0;
}
//p1164
//计算体积为V的方案数 f[i][j]=f[i-1][j]+f[i-1][j-a[i]] 