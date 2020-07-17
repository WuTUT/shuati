#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1e4 + 5;
vector<int> v[maxn];
int t[maxn];
int ans[maxn];
int n;
int in[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    int raw;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &raw, &t[i]);

        while (scanf("%d", &raw))
        {
            if (raw == 0)
                break;
            else
            {
                v[raw].push_back(i);
                in[i]++;
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
            ans[i] = t[i];
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < v[x].size(); i++)
        {
            int nex = v[x][i];

            in[nex]--;
            ans[nex] = max(ans[nex], t[nex] + ans[x]);
            if (in[nex] == 0)
            {
                q.push(nex);
            }
        }
    }
    //cout << ans[2] << ans[3] << ans[4] << endl;
    int maxans = 0;
    for (int i = 1; i <= n; i++)
    {
        maxans = max(maxans, ans[i]);
    }
    cout << maxans << endl;
}

//坑点1  先把入度为0的放进去
//坑点2 最大的不一定是ans【n】