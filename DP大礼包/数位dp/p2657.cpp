#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll f[20][10];
int a[20];
ll dfs(bool lead, bool eq, int pos, int pre) {
    if (pos == 0) return 1;
    if (!eq && !lead && ~f[pos][pre]) return f[pos][pre];

    int ed = eq ? a[pos] : 9;
    ll ret = 0;
    for (int i = 0;i <= ed;i++) {
        if (!lead && abs(pre - i) < 2) continue;
        ret += dfs(lead && i == 0, eq && i == ed, pos - 1, i);
    }
    if (!eq && !lead) f[pos][pre] = ret;
    return ret;
}
ll solve(ll x) {
    a[0] = 0;
    while (x) {
        a[++a[0]] = x % 10;
        x /= 10;
    }
    memset(f, -1, sizeof f);
    return dfs(true, true, a[0], -1);
}
int main() {
    ll L, R;
    scanf("%lld %lld", &L, &R);
    printf("%lld\n", solve(R) - solve(L - 1));
    return 0;
}