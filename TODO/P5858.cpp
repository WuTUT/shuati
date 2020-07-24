#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int maxn = 5505;
typedef long long ll;
const ll INF = 0x7f7f7f7f7f7f7ff;
ll f[maxn][maxn];
int s, w, n;
ll a[maxn];
int main()
{
    freopen("data.in", "r", stdin);

    cin >> n >> w >> s;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            f[i][j] = -INF;
        }
    }
    f[1][1] = a[1];
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 1; j <= w; j++)
    //     {

    //         for (int k = 0; k <= s; k++)
    //         {
    //             if (j - k + 1 >= 0)
    //             {
    //                 f[i + 1][j - k + 1] = max(f[i + 1][j - k + 1], f[i][j] + (1ll) * (j - k + 1) * a[i + 1]);
    //             }
    //         }
    //     }
    // }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            for (int k = j - 1; k <= min(w, s + j - 1); k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][k] + a[i] * j);
            }
        }
    }
    ll ans = -INF;
    for (int i = 1; i <= w; i++)
    {
        ans = max(ans, f[n][i]);
    }
    cout << ans << endl;
}