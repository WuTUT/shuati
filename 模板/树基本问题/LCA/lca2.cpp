#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 500005;
vector<int> v[maxn];
int dfn[maxn << 1], idx[maxn];
int dep[maxn << 1];
int dfstot;
int lg[maxn << 1];
int dp[maxn << 1][21];
void dfs(int root, int fa, int dis) {
    dfn[++dfstot] = root;
    idx[root] = dfstot;
    dep[dfstot] = dis;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs(to, root, dis + 1);
        dfn[++dfstot] = root;
        dep[dfstot] = dis;
    }
}
inline int cmpdep(int x, int y) {
    return dep[x] < dep[y] ? x : y;
}
void RMQ(int n) {
    for (int i = 1;i <= n;i++) {
        dp[i][0] = i;
    }
    for (int j = 1;(1 << j) <= n;j++) {
        for (int i = 1;i + (1 << j) - 1 <= n;i++) {
            dp[i][j] = cmpdep(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
        }
    }
}
inline int query(int x, int y) {
    int k = lg[y - x + 1];
    return cmpdep(dp[x][k], dp[y - (1 << k) + 1][k]);
}
int LCA(int x, int y) {
    x = idx[x];
    y = idx[y];
    if (x > y)
        return dfn[query(y, x)];
    else
        return dfn[query(x, y)];
}
int n, m, s;
int main() {
    freopen("data.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &s);
    dfstot = 0;
    lg[0] = lg[1] = 0;
    for (int i = 2;i <= n * 2;i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1, x, y;i < n;i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(s, -1, 1);
    RMQ(2 * n - 1);
    for (int i = 1, a, b;i <= m;i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
    return 0;
}