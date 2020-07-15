#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll gcd(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
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
int main()
{
    ll a, b, x, y;
    cin >> a >> b;
    exgcd(a, b, x, y);
    cout << (x % b + b) % b << endl;
}