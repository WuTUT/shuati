#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll b, p, k;
ll cal(ll x)
{
    if (x == 1)
        return b % k;
    if (x == 0)
        return 1 % k;

    if (x & 1)
    {
        return cal(x - 1) * b % k;
    }
    else
    {
        int tmp = cal(x >> 1);
        return 1ll * tmp * tmp % k;
    }
}
int main()
{
    cin >> b >> p >> k;
    if (b == 0 && p != 0)
    {
        printf("%lld^%lld mod %lld=0\n", b, p, k);
    }
    else if (b == 0 && p == 0)
    {
        printf("%lld^%lld mod %lld=%lld\n", b, p, k, 1 % k);
    }
    else
    {
        printf("%lld^%lld mod %lld=%lld\n", b, p, k, cal(p));
    }
    return 0;
}