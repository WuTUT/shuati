#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 205;
int f[2][maxn][maxn][2];
int n, m, k;
char a[1005], b[maxn];
const int mod = 1000000007;
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> m >> k;
    scanf("%s%s", a + 1, b + 1);
    f[0][0][0][0] = 1;
    f[1][0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int p = i & 1;
        for (int j = 1; j <= m; j++)
        {
            for (int t = 1; t <= k; t++)
            {
                if (a[i] == b[j])
                {
                    f[p][j][t][1] = ((f[p ^ 1][j - 1][t][1] + f[p ^ 1][j - 1][t - 1][0]) % mod + f[p ^ 1][j - 1][t - 1][1]) % mod;
                    f[p][j][t][0] = (f[p ^ 1][j][t][1] + f[p ^ 1][j][t][0]) % mod;
                }
                else
                {
                    f[p][j][t][0] = (f[p ^ 1][j][t][1] + f[p ^ 1][j][t][0]) % mod;
                    f[p][j][t][1] = 0;
                }
            }
        }
    }
    int ans = (f[n & 1][m][k][0] + f[n & 1][m][k][1]) % mod;
    printf("%d\n", ans);
    return 0;
}