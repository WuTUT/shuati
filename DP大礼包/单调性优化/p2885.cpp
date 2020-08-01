#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n, c;
const int maxh = 101, maxn = 100005;
int a[maxn];
int f[maxh];
int pre1[maxh], pre2[maxh];
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    memset(f, 0x7f, sizeof f);
    for (int i = 0; i < maxh; i++)
    {
        f[i] = 0;
        pre1[i] = -c * i;
        pre2[i] = c * i;
    }
    for (int i = 1; i <= n; i++)
    {

        memset(f, 0x7f, sizeof f);
        for (int j = a[i]; j < maxh; j++)
        {
            f[j] = min(f[j], pre1[j] + (j - a[i]) * (j - a[i]) + c * j);
            f[j] = min(f[j], pre2[j] + (j - a[i]) * (j - a[i]) - c * j);
        }
        pre1[0] = f[0];
        for (int j = 1; j < maxh; j++)
        {
            pre1[j] = min(pre1[j - 1], f[j] - c * j);
        }
        pre2[maxh - 1] = f[maxh - 1] + (maxh - 1) * c;
        for (int j = maxh - 2; j >= 0; j--)
        {
            pre2[j] = min(pre2[j + 1], f[j] + c * j);
        }
    }
    int ans = 0x7f7f7f7f;
    for (int i = 0; i < maxh; i++)
    {
        ans = min(f[i], ans);
    }
    cout << ans << endl;
}