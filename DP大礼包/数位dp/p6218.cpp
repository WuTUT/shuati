#include <iostream>
#include <bitset>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
int a[50];
ll f[50][50][50];
ll dfs(int pos, int n0, int n1, bool eq, bool lead) {
    if (pos == 0) {
        if (n0 >= n1) return 1;
        return 0;
    }
    if (!eq && !lead && ~f[pos][n0][n1]) return f[pos][n0][n1];
    int ed = eq ? a[pos] : 1;
    ll ret = 0;
    for (int i = 0;i <= ed;i++) {

        ret += dfs(pos - 1, n0 + (i == 0 && !lead), n1 + (i == 1), eq && i == ed, lead && i == 0);
    }
    if (!eq && !lead) f[pos][n0][n1] = ret;
    return ret;
}
ll solve(ll x) {
    a[0] = 0;
    while (x) {
        a[++a[0]] = x % 2;
        x /= 2;
    }
    memset(f, -1, sizeof f);
    return dfs(a[0], 0, 0, true, true);
}
int main() {
    ll L, R;
    scanf("%lld %lld", &L, &R);
    printf("%lld\n", solve(R) - solve(L - 1));
    return 0;
}