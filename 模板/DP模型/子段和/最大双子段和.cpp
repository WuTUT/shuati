#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
typedef long long ll;
ll a[maxn], f[maxn], g[maxn];
ll ansl[maxn], ansr[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    ansl[0] = LLONG_MIN;
    ansr[n + 1] = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        f[i] = max(a[i], f[i - 1] + a[i]);
        ansl[i] = max(ansl[i - 1], f[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        g[i] = max(a[i], g[i + 1] + a[i]);
        ansr[i] = max(ansr[i + 1], g[i]);
    }
    ll ans = LLONG_MIN;
    for (int i = 2; i < n; i++)
    {
        ans = max(ans, ansl[i - 1] + ansr[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
//P2624 知道前1~i最大ansl[i] 和后i~n 最大 ansr[i] 则枚举端点 ansl[i-1]+ansr[i+1]
//这个题目要求相隔至少为1，因此有个i-1 和 i+1
//ansl[i] = max(ansl[i-1],f[i]) f[i] 为以i结尾最大子段和