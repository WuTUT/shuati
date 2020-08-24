#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int sz[maxn];
vector<int> v[maxn];
double f[maxn];
void dfs(int root, int fa) {

    sz[root] = 1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs(to, root);
        sz[root] += sz[to];
    }
}
void dfs2(int root, int fa) {

    f[root] = f[fa] + 1 + 0.5 * (sz[fa] - 1 - sz[root]);
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs2(to, root);

    }
}
int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 2, pi;i <= n;i++) {
        scanf("%d", &pi);
        v[i].push_back(pi);
        v[pi].push_back(i);
    }
    dfs(1, 0);
    sz[0] = sz[1] + 1;
    f[0] = 0;
    dfs2(1, 0);
    for (int i = 1;i <= n;i++) {
        printf("%.8lf ", f[i]);
    }
    return 0;
}