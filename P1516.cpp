#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n, m, t, k, l, x, y;
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
ll gcd(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}
int main()
{
    cin >> x >> y >> m >> n >> l;
    ll xx, yy;
    ll a = m - n, b = l, c = y - x;
    if (a < 0)
    {
        a = -a, c = -c;
    }
    ll tmp = gcd(a, b);

    if (c % tmp != 0)
    {
        cout << "Impossible\n";
        return 0;
    }
    ll k = c / tmp;
    c /= tmp;
    exgcd(a, b, xx, yy);
    cout << (xx * k % l + l) % l << endl;
}