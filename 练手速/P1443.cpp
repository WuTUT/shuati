#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 405;
int xs, xy;
int m, n;
int g[maxn][maxn];
int isvis[maxn][maxn];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
typedef pair<int, int> node;
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> m >> xs >> xy;
    xs--;
    xy--;
    memset(g, -1, sizeof g);
    g[xs][xy] = 0;

    queue<node> q;
    q.push(node(xs, xy));
    isvis[xs][xy] = 1;
    while (!q.empty())
    {

        int x = (q.front()).first;
        int y = (q.front()).second;
        q.pop();
        for (int j = 0; j < 8; j++)
        {
            int nex = x + dx[j];
            int ney = y + dy[j];
            if (nex >= 0 && nex < n && ney >= 0 && ney < m && !isvis[nex][ney])
            {
                // cout << nex << " " << ney << " \n";
                isvis[nex][ney] = 1;
                g[nex][ney] = g[x][y] + 1;
                q.push(node(nex, ney));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%-5d", g[i][j]);
        }
        printf("\n");
    }
}