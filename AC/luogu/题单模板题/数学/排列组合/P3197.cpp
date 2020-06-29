#include <iostream>
#include <cstdio>
using namespace std;
const int p = 100003;
typedef long long ll;
ll pow(ll n, ll x)
{
    if (x == 0 && n != 0)
    {
        return 0;
    }
    if (x == 1)
    {
        return 1;
    }
    if (x == 0 && n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    if (n % 2 == 0)
    {
        ll tmp = pow(n / 2, x);
        return tmp * tmp % p;
    }
    else
    {
        return pow(n - 1, x) * x % p;
    }
}
int main()
{

    ll n, m;

    cin >> m >> n;
    if (n == 1)
    {
        printf("0\n");
        return 0;
    }
    // printf("%lld %lld\n", pow(n, m), pow(n - 1, m - 1));
    ll ans = pow(n, m) % p - pow(n - 1, m - 1) * m % p;
    printf("%lld", (ans + p) % p); //坑点 有减法的取模必加p
    return 0;
}

//坑点 有减法的取模必加p
//正难则反.....