#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int c, n;
const int maxn = 1e3 + 5;
int f[maxn];
int g[maxn][maxn];
int main()
{
    freopen("data.in", "r", stdin);
    while (scanf("%d", &c) != EOF)
    {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                scanf("%d", &g[i][j]);
            }
        }
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i] = 0x7f7f7f7f;
            for (int j = 1; j <= i; j++)
            {
                f[i] = min(f[i], f[j - 1] + g[j][i] + c);
            }
            //printf("%d\n", f[i]);
        }

        printf("%d\n", f[n]);
    }
    return 0;
}