#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll f[maxn], a[maxn], g[maxn], h[maxn];
int n;
ll getTWO()
{
    ll t1, t2;
    t1 = t2 = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > t1)
        {
            t2 = t1;
            t1 = a[i];
        }
        else if (a[i] > t2)
        {
            t2 = a[i];
        }
    }
    return t1 + t2;
}
int main()
{
    freopen("data.in", "r", stdin);

    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    f[0] = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        f[i] = max(f[i - 1], 0ll) + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = max(f[i - 1], f[i]);
    }
    h[n + 1] = LLONG_MIN;
    for (int i = n; i >= 1; i--)
    {
        h[i] = max(h[i + 1], 0ll) + a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        h[i] = max(h[i + 1], h[i]);
    }
    ll ans1 = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        ans1 = max(ans1, f[i] + h[i + 1]);
    }
    // cout << ans1 << endl;

    f[0] = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        f[i] = min(f[i - 1], 0ll) + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = min(f[i - 1], f[i]);
    }
    h[n + 1] = LLONG_MAX;
    for (int i = n; i >= 1; i--)
    {
        h[i] = min(h[i + 1], 0ll) + a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        h[i] = min(h[i + 1], h[i]);
    }

    ll ans2 = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        ans2 = min(ans2, h[i + 1] + f[i]);
    }
    if (sum == ans2)
    {
        cout << getTWO() << endl;
    }
    else
    {
        ans2 = sum - ans2;
        cout << max(ans1, ans2) << endl;
    }

    return 0;
}