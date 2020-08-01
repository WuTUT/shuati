#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, v, e;
const int maxn = 2005, maxv = 305;
const double inf = 1e17 + 5;
int c[maxn], d[maxn];
double p[maxn];
int g[maxv][maxv];
double f[maxn][maxn][2];
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> m >> v >> e;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &p[i]);
    }
    memset(g, 0x3f, sizeof g);

    for (int i = 1, ai, bi, wi; i <= e; i++)
    {
        scanf("%d%d%d", &ai, &bi, &wi);
        g[bi][ai] = g[ai][bi] = min(g[ai][bi], wi);
    }
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for (int i = 1; i <= v; i++)
    {
        g[i][i] = 0;
    }
    // for (int i = 1; i <= v; i++)
    // {
    //     for (int j = 1; j <= v; j++)
    //     {
    //         printf("%d ", g[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j][0] = f[i][j][1] = inf;
        }
    }
    f[1][1][1] = 0;
    f[1][0][0] = 0;

    //f[1][1] = f[1][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j][1] = min(f[i][j][1], f[i - 1][j - 1][1] + g[c[i - 1]][d[i]] * (1 - p[i - 1]) * p[i] + g[d[i - 1]][c[i]] * p[i - 1] * (1 - p[i]) + g[d[i - 1]][d[i]] * p[i - 1] * p[i] + g[c[i - 1]][c[i]] * (1 - p[i - 1]) * (1 - p[i]));
            f[i][j][1] = min(f[i][j][1], f[i - 1][j - 1][0] + g[c[i - 1]][d[i]] * p[i] + (1 - p[i]) * g[c[i - 1]][c[i]]);
        }
        for (int j = 0; j <= m; j++)
        {
            f[i][j][0] = min(f[i][j][0], f[i - 1][j][1] + g[c[i - 1]][c[i]] * (1 - p[i - 1]) + g[d[i - 1]][c[i]] * p[i - 1]);
            f[i][j][0] = min(f[i][j][0], f[i - 1][j][0] + g[c[i - 1]][c[i]]);
        }
    }
    double ans = inf;
    for (int j = 0; j <= m; j++)
    {
        ans = min(ans, min(f[n][j][0], f[n][j][1]));
    }

    printf("%.2lf\n", ans);
    return 0;
}