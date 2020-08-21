#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100005;
vector<int> v[maxn];
int dep[maxn];
int f[maxn][21];
int lg[maxn];
int n, m;
inline void init(int n) {
    lg[1] = 0;
    for (int i = 2;i <= n;i++) {
        lg[i] = lg[i >> 1] + 1;
    }
}
void dfs(int root, int fa) {
    dep[root] = dep[fa] + 1;
    f[root][0] = fa;
    for (int j = 1;j <= lg[dep[root]];j++) {//有等于
        f[root][j] = f[f[root][j - 1]][j - 1];
    }
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa)continue;
        dfs(to, root);
    }
}
int LCA(int x, int y) {

    if (dep[x] < dep[y])
        std::swap(x, y);
    while (dep[x] > dep[y]) {
        x = f[x][lg[dep[x] - dep[y]]];
    }
    if (x == y) return x;//x==y时 必须有
    for (int i = lg[dep[x]];i >= 0;i--) {
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];

}
inline int dis(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}
int main() {
    //freopen("data.in", "r", stdin);
    scanf("%d %d", &n, &m);
    init(n);
    for (int i = 1, ai, bi;i < n;i++) {
        scanf("%d %d", &ai, &bi);
        v[ai].push_back(bi);
        v[bi].push_back(ai);
    }
    dfs(1, 0);
    for (int i = 1, ai, bi, ci, di;i <= m;i++) {
        scanf("%d %d %d %d", &ai, &bi, &ci, &di);
        int xi = LCA(ai, bi);
        int yi = LCA(ci, di);
        // printf("i:=%d xi:=%d,yi=%d \n", i, xi, yi);
        if ((dis(xi, ci) + dis(xi, di) == dis(ci, di)) || (dis(yi, ai) + dis(yi, bi) == dis(ai, bi))) {
            printf("Y\n");
        }
        else printf("N\n");
    }
    return 0;
}