#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 1e7 + 5;
ll d[maxn], f[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    int l, r, s, e;
    for (int i = 1;i <= m;i++) {
        scanf("%d %d %d %d", &l, &r, &s, &e);
        int nd = (e - s) / (r - l);
        f[l + 1] += nd, f[r + 1] -= nd;
        d[l] += s, d[r + 1] -= e;
    }
    for (int i = 1;i <= n;i++) {
        f[i] += f[i - 1];
    }
    for (int i = 1;i <= n;i++) {
        d[i] += f[i];
    }
    ll ans1 = 0, ans2 = -0x7f7f7f7f7f7f7f7f;
    for (int i = 1;i <= n;i++) {
        d[i] += d[i - 1];
        //   printf("%lld ", d[i]);
        ans1 ^= d[i];
        ans2 = max(ans2, d[i]);
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}