#include <iostream>
#include <cstdio>
using namespace std;
const int maxk = 11;
typedef long long ll;
ll M;
ll invb[maxk];
inline ll qmul(ll x, ll y, ll mod)
{
    x %= mod;
    y %= mod;
    return ((x * y - (ll)(((long double)x * y + 0.5) / mod) * mod) % mod + mod) % mod;
}

void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
    }
    else
    {
        exgcd(b, a % b, y, x), y -= a / b * x;
    }
}
ll ina[maxk], inb[maxk];
int main()
{
    freopen("data.in", "r", stdin);
    int k;
    cin >> k;
    M = 1;
    for (int i = 1; i <= k; i++)
    {
        cin >> ina[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> inb[i];
        M *= inb[i];
    }
    ll tmp, sum = 0;
    for (int i = 1; i <= k; i++)
    {
        exgcd(M / inb[i], inb[i], invb[i], tmp);
        sum += qmul(qmul(ina[i], (M / inb[i]), M), invb[i], M);
    }
    printf("%lld\n", (sum % M + M) % M);
}
//P3868