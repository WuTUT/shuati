#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 5;
vector<int> v[maxn];
typedef long long ll;
ll g[maxn], f[maxn];
int sz[maxn];
int n;
ll ans;int ansi;
void dfs1(int root, int fa) {
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs1(to, root);
        sz[root] += sz[to] + 1;
        f[root] += f[to] + sz[to] + 1;
    }
}
void dfs2(int root, int fa) {
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        g[to] = f[to] + g[root] - (f[to] + sz[to] + 1) + (n - sz[to] - 1);
        dfs2(to, root);
    }
}

int main() {
    freopen("data.in", "r", stdin);
    cin >> n;
    int xi, yi;
    for (int i = 1;i < n;i++) {
        scanf("%d %d", &xi, &yi);
        v[xi].push_back(yi);
        v[yi].push_back(xi);
    }
    dfs1(1, 0);
    // for (int i = 1;i <= n;i++) {
    //     printf("%d ", f[i]);
    // }
    // printf("\n");
    g[1] = f[1];

    dfs2(1, 0);
    ans = 0, ansi = 0;
    for (int i = 1;i <= n;i++) {
        //  printf("%d ", g[i]);
        if (g[i] > ans) {
            ans = g[i], ansi = i;
        }
    }
    //printf("\n");
    printf("%d\n", ansi);
    //printf("%d\n", ans);
    return 0;
}