#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 105;
vector<int> v[maxn];
int maxheight;
int bfs(int root)
{
    int bsz = 1;
    queue<int> q, faq;
    q.push(root);
    faq.push(0);
    while (!q.empty())
    {
        int qsize = q.size();
        bsz = max(qsize, bsz);
        for (int i = 0; i < qsize; i++)
        {
            int x = q.front();
            q.pop();
            int fa = faq.front();
            faq.pop();
            for (int i = 0; i < v[x].size(); i++)
            {
                if (v[x][i] == fa)
                    continue;
                q.push(v[x][i]);
                faq.push(x);
            }
        }
    }
    return bsz;
}
int dep[maxn];
int dp[maxn][22];
void dfs(int root, int fa)
{
    dep[root] = dep[fa] + 1;
    maxheight = max(maxheight, dep[root]);
    for (int i = 1; (1 << i) <= dep[root]; i++)
    {
        dp[root][i] = dp[dp[root][i - 1]][i - 1];
    }
    for (int i = 0; i < v[root].size(); i++)
    {
        int to = v[root][i];
        if (to == fa)
            continue;
        dp[to][0] = root;
        dfs(to, root);
    }
}
int lca(int x, int y)
{
    if (dep[y] > dep[x])
    {
        std::swap(x, y);
    }
    for (int i = 20; i >= 0; i--)
    {
        if (dep[dp[x][i]] >= dep[y])
        {
            x = dp[x][i];
        }
        if (x == y)
            return x;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (dp[x][i] != dp[y][i])
        {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}
int main()
{
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    cout << maxheight << endl;
    cout << bfs(1) << endl;

    int u, v;
    cin >> u >> v;

    int bofa = lca(u, v);
    //cout << bofa << endl;
    int ans = (dep[u] - dep[bofa]) * 2 + dep[v] - dep[bofa];
    cout << ans << endl;
}
//P3884
//LCA  f[root][i]=f[f[root][i-1]][i-1];
//    f[to][0]=root!!! 不是 fa