#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int son[maxn];
vector<int> v[maxn];
double f[maxn];
double ans;
void dfs1(int root, int fa) {

    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs1(to, root);
        son[root]++;
    }
}
void dfs2(int root, int fa) {

    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs2(to, root);
        f[root] += (f[to] + 1.0) / son[root];
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

    dfs1(1, 0);


    dfs2(1, 0);
    printf("%.8lf\n", f[1]);
    return 0;
}