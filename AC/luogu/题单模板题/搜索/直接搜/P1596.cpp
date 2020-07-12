#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 105;
char f[maxn][maxn];
int ans;
int isvis[maxn][maxn];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m;
void dfs(int row, int col)
{
    for (int i = 0; i < 8; i++)
    {
        int nex = row + dx[i];
        int ney = col + dy[i];
        if (nex < n && nex >= 0 && ney < m && ney >= 0 && !isvis[nex][ney] && f[nex][ney] == 'W')
        {
            isvis[nex][ney] = 1;
            dfs(nex, ney);
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &f[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!isvis[i][j] && f[i][j] == 'W')
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
}
//联通块  紫书油田题一模一样  这次手速还可以