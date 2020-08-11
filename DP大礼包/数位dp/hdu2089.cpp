#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int a[20];
ll f[20][2];
ll dfs(int pos, int sta, bool eq) {
    if (pos == 0) return 1;
    if (!eq && f[pos][sta] != -1) return f[pos][sta];

    int ed = eq ? a[pos] : 9;
    ll ret = 0;

    for (int i = 0;i <= ed;i++) {
        if (sta && i == 2) continue;
        if (i == 4) continue;

        ret += dfs(pos - 1, i == 6, eq && i == ed);
    }

    if (!eq) f[pos][sta] = ret;
    return ret;
}
ll solve(ll x) {
    a[0] = 0;
    while (x) {
        a[++a[0]] = x % 10;
        x /= 10;
    }
    memset(f, -1, sizeof f);
    return dfs(a[0], 0, true);
}
int main() {
    ll L, R;
    while (scanf("%lld %lld", &L, &R) && (L || R)) {
        if (L) {
            printf("%lld\n", solve(R) - solve(L - 1));
        }
        else {
            printf("%lld\n", solve(R) - solve(L));
        }
    }
    return 0;
}