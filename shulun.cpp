#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
        x = 1, y = 0;
    else
        exgcd(b, a % b, y, x), y = y - a / b * x;
}
ll fm(ll x, ll pow, ll mod)
{
    if (pow == 1)
        return x % mod;

    if (pow % 2 == 0)
    {
        ll tmp = fm(x, pow / 2, mod);
        return tmp * tmp % mod;
    }
    else
    {
        return fm(x, pow - 1, mod) * x % mod;
    }
}
const int maxn = 3e6 + 10;
ll inv[maxn];
int main()
{
    ll x, y;
    ll a, p;
    cin >> a >> p;
    inv[1] = 1;
    printf("1\n");
    // for (ll i = 1; i <= a; i++)
    // {
    //     //exgcd(i, p, x, y);
    //     //x = fm(i, p - 2, p);
    //     //x = (x % p + p) % p;
    //     printf("%lld\n", x);
    // }
    for (ll i = 2; i <= a; i++)
    {
        inv[i] = (p - p / i) * inv[p % i] % p;
        printf("%lld\n", inv[i]);
    }
    return 0;
}