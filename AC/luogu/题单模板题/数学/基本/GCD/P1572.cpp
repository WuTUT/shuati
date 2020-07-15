#include <iostream>
#include <cstdio>
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
ll x[100];
ll y[100];
ll n;
int main()
{
    freopen("data.in", "r", stdin);
    char ch, op;
    ll xi, yi;
    while (cin >> xi)
    {
        cin >> ch;
        cin >> yi;
        x[n] = xi, y[n] = yi, n++;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << x[i] << '/' << y[i] << endl;
    // };
    if (n == 1)
    {
        bool fla = false;
        if (x[0] < 0)
        {
            fla = true;
            x[0] = -x[0];
            cout << '-';
        }
        if (x[0] % y[0] == 0)
        {
            cout << x[0] << endl;
        }
        else
        {

            ll tmp = gcd(x[0], y[0]);

            cout << x[0] / tmp << '/' << y[0] / tmp << endl;
        }
        return 0;
    }
    ll pro1 = y[0];
    for (int i = 1; i < n; i++)
    {
        pro1 = gcd(pro1, y[i]);
    }

    ll pro2 = pro1;
    for (int i = 0; i < n; i++)
    {
        pro2 *= y[i] / pro1;
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += x[i] * (pro2 / y[i]);
    }

    bool fla = false;
    if (sum < 0)
    {
        fla = true;
        sum = -sum;
        cout << '-';
    }
    if (sum % pro2 == 0)
    {
        cout << sum / pro2 << endl;
    }
    else
    {

        ll tmp = gcd(sum, pro2);

        cout << sum / tmp << '/' << pro2 / tmp << endl;
    }
}