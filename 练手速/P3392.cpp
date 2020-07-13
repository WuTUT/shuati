#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
const int maxn = 52;
char f[maxn][maxn];
int g[maxn][3];
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
            if (f[i][j] == 'W')
            {
                g[i][1]++, g[i][2]++;
            }
            if (f[i][j] == 'B')
            {
                g[i][0]++, g[i][2]++;
            }
            if (f[i][j] == 'R')
            {
                g[i][0]++, g[i][1]++;
            }
        }
    }
    int ans = 0x7f7f7f7f;
    for (int i = 0; i < n - 2; i++)
    {

        for (int j = i + 1; j < n - 1; j++)
        {
            int mtp = 0;
            for (int l = 0; l <= i; l++)
            {
                mtp += g[l][0];
            }
            for (int l = i + 1; l <= j; l++)
            {
                mtp += g[l][1];
            }
            for (int l = j + 1; l < n; l++)
            {
                mtp += g[l][2];
            }
            ans = min(ans, mtp);
        }
    }
    cout << ans << endl;
}