#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> v[maxn];
struct Egde
{
    int fr, to;
} edges[maxn];
int n, m;
int low[maxn], dfn[maxn], scc[maxn], sccnum, stk[maxn], top, index;
int numofscc[maxn];
int ans[maxn];
void tarjan(int root)
{
    if (dfn[root])
    {
        return;
    }
    low[root] = dfn[root] = ++index;
    stk[++top] = root;
    for (int i = 0; i < v[root].size(); i++)
    {
        int to = v[root][i];
        if (!dfn[to])
        {
            tarjan(to);
            low[root] = min(low[root], low[to]);
        }
        else if (!scc[to])
        {
            low[root] = min(low[root], dfn[to]);
        }
    }
    if (dfn[root] == low[root])
    {
        sccnum++;
        while (1)
        {
            int x = stk[top--];
            scc[x] = sccnum;
            numofscc[sccnum] = max(numofscc[sccnum], x);
            if (x == root)
                break;
        }
    }
}
vector<int> nv[maxn];

int in[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        v[y].push_back(x);
        edges[i].fr = y, edges[i].to = x;
    }
    for (int i = 1; i <= n; i++)
    {
        tarjan(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int fr = edges[i].fr, to = edges[i].to;
        if (scc[fr] != scc[to])
        {
            in[scc[to]]++;
            nv[scc[fr]].push_back(scc[to]);
        }
    }
    // for (int i = 1; i <= sccnum; i++)
    // {
    //     for (int j = 0; j < nv[i].size(); j++)
    //     {
    //         cout << nv[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //cout << sccnum << endl;

    queue<int> q;
    for (int i = 1; i <= sccnum; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < nv[x].size(); i++)
        {
            int to = nv[x][i];
            numofscc[to] = max(numofscc[to], numofscc[x]);
            if (--in[to] == 0)
            {
                q.push(to);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] = numofscc[scc[i]];
        // cout << ans[i] << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
}
//正向建图不行，反向建图行！
//神他妈的tarjan 。。。
//dfs一次就好了呀