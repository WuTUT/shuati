#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int dep[maxn];
vector<int> v[maxn];
double f[maxn];
double ans;
void dfs(int root, int fa) {

    dep[root] = dep[fa] + 1;
    ans += 1.0 / dep[root];
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs(to, root);

    }
}
int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1, xi, yi;i < n;i++) {
        scanf("%d %d", &xi, &yi);
        v[xi].push_back(yi);
        v[yi].push_back(xi);
    }

    dfs(1, 0);
    printf("%.8lf\n", ans);
    return 0;
}