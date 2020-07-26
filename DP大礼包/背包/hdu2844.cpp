#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100005;
int v[105], c[105];
int w[maxn], f[maxn];
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
        int top = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            for (tmp = 1; tmp * 2 < c[i] + 1; tmp *= 2)
            {
                w[++top] = tmp * v[i];
            }
            w[++top] = (c[i] - (tmp - 1)) * v[i];
        }

        memset(f, 0, sizeof f);
        int ans = 0;
        f[0] = 1;
        for (int i = 1; i <= top; i++)
        {

            for (int j = m; j >= w[i]; j--)
            {
                if (!f[j])
                    f[j] = f[j - w[i]];
            }
        }
        for (int i = 1; i <= m; i++)
        {
            // printf("%d ", f[i]);
            ans += f[i];
        }
        cout << ans << endl;
    }
}