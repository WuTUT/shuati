#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int maxn = 500005;
vector<int> v[maxn];
vector<double> w[maxn];
double q[maxn];
double f[maxn];
//double ff[maxn];
double g[maxn];
void dfs1(int root, int fa) {
    //ff[root] = 1.0;
    f[root] = (1.0 - q[root]);
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs1(to, root);
        f[root] *= f[to] + (1.0 - f[to]) * (1.0 - 1.0 * w[root][i]);
        //ff[root] *= f[to] * w[root][i] + (1.0 - w[root][i]);
    }
}
void dfs2(int root, int fa) {
    double tmp;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        tmp = 1.0 * g[root] * f[root] / (f[to] + (1.0 - f[to]) * (1.0 - w[root][i]));
        //tmp = g[root] * ff[root] * (1.0 - q[root]) / (f[to] + (1.0 - f[to]) * (1.0 - w[root][i]));
        g[to] = 1.0 - w[root][i] + w[root][i] * tmp;

        dfs2(to, root);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1, ai, bi, pi;i <= n - 1;i++) {
        scanf("%d %d %d", &ai, &bi, &pi);

        v[ai].push_back(bi);
        v[bi].push_back(ai);
        w[ai].push_back(pi / 100.0);
        w[bi].push_back(pi / 100.0);
    }
    for (int i = 1, qi;i <= n;i++)
        scanf("%d", &qi), q[i] = qi / 100.0;
    dfs1(1, 0);
    g[1] = 1.0;
    dfs2(1, 0);
    double ans = 0.0;
    for (int i = 1;i <= n;i++) {
        ans += 1.0 - f[i] * g[i];
    }
    printf("%.6lf\n", ans);
    return 0;
}