#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100005;
int v[105], c[105];
int sum[maxn], f[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    int n, m;
    while ((scanf("%d%d", &n, &m) != EOF) && (n || m))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &v[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &c[i]);
        }

        memset(f, 0, sizeof f);
        int ans = 0;
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            memset(sum, 0, sizeof sum);
            for (int j = v[i]; j <= m; j++)
            {
                if (!f[j] && f[j - v[i]] && sum[j - v[i]] < c[i])
                {
                    f[j] = 1, sum[j] = sum[j - v[i]] + 1;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}