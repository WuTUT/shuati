#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 10005;
vector<int> v[maxn];
vector<int> w[maxn];
int g[maxn][3];
void dfs(int root, int fa) {
    g[root][0] = g[root][1] = 0;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs(to, root);
        int tmp = g[to][0] + w[root][i];
        if (tmp > g[root][0]) {
            g[root][1] = g[root][0];
            g[root][0] = tmp;
        }
        else if (tmp > g[root][1])
            g[root][1] = tmp;
    }

}
void dfs2(int root, int fa) {

    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        if (g[root][0] == g[to][0] + w[root][i]) {
            g[to][2] = max(g[root][2], g[root][1]) + w[root][i];
        }
        else {
            g[to][2] = max(g[root][2], g[root][0]) + w[root][i];
        }
        dfs2(to, root);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {

        for (int i = 0;i <= n;i++) {
            v[i].clear(), w[i].clear();
        }
        for (int i = 2, xi, yi;i <= n;i++) {
            scanf("%d %d", &xi, &yi);
            v[i].push_back(xi);
            w[i].push_back(yi);

            v[xi].push_back(i);
            w[xi].push_back(yi);
        }
        dfs(1, 0);
        dfs2(1, 0);

        for (int i = 1;i <= n;i++) {
            printf("%d\n", max(g[i][0], g[i][2]));
        }
    }
}