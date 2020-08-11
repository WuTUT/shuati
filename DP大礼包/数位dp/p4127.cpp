#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
int a[20];
int sum;
ll f[20][170][170];
ll dfs(int pos, int cur, int mod, bool eq) {
    if (cur + 9 * pos < sum) return 0;
    if (pos == 0) {
        if (cur == sum && mod == 0) return 1;
        else return 0;
    }
    if (!eq && ~f[pos][cur][mod]) return f[pos][cur][mod];
    int ed = eq ? a[pos] : 9;
    ll ret = 0;
    for (int i = 0;i <= ed;i++) {

        ret += dfs(pos - 1, cur + i, (mod * 10 + i) % sum, eq && i == ed);
    }
    if (!eq) f[pos][cur][mod] = ret;
    return ret;
}
ll solve(ll x) {
    a[0] = 0;
    while (x) {
        a[++a[0]] = x % 10;
        x /= 10;
    }
    ll ans = 0;
    for (int i = 1;i <= a[0] * 9;i++) {
        sum = i;
        memset(f, -1, sizeof f);
        ans += dfs(a[0], 0, 0, true);
    }
    return ans;
}
int main() {
    ll L, R;
    scanf("%lld %lld", &L, &R);
    printf("%lld\n", solve(R) - solve(L - 1));
}