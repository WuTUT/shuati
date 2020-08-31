#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> v[maxn];
struct edge {
    int x, y;
};
vector<edge> e;
int d[maxn];
int f[maxn][20];
int dep[maxn];
int lg[maxn];
void dfs1(int root, int fa) {
    dep[root] = dep[fa] + 1;
    f[root][0] = fa;
    for (int i = 1;i <= lg[dep[root]];i++) {
        f[root][i] = f[f[root][i - 1]][i - 1];
    }
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs1(to, root);
    }
}
int lca(int x, int y) {
    if (x == y) return x;
    if (dep[x] < dep[y]) std:swap(x, y);
    while (dep[x] > dep[y]) {
        x = f[x][lg[dep[x] - dep[y]]];
    }
    if (x == y) return x;
    for (int i = lg[dep[x]];i >= 0;i--) {
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];
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
    int xi, yi;
    cin >> n;
    for (int i = 1;i < n;i++) {
        scanf("%d %d", &xi, &yi);
        v[xi].push_back(yi);
        v[yi].push_back(xi);
        e.push_back({ xi,yi });
    }
    dfs1(1, 0);
    cin >> k;
    for (int i = 1;i <= k;i++) {
        scanf("%d %d", &xi, &yi);
        int lc = lca(xi, yi);
        d[lc] -= 2, d[xi]++, d[yi]++;
    }
    dfs2(1, 0);
    for (int i = 0;i < n - 1;i++) {
        printf("%d ", dep[e[i].x] < dep[e[i].y] ? d[e[i].y] : d[e[i].x]);
    }
    return 0;
}
//cf191c