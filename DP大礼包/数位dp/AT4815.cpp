#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 105;
typedef long long ll;
ll f[maxn][5];
string s;
int k;
ll dfs(int pos, int now, bool lead, bool eq) {
    if (now > k) return 0;

    if (pos == s.length()) {
        if (now == k) return 1;
        else return 0;
    }
    if (!lead && !eq && ~f[pos][now]) return f[pos][now];
    int ed = eq ? (s[pos] - '0') : 9;
    ll ret = 0;
    for (int i = 0;i <= ed;i++) {
        ret += dfs(pos + 1, now + (i != 0), lead && i == 0, eq && i == ed);
    }
    if (!lead && !eq) f[pos][now] = ret;
    return ret;
}
ll solve(string& s) {
    memset(f, -1, sizeof f);
    return dfs(0, 0, true, true);
}
int main() {
    freopen("data.in", "r", stdin);
    cin >> s;
    cin >> k;
    printf("%lld\n", solve(s));
    return 0;
}