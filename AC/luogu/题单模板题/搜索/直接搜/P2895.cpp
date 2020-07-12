#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int n = 308;
typedef pair<int, int> node;
int dis[n][n];
int t[n][n];
int m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool isvis[n][n];
inline bool isok(int x, int y)
{
    if (dis[x][y] >= t[x][y])
    {
        return false;
    }
    for (int i = 0; i < 4; i++)
    {
        int nex = x + dx[i];
        int ney = y + dy[i];
        if (nex < n && nex >= 0 && ney < n && ney >= 0)
        {
            if (dis[x][y] >= t[nex][ney])
            {
                return false;
            }
        }
    }
    return true;
}
inline bool isend(int x, int y)
{
    if (t[x][y] == 1005)
    {
        for (int i = 0; i < 4; i++)
        {
            int nex = x + dx[i];
            int ney = y + dy[i];
            if (nex < n && nex >= 0 && ney < n && ney >= 0)
            {
                if (t[nex][ney] != 1005)
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> m;
    int xi, yi, ti;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            t[i][j] = 1005;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> xi >> yi >> ti;
        t[xi][yi] = min(ti, t[xi][yi]);
    }
    queue<node> q;
    q.push(node(0, 0));
    isvis[0][0] = true;
    bool isfind = false;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (isend(x, y))
        {
            isfind = true;
            cout << dis[x][y] << endl;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nex = x + dx[i];
            int ney = y + dy[i];
            if (nex < n && nex >= 0 && ney < n && ney >= 0 && !isvis[nex][ney])
            {
                dis[nex][ney] = dis[x][y] + 1;
                if (isok(nex, ney))
                {
                    isvis[nex][ney] = true;
                    q.push(node(nex, ney));
                }
            }
        }
    }
    if (!isfind)
    {
        cout << -1 << endl;
    }
    return 0;
}