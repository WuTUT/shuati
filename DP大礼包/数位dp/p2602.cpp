#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll f[20][20];
int a[20];
ll dfs(bool lead, bool eq, int pos, int d, ll sum) {
    if (pos == 0) return sum;
    if (!eq && !lead && ~f[pos][sum]) return f[pos][sum];

    int ed = eq ? a[pos] : 9;
    ll ret = 0;
    for (int i = 0;i <= ed;i++) {
        ret += dfs(lead && i == 0, eq && i == ed, pos - 1, d, sum + ((d == i) && (!(lead && i == 0))));
    }
    if (!eq && !lead) f[pos][sum] = ret;
    return ret;
}
ll solve(ll x, int d) {
    a[0] = 0;
    while (x) {
        a[++a[0]] = x % 10;
        x /= 10;
    }
    memset(f, -1, sizeof f);
    return dfs(true, true, a[0], d, 0);
}
int main() {
    ll L, R;
    scanf("%lld %lld", &L, &R);
    for (int d = 0;d < 10;d++) {
        printf("%lld ", solve(R, d) - solve(L - 1, d));
    }
    return 0;
}