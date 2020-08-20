#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 500005;
vector<int> v[maxn];
int n, m, s;
int dep[maxn];
int dp[maxn][21];
int lg[maxn];
void dfs(int root, int fa) {
    dp[root][0] = fa, dep[root] = dep[fa] + 1;
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
    if (dep[x] < dep[y])
        std::swap(x, y);
    while (dep[x] > dep[y]) {
        x = dp[x][lg[dep[x] - dep[y]] - 1];
        if (x == y) return x;
    }
    for (int k = lg[dep[x]] - 1;k >= 0;k--) {
        if (dp[x][k] != dp[y][k])
            x = dp[x][k], y = dp[y][k];
    }
    return dp[x][0];
}
int main() {
    freopen("data.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1;i <= n;i++) {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }

    for (int i = 1, x, y;i < n;i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(s, -1);
    for (int i = 1, a, b;i <= m;i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
}