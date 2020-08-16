#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
struct node {
    ll cnt;
    ll sum;
    ll sqr;
}f[20][2][8][8];
int a[20];
const ll mod = 1e9 + 7;
ll p10[20];
void do10() {
    p10[0] = 1;
    for (int i = 1;i < 20;i++) {
        p10[i] = p10[i - 1] * 10;
    }
}
node dfs(int pos, bool has, int sum, int left, bool eq) {
    if (pos == 0) {
        if (has == 1 || sum == 0 || left == 0) {
            return (node) { 0, 0, 0 };
        }
        else return (node) { 1, 0, 0 };
    }
    if (!eq && ~f[pos][has][sum][left].cnt) return f[pos][has][sum][left];
    int ed = eq ? a[pos] : 9;
    node ret = (node){ 0,0,0 };
    for (int i = 0;i <= ed;i++) {
        int ki = 1ll * p10[pos - 1] * i % mod;
        node p = dfs(pos - 1, has || i == 7, (sum + i) % 7, (left * 10 + i) % 7, eq && i == ed);
        ret.cnt = (ret.cnt + p.cnt) % mod;
        ret.sum = (ret.sum + p.sum + 1ll * p.cnt * ki % mod) % mod;
        ret.sqr = (ret.sqr + p.sqr + 1ll * ki * ki % mod * p.cnt + 2ll * ki * p.sum % mod) % mod;
    }
    if (!eq) f[pos][has][sum][left] = ret;
    return ret;
}
inline void initf() {
    for (int i = 0;i < 20;i++) {
        for (int j = 0;j < 2;j++) {
            for (int k = 0;k < 8;k++) {
                for (int l = 0;l < 8;l++) {
                    f[i][j][k][l].cnt = -1;
                }
            }
        }
    }
}
ll sovle(ll x) {
    a[0] = 0;
    while (x) {
        a[++a[0]] = x % 10;
        x /= 10;
    }
    initf();
    return dfs(a[0], false, 0, 0, true).sqr;
}

int main() {
    freopen("data.in", "r", stdin);
    do10();
    int T;
    scanf("%d", &T);
    while (T--) {
        ll L, R;
        scanf("%lld %lld", &L, &R);
        printf("%lld\n", (sovle(R) - sovle(L - 1) + mod) % mod);
    }
    return 0;
}