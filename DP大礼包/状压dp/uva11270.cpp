#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 105;
typedef long long ll;
ll ans[maxn][maxn];
ll f[maxn][1 << 11];
int m, n;
struct state
{
    int pre, now;
} st[6005];
int tot;
void dfs(int ind, int now, int pre)
{
    if (ind > n)
        return;
    if (ind == n)
    {
        tot++;
        st[tot].now = now, st[tot].pre = pre;
        return;
    }
    dfs(ind + 2, now << 2 | 3, pre << 2 | 3);
    dfs(ind + 1, now << 1 | 1, pre << 1);
    dfs(ind + 1, now << 1, pre << 1 | 1);
}
int main()
{
    freopen("data.in", "r", stdin);
    memset(ans, -1, sizeof ans);
    while (scanf("%d %d", &n, &m) != EOF)
    {
        if (m < n)
        {
            std::swap(n, m);
        }

        if ((m * n) % 2 != 0)
        {
            printf("0\n");
            continue;
        }
        if (ans[m][n] != -1)
        {
            printf("%lld\n", ans[m][n]);
            continue;
        }
        tot = 0;
        dfs(0, 0, 0);
        memset(f, 0, sizeof f);
        //printf("%d\n", tot);
        f[0][(1 << n) - 1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= tot; j++)
            {
                f[i][st[j].now] += f[i - 1][st[j].pre];
            }
        }
        printf("%lld\n", f[m][(1 << n) - 1]);
        ans[m][n] = f[m][(1 << n) - 1];
    }
    return 0;
}