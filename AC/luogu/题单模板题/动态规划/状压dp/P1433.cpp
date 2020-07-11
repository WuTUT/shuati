#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 16;
inline double getdis(double x1, double x2, double y1, double y2)
{
    return sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
}
double x[maxn], y[maxn];
int n;
double f[1 << maxn][maxn];
// int vis[maxn];
double ans = 1.0 * 0x7f7f7f7f7f7f7f;
// void dfs(int kt, double tmp, double row, double col)
// {
//     if (tmp > ans)
//     {
//         return;
//     }
//     if (kt == n)
//     {
//         ans = min(ans, tmp);
//         return;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//         {
//             vis[i] = 1;
//             dfs(kt + 1, tmp + getdis(row, x[i], col, y[i]), x[i], y[i]);
//             vis[i] = 0;
//         }
//     }
// }
// int main()
// {
//     freopen("data.in", "r", stdin);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%lf%lf", &x[i], &y[i]);
//     }
//     dfs(0, 0.0, 0.0, 0.0);
//     printf("%.2lf\n", ans);
// }
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    memset(f, 0x7f, sizeof f);
    for (int i = 1; i <= n; i++)
    {
        f[1 << (i - 1)][i] = getdis(0, x[i], 0, y[i]);
    }
    for (int i = 1; i < (1 << n); i++)
    {
        for (int j = 0; (1 << j) <= i; j++)
        {
            if (((1 << j) & i))
            {
                int ss = i - (1 << j);
                for (int k = 0; (1 << k) <= ss; k++)
                {
                    if ((ss & (1 << k)))
                    {
                        f[i][j + 1] = min(f[i][j + 1], f[ss][k + 1] + getdis(x[j + 1], x[k + 1], y[j + 1], y[k + 1]));
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, f[(1 << n) - 1][i]);
    }
    printf("%.2lf\n", ans);
}
//差不多的TSP 问题，注意枚举是第一层循环应该是遍历全集，并不会影响状态后继性的要求