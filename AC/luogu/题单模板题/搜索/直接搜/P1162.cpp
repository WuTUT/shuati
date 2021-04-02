#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 35;
int f[maxn][maxn];
int ans[maxn][maxn];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
void dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] == 1 || ans[x][y] == -1)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        ans[x][y] = -1;
        dfs(x + dx[i], y + dy[i]);
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> f[i][j];
            ans[i][j] = f[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
            {
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j] == 0)
            {
                printf("2");
            }
            else if (ans[i][j] == 1)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
            if (j != n)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}