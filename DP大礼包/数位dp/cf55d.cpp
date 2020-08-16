#include <cstring>
#include <cstdio>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
ll f[20][50][2522];
int a[20];
int id[2522];
int iid[100];
int d[100][10];
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
inline int LCM(int x, int y) {
    return x * y / gcd(x, y);
}
ll dfs(int pos, bool eq, int lcm, int mod) {
    if (pos == 0) {
        if (mod % lcm == 0) {
            return 1;
        }
        else return 0;
    }
    if (!eq && ~f[pos][id[lcm]][mod]) return f[pos][id[lcm]][mod];
    int ed = eq ? a[pos] : 9;
    ll ret = 0;
    for (int i = 0;i <= ed;i++) {
        if (i <= 1) {
            ret += dfs(pos - 1, eq && i == ed, lcm, (mod * 10 + i) % 2520);
        }
        else {
            ret += dfs(pos - 1, eq && i == ed, d[id[lcm]][i], (mod * 10 + i) % 2520);
        }
    }

    if (!eq) f[pos][id[lcm]][mod] = ret;
    return ret;
}
ll solve(ll x) {
    a[0] = 0;
    while (x) {
        a[++a[0]] = x % 10;
        x /= 10;
    }

    return dfs(a[0], true, 1, 0);
}

int main() {
    freopen("data.in", "r", stdin);
    int cnt = 0;
    for (int i = 1;i <= 2520;i++) {
        if (2520 % i == 0) {

            id[i] = cnt;
            iid[cnt] = i;
            cnt++;
        }
    }
    for (int i = 0;i < cnt;i++) {
        for (int j = 2;j < 10;j++) {
            d[i][j] = LCM(iid[i], j);
        }
    }
    int T;
    scanf("%d", &T);
    memset(f, -1, sizeof f);
    while (T--) {
        ll L, R;
        cin >> L >> R;
        printf("%lld\n", solve(R) - solve(L - 1));
    }
    return 0;
}