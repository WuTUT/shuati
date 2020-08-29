#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline int read()
{
    int x = 0;
    char c = getchar();
    while (c < '0' || c>'9')c = getchar();
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';c = getchar();
    }
    return x;
}
const int maxn = 5000005;
int d[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n, p;
    n = read();p = read();
    int a, _a = 0;
    for (int i = 1;i <= n;i++) {
        a = read();
        d[i] = a - _a;
        _a = a;
    }
    int x, y, z;
    for (int i = 1;i <= p;i++) {
        x = read();
        y = read();
        z = read();
        d[x] += z, d[y + 1] -= z;
    }
    int ans = 0x7f7f7f7f;a = 0;
    for (int i = 1;i <= n;i++) {
        a += d[i];
        ans = min(ans, a);
    }
    printf("%d\n", ans);
    return 0;
}