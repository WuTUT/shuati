#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll a, b, c;
ll gcd(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}
int main()
{
    cin >> a >> b >> c;
    ll tmp = a * b / gcd(a, b);
    cout << tmp * c / gcd(tmp, c);
    return 0;
}