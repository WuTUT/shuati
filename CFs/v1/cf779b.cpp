#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll f[1005];

void pre(int n)
{
    ll x = 1;
    for (int i = 4; i <= n; i += 2)
    {
        x = x * (i / 2) % mod;
        f[i] = x * x % mod;
    }
}
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int T;
    cin >> T;
    f[2] = 1;
    pre(1000);
    while (T--)
    {

        int n;
        cin >> n;

        printf("%lld\n", f[n]);
    }
    return 0;
}