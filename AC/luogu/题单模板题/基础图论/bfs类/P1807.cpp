#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
const int maxn = 1505;
vector<int> v[maxn];
vector<int> w[maxn];
int ma[maxn][maxn];
int n, m;
int in[maxn];
int f[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    memset(ma, -1, sizeof ma);
    cin >> n >> m;
    for (int i = 1, x, y, z; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if (ma[x][y] != -1)
        {
            w[x][ma[x][y]] = max(w[x][ma[x][y]], z);
        }
        else
        {
            v[x].push_back(y);
            w[x].push_back(z);
            in[y]++;
            ma[x][y] = v[x].size() - 1;
        }
    }
    queue<int> q;

    for (int i = 2; i <= n; i++)
    {
        if (in[i] == 0)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                in[v[i][j]]--;
            }
        }
    }

    int isfind = 0;
    q.push(1);
    f[n] = -1;
    while (!q.empty())
    {
        int x = q.front();
        // if (x == n)
        // {
        //     isfind = 1;
        //     break;
        // }
        q.pop();
        for (int i = 0; i < v[x].size(); i++)
        {
            int to = v[x][i];
            f[to] = max(f[to], f[x] + w[x][i]);
            if (--in[to] == 0)
            {
                q.push(to);
            }
        }
    }
    cout << f[n] << endl;
    // if (isfind)
    // {
    //     cout << f[n];
    // }
    // else
    // {
    //     cout << -1;
    // }
    return 0;
}