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
int a[10005];
int main()
{
    freopen("data.in", "r", stdin);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (i != 1)
                a[1] /= gcd(a[i], a[1]);
        }
        if (a[1] != 1)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
}