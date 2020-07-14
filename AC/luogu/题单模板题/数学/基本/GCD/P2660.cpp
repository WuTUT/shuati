#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll a, b, ans;
void gt(ll x, ll y)
{
    while (x >= 1 && y >= 1)
    {
        if (x < y)
            std::swap(x, y);
        if (y == 1)
        {
            ans += x * 4;
            break;
        }
        ll num = (x / y);
        ans += y * 4 * num;
        x -= num * y;
    }
}
int main()
{
    cin >> a >> b;
    gt(a, b);
    cout << ans << endl;
    return 0;
}