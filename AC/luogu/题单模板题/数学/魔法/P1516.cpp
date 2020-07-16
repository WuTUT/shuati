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
    cout << ((xx * k) % (b / tmp) + (b / tmp)) % (b / tmp) << endl;
}

//EXGCD : 1. a,b >0
//2. if(a < 0 ) a=-a,c=-c,
//3. 最小正数解 和负数模错的修改一样  一个数轴划分为了等长段，那么x对长度取模总会在0点左右那个段，反正+个长度再取模就总是对的了
