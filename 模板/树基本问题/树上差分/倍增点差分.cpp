#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 50005;
vector<int> v[maxn];
int lg[maxn];
int dep[maxn];
int dp[maxn][20];
int d[maxn];
void dfs(int root, int fa) {
    dep[root] = dep[fa] + 1;
    dp[root][0] = fa;
    for (int i = 1;i <= lg[dep[root]];i++) {
        dp[root][i] = dp[dp[root][i - 1]][i - 1];
    }
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs(to, root);
    }
}
int LCA(int x, int y) {
    if (x == y) return x;
    if (dep[x] < dep[y]) std:swap(x, y);
    while (dep[x] > dep[y]) {
        x = dp[x][lg[dep[x] - dep[y]]];

    }
    if (y == x) return x;
    for (int i = lg[dep[x]];i >= 0;i--) {
        if (dp[x][i] != dp[y][i])
            x = dp[x][i], y = dp[y][i];

    }
    return dp[x][0];
}
void dfs2(int root, int fa) {
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs2(to, root);
        d[root] += d[to];
    }
}
int main() {
    freopen("data.in", "r", stdin);
    lg[1] = 0;
    for (int i = 2;i < maxn;i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    int n, k;
    cin >> n >> k;
    int xi, yi;
    for (int i = 1;i < n;i++) {
        scanf("%d %d", &xi, &yi);
        v[xi].push_back(yi);
        v[yi].push_back(xi);
    }
    dfs(1, 0);
    for (int i = 1;i <= k;i++) {
        scanf("%d %d", &xi, &yi);
        int lc = LCA(xi, yi);
        d[lc]--, d[dp[lc][0]]--;d[xi]++, d[yi]++;
    }
    dfs2(1, 0);
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        ans = max(d[i], ans);
    }
    printf("%d", ans);
    return 0;
}