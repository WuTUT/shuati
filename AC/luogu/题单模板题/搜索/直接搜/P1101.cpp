#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 105;
const char s[8] = "yizhong";
char f[maxn][maxn];
int vis[maxn][maxn];
int n;
void dfs(int row, int col, int kt, int dir)
{
    if (kt == 7)
    {

        if (dir == 1)
            for (int i = 1; i <= 7; i++)
                vis[row + i][col] = 1;
        else if (dir == 2)
            for (int i = 1; i <= 7; i++)
                vis[row + i][col - i] = 1;
        else if (dir == 3)
            for (int i = 1; i <= 7; i++)
                vis[row][col - i] = 1;
        else if (dir == 4)
            for (int i = 1; i <= 7; i++)
                vis[row - i][col - i] = 1;
        else if (dir == 5)
            for (int i = 1; i <= 7; i++)
                vis[row - i][col] = 1;
        else if (dir == 6)
            for (int i = 1; i <= 7; i++)
                vis[row - i][col + i] = 1;
        else if (dir == 7)
            for (int i = 1; i <= 7; i++)
                vis[row][col + i] = 1;
        else if (dir == 8)
            for (int i = 1; i <= 7; i++)
                vis[row + i][col + i] = 1;

        return;
    }
    if (row >= n || row < 0 || col < 0 || col >= n)
    {
        return;
    }

    if (s[kt] == f[row][col])
    {
        if (dir == 1)
        {
            dfs(row - 1, col, kt + 1, dir);
        }
        else if (dir == 2)
        {
            dfs(row - 1, col + 1, kt + 1, dir);
        }
        else if (dir == 3)
        {
            dfs(row, col + 1, kt + 1, dir);
        }
        else if (dir == 4)
        {
            dfs(row + 1, col + 1, kt + 1, dir);
        }
        else if (dir == 5)
        {
            dfs(row + 1, col, kt + 1, dir);
        }
        else if (dir == 6)
        {
            dfs(row + 1, col - 1, kt + 1, dir);
        }
        else if (dir == 7)
        {
            dfs(row, col - 1, kt + 1, dir);
        }
        else if (dir == 8)
        {
            dfs(row - 1, col - 1, kt + 1, dir);
        }
    }

    return;
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
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int dir = 1; dir <= 8; dir++)
            {
                dfs(i, j, 0, dir);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                f[i][j] = '*';
            }
            cout << f[i][j];
        }
        cout << endl;
    }
}