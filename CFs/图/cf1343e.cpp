#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <assert.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int h[N], e[N * 2], ne[N * 2], idx;
int p[N * 2];
int n, m, st, md, ed;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dis1[N], dis2[N], dis3[N];
ll s[N * 2];
void bfs(int st, int dis[])
{

    for (int i = 1; i <= n; i++)
        dis[i] = 0x3f3f3f3f;
    dis[st] = 0;

    queue<int> q;
    q.push(st);
    while (q.size())
    {
        int x = q.front();
        q.pop();

        for (int i = h[x]; ~i; i = ne[i])
        {
            int to = e[i];
            if (dis[to] > dis[x] + 1)
            {
                q.push(to);
                dis[to] = dis[x] + 1;
            }
        }
    }
}
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        memset(h, -1, sizeof h);

        idx = 0;

        cin >> n >> m >> st >> md >> ed;
        for (int i = 1; i <= m; i++)
            scanf("%d", &p[i]);
        for (int i = 0, x, y; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            add(x, y), add(y, x);
        }
        sort(p + 1, p + 1 + m);
        for (int i = 1; i <= m; i++)
        {
            s[i] = s[i - 1] + p[i];
        }
        bfs(st, dis1);
        bfs(md, dis2);
        bfs(ed, dis3);
        ll ans = LONG_LONG_MAX;

        for (int i = 1; i <= n; i++)
        {
            if (dis1[i] + dis2[i] + dis3[i] > m)
                continue;
            // cout << i << " " << dis1[i] << " " << dis2[i] << " " << dis3[i] << " " << endl;
            ll sum = s[dis2[i]] * 2 + s[dis1[i] + dis2[i] + dis3[i]] - s[dis2[i]];
            if (ans > sum)
            {
                // cout << "update by " << i << " to sum " << sum << endl;
                ans = sum;
            }
        }

        cout << ans << endl;
    }

    return 0;
}