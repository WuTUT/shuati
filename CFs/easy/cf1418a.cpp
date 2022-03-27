#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll x, y, k;

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        cin >> x >> y >> k;

        ll ans = (k * y + k - 1) / (x - 1) + k;
        if ((k * y + k - 1) % (x - 1) != 0)
            ans++;
        cout << ans << endl;
    }

    return 0;
}