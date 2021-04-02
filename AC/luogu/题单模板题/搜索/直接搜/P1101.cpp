#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;
const int maxn = 104;
char s[8] = "yizhong";
char f[maxn][maxn];
char ans[maxn][maxn];
int n;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
void dfs(int x, int y, int len, int dir)
{
    if (len == 7)
    {
        //printf("this %d %d\n", x, y);
        for (int i = 0; i < 8; i++)
        {
            ans[x - dx[dir] * i][y - dy[dir] * i] = s[7 - i];
        }
        return;
    }
    if (x >= n || y >= n || x < 0 || y < 0)
    {
        return;
    }
    if (f[x][y] == s[len])
    {
        dfs(x + dx[dir], y + dy[dir], len + 1, dir);
    }
    return;
}
int main()
{
    //freopen("data.in", "r", stdin);
    cin >> n;
    //printf("%d\n", n);
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
            for (int k = 0; k < 8; k++)
            {
                dfs(i, j, 0, k);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j])
            {
                printf("%c", ans[i][j]);
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}