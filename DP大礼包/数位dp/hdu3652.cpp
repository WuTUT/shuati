#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int a[20];
ll f[13][13][2][10];
ll dfs(int pos, bool eq, int mod, bool has, int pre) {
    if (pos == 0) {
        if (has && mod == 0) return 1;
        return 0;
    }
    if (!eq && ~f[pos][mod][has][pre]) return f[pos][mod][has][pre];

    int ed = eq ? a[pos] : 9;
    ll ret = 0;

    for (int i = 0;i <= ed;i++) {
        ret += dfs(pos - 1, eq && i == ed, (mod * 10 + i) % 13, has || (i == 3 && pre == 1), i);
    }

    if (!eq) f[pos][mod][has][pre] = ret;
    return ret;
}
ll solve(ll x) {
    a[0] = 0;
    while (x) {
        a[++a[0]] = x % 10;
        x /= 10;
    }

    return dfs(a[0], true, 0, false, 0);
}
int main() {
    freopen("data.in", "r", stdin);
    ll R;
    memset(f, -1, sizeof f);
    while (scanf("%lld", &R) != EOF) {
        printf("%lld\n", solve(R));
    }
    return 0;
}