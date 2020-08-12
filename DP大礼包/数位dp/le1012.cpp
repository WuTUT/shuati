#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[20];
int f[20][1 << 10][2];
//        
int dfs(int lead, int eq, int pos, bool ok, int now) {
    //if (!ok) return 0;
    if (pos == 0) {
        if (ok)
            return 1;
        return 0;
    }
    if (!eq && !lead && ~f[pos][now][ok]) return f[pos][now][ok];
    int ed = eq ? a[pos] : 9;
    int ret = 0;
    for (int i = 0;i <= ed;i++) {
        if (lead && i == 0) ret += dfs(lead && i == 0, eq && i == ed, pos - 1, ok, now);
        else {
            ret += dfs(lead && i == 0, eq && i == ed, pos - 1, ok && (!((now >> i) & 1)), now | (1 << i));
        }
    }
    if (!eq && !lead) f[pos][now][ok] = ret;
    return ret;
}
int numDupDigitsAtMostN(int N) {
    int Tmp = N;
    a[0] = 0;
    while (N) {
        a[++a[0]] = N % 10;
        N /= 10;
    }
    memset(f, -1, sizeof f);
    return Tmp - dfs(true, true, a[0], true, 0) + 1;
}
int main() {
    int N;
    cin >> N;
    int ans = numDupDigitsAtMostN(N);
    printf("%d", ans);
    return 0;
}