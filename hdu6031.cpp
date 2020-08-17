#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> v[maxn];
int n, m;
int a[maxn], b[maxn];
int dep[maxn];
int dfs_clk;
int id[maxn], de[maxn], vs[maxn];
int dp[maxn << 1][20];
void RMQ(int NN) {
    for (int i = 1; i <= NN; i++)
        dp[i][0] = i;
    for (int j = 1; (1 << j) <= NN; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= NN; i++)
        {
            int a = dp[i][j - 1];
            int b = dp[i + (1 << (j - 1))][j - 1];
            if (de[a] <= de[b])
                dp[i][j] = a;
            else
                dp[i][j] = b;
        }
    }
}
int query(int L, int R)
{
    //查询L <= i <= R 里面使得depth[i]最小的值 返回对应下标
    int k = 0;
    while ((1 << (k + 1)) <= R - L + 1) k++;
    int a = dp[L][k];
    int b = dp[R - (1 << k) + 1][k];
    if (de[a] <= de[b])
        return a;//返回下标
    else
        return b;
}
int LCA(int u, int v)
{
    int x = id[u];//比较大小 小的当作左区间 大的当作右区间
    int y = id[v];
    if (x > y)
        return vs[query(y, x)];
    else
        return vs[query(x, y)];
}

void dfs(int root, int fa, int d) {
    id[root] = dfs_clk;
    vs[dfs_clk] = root;
    de[dfs_clk++] = d;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dep[to] = dep[root] + 1;
        dfs(to, root, d + 1);
        vs[dfs_clk] = root;
        de[dfs_clk++] = d;
    }
}
int main() {
    freopen("data.in", "r", stdin);
    while (scanf("%d %d", &n, &m) != EOF) {

        for (int i = 0;i <= n;i++) {
            v[i].clear();
        }
        dfs_clk = 1;

        for (int i = 1, xi, yi;i < n;i++) {
            scanf("%d %d", &xi, &yi);
            v[xi].push_back(yi);
            v[yi].push_back(xi);
        }
        dep[1] = 0;
        dfs(1, 0, 0);

        RMQ(dfs_clk - 1);
        int k1, k2;
        for (int i = 1;i <= m;i++) {
            int ans = 0;
            int depa = 0, depb = 0;
            scanf("%d", &k1);
            for (int j = 1;j <= k1;j++) {
                scanf("%d", &a[j]);
                depa = max(depa, dep[a[j]]);
            }
            scanf("%d", &k2);
            for (int j = 1;j <= k2;j++) {
                scanf("%d", &b[j]);
                depb = max(depb, dep[b[j]]);
            }
            for (int j = 1;j <= k1;j++) {
                for (int l = 1;l < k2;l++) {
                    if (depa == dep[a[j]] && depb == dep[b[l]]) {
                        ans = max(ans, dep[LCA(a[j], b[l])]);
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}