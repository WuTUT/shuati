#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e6 + 5;
int vis[maxn];
int n, m;
int top;
vector<int> v[maxn];
void dfs(int root)
{

    if (vis[root])
        return;
    vis[root] = 1;
    printf("%d", root);
    ++top;

    {
        printf(" ");
    }

    for (int i = 0; i < v[root].size(); i++)
    {
        dfs(v[root][i]);
    }
}

int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size())
        {
            sort(v[i].begin(), v[i].end());
        }
    }
    dfs(1);
    printf("\n");
    memset(vis, 0, sizeof vis);
    top = 0;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int x = q.front();

        q.pop();
        printf("%d", x);
        ++top;
        if (top == n)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
        for (int i = 0; i < v[x].size(); i++)
        {
            if (vis[v[x][i]])
                continue;
            vis[v[x][i]] = 1;
            q.push(v[x][i]);
        }
    }

    return 0;
}