#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e5 + 5;
vector<int> v[maxn];
int n, m, s;
int fat[maxn], dep[maxn], son[maxn], sz[maxn];
int dfn[maxn], top[maxn], dfntot;
void dfs1(int root, int fa) {
    fat[root] = fa;
    dep[root] = dep[fa] + 1;
    sz[root] = 1;
    int maxsz = -1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs1(to, root);
        sz[root] += sz[to];
        if (sz[to] > maxsz) {
            son[root] = to;
            maxsz = sz[to];
        }
    }
}
void dfs2(int root, int t) {
    dfn[root] = ++dfntot;
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
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
        x = fat[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}
int main() {
    freopen("data.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1, ai, bi;i < n;i++) {
        scanf("%d %d", &ai, &bi);
        v[ai].push_back(bi);
        v[bi].push_back(ai);
    }
    dfntot = 0;
    dfs1(s, 0);
    dfs2(s, s);
    for (int i = 1, ai, bi;i <= m;i++) {
        scanf("%d %d", &ai, &bi);
        printf("%d\n", LCA(ai, bi));
    }
    return 0;
}