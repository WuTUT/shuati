#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 50005;
vector<int> v[maxn];
int d[maxn];
int fat[maxn], dep[maxn], son[maxn], sz[maxn];
void dfs(int root, int fa) {
    dep[root] = dep[fa] + 1;
    fat[root] = fa;
    sz[root] = 1;
    int maxz = -1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs(to, root);
        sz[root] += sz[to];
        if (sz[to] > maxz) {
            maxz = sz[to];
            son[root] = to;
        }
    }
}
int top[maxn];int dfn[maxn], dfntot, va[maxn];
void dfs2(int root, int t) {
    top[root] = t;
    if (!son[root]) return;
    dfs2(son[root], t);
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fat[root] || to == son[root]) continue;
        dfs2(to, to);
    }
}
int LCA(int x, int y) {
    if (x == y) return x;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
        x = fat[top[x]];
    }
    if (dep[x] < dep[y]) return x;
    return y;
}
void deald(int root, int fa) {
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fat[root]) continue;
        deald(to, root);
        d[root] += d[to];
    }
}
int main() {
    freopen("data.in", "r", stdin);

    int n, k;
    cin >> n >> k;
    int xi, yi;
    for (int i = 1;i < n;i++) {
        scanf("%d %d", &xi, &yi);
        v[xi].push_back(yi);
        v[yi].push_back(xi);
    }
    dfs(1, 0);
    dfs2(1, 1);
    for (int i = 1;i <= k;i++) {
        scanf("%d %d", &xi, &yi);
        int lc = LCA(xi, yi);
        d[lc]--, d[fat[lc]]--;d[xi]++, d[yi]++;
    }
    deald(1, 0);
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        ans = max(d[i], ans);
    }
    printf("%d", ans);
    return 0;
}