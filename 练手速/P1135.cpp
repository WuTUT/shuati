#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 255;
vector<int> v[maxn];
int n, s, t;
int isvis[maxn];
int dis[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> s >> t;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a == 0)
            continue;
        if (i + a <= n)
        {
            v[i].push_back(i + a);
        }
        if (i - a >= 1)
        {
            v[i].push_back(i - a);
        }
    }
    memset(dis, 0x7f, sizeof dis);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    isvis[s] = 1;
    while (!q.empty())
    {
        int qsize = q.size();
        for (int j = 0; j < qsize; j++)
        {
            int x = q.front();

            q.pop();
            for (int i = 0; i < v[x].size(); i++)
            {
                if (isvis[v[x][i]])
                    continue;
                isvis[v[x][i]] = 1;
                dis[v[x][i]] = dis[x] + 1;
                q.push(v[x][i]);
            }
        }
    }
    if (!isvis[t])
    {
        cout << -1 << endl;
    }
    else
        cout << dis[t] << endl;
    return 0;
}