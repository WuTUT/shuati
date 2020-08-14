#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 205;
vector<int> v[maxn];
int b[maxn];
int f[maxn][maxn];
int n, m;
int sz[maxn];
void dfs(int root) {
    f[root][1] = b[root];
    sz[root] = 1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        dfs(to);
        sz[root] += sz[to];

    }
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        for (int j = min(sz[root], m);j > 0;j--) {
            // for (int k = 0;k < j && k <= sz[to];k++) {
            for (int k = min(sz[to], j - 1);k >= 0;k--) {
                f[root][j] = max(f[to][k] + f[root][j - k], f[root][j]);
            }
        }
    }
}
int main() {
    freopen("data.in", "r", stdin);
    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) break;
        m += 1;
        b[0] = 0;
        memset(f, 0, sizeof f);
        memset(sz, 0, sizeof sz);
        for (int i = 0;i <= n;i++) {
            v[i].clear();
        }
        for (int i = 1, ai, bi;i <= n;i++) {
            scanf("%d %d", &ai, &bi);
            v[ai].push_back(i);
            b[i] = bi;
        }
        dfs(0);
        printf("%d\n", f[0][m]);
    }

    return 0;
}
//n个点，每个点有点权
//找m个点的子树，点权和最大
//在子树i 取j个点的最大值
//优化1：这个优化最明显 第二层循环取min(待选的物品数量，背包大小）