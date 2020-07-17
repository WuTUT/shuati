#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1005;
vector<int> v[maxn];
int f[maxn];
int k, n, m;
int isvis[maxn], isfind;
int ans, tmp;
void dfs(int ind)
{

    if (isvis[ind])
    {
        return;
    }
    isvis[ind] = 1;
    tmp += f[ind];
    if (tmp == k)
    {
        isfind = 1;
        return;
    }
    for (int i = 0; i < v[ind].size(); i++)
    {
        int to = v[ind][i];
        if (!isvis[to])
        {

            dfs(to);
        }
    }
    return;
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> k >> n >> m;
    for (int i = 1, x; i <= k; i++)
    {
        scanf("%d", &x);
        f[x] += 1;
    }
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        v[y].push_back(x);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++)
    {
        // cout << num_scc[i] << endl;
        tmp = isfind = 0;
        memset(isvis, 0, sizeof isvis);
        dfs(i);
        if (isfind)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}