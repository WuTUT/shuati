#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int a[20];
ll f[15][4][11][11][2];
ll dfs(bool eq, int pos, int pre, int prepre, int sta, bool has) {
    //if (sta == 2) return 0;
    if (pos == 0) {
        if (has && sta != 3) return 1;
        else return 0;
    }

    if (!eq && ~f[pos][sta][pre][prepre][has]) return f[pos][sta][pre][prepre][has];
    int ed = eq ? a[pos] : 9;

    ll ret = 0;
    int nxtsta = sta;
    bool nxthas = has;
    for (int i = 0;i <= ed;i++) {
        if (pre == 10 && i == 0) continue;

        if (sta == 1 && i == 4) nxtsta = 3;
        if (sta == 2 && i == 8) nxtsta = 3;

        if (sta == 0 && i == 4)    nxtsta = 2;
        else if (sta == 0 && i == 8)  nxtsta = 1;

        if (prepre == pre && pre == i) nxthas = true;

        ret += dfs(eq && i == ed, pos - 1, i, pre, nxtsta, nxthas);
        nxtsta = sta;
        nxthas = has;
    }
    if (!eq) f[pos][sta][pre][prepre][has] = ret;
    return ret;
}
ll solve(ll x) {
    a[0] = 0;
    while (x) {
        a[++a[0]] = x % 10;
        x /= 10;
    }
    if (a[0] != 11) return 0;
    memset(f, -1, sizeof f);
    return dfs(true, a[0], 10, 10, 0, false);
}
int main() {
    freopen("data.in", "r", stdin);
    ll L, R;

    scanf("%lld %lld", &L, &R);
    printf("%lld\n", solve(R) - solve(L - 1));
    return 0;
}