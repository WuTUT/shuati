#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;
int n, m;
vector<int> v[maxn];

int dfn[maxn << 1], idx[maxn];
int dep[maxn << 1];
int dfstot;
int lg[maxn << 1];
int dp[maxn << 1][21];
void dfs(int root, int fa, int dis) {
    dfn[++dfstot] = root;
    idx[root] = dfstot;
    dep[dfstot] = dis;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs(to, root, dis + 1);
        dfn[++dfstot] = root;
        dep[dfstot] = dis;
    }
}
inline int cmpdep(int x, int y) {
    return dep[x] < dep[y] ? x : y;
}
void RMQ(int n) {
    for (int i = 1;i <= n;i++) {
        dp[i][0] = i;
    }
    for (int j = 1;(1 << j) <= n;j++) {
        for (int i = 1;i + (1 << j) - 1 <= n;i++) {
            dp[i][j] = cmpdep(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
        }
    }
}
inline int query(int x, int y) {
    int k = lg[y - x + 1];
    return cmpdep(dp[x][k], dp[y - (1 << k) + 1][k]);
}
int LCA(int x, int y) {
    x = idx[x];
    y = idx[y];
    if (x > y)
        return dfn[query(y, x)];
    else
        return dfn[query(x, y)];
}
vector<pair<int, int> > S;
int main() {
    freopen("data.in", "r", stdin);
    lg[0] = lg[1] = 0;
    for (int i = 2;i <= maxn * 2;i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0;i <= n;i++) {
            v[i].clear();
        }
        dfstot = 0;
        for (int i = 1, xi, yi;i < n;i++) {
            scanf("%d %d", &xi, &yi);
            v[xi].push_back(yi);
            v[yi].push_back(xi);
        }
        dfs(1, -1, 1);
        RMQ(2 * n - 1);
        int k1, k2;
        for (int i = 1;i <= m;i++) {
            int ans = 0;
            S.clear();
            scanf("%d", &k1);
            for (int j = 1, ai;j <= k1;j++) {
                scanf("%d", &ai);
                S.push_back(make_pair(idx[ai], ai));
            }
            sort(S.begin(), S.end());
            scanf("%d", &k2);
            for (int j = 1, bi;j <= k2;j++) {
                scanf("%d", &bi);
                int it = lower_bound(S.begin(), S.end(), make_pair(idx[bi], bi)) - S.begin();
                if (it != S.size())
                    ans = max(ans, dep[idx[LCA(bi, S[it].second)]]);
                it--;
                if (it >= 0)
                    ans = max(ans, dep[idx[LCA(bi, S[it].second)]]);

            }

            printf("%d\n", ans);
        }
    }
    return 0;
}