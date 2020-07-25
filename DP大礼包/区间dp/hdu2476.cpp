#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 105;
typedef long long ll;
ll f[maxn][maxn], g[maxn];
char s[maxn], a[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    while (scanf("%s%s", a + 1, s + 1) != EOF)
    {
        s[0] = '*';
        int n = strlen(s) - 1;
        memset(f, 0x7f, sizeof f);
        for (int i = 1; i <= n; i++)
        {
            f[i][i] = 1;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                {
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]);
                }
                else
                {
                    for (int k = i; k < j; k++)
                    {
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            g[i] = f[1][i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == s[i])
            {
                g[i] = g[i - 1];
            }
            for (int j = 1; j < i; j++)
            {
                g[i] = min(g[i], g[j] + f[j + 1][i]);
            }
        }
        printf("%lld\n", g[n]);
    }
}