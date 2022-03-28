#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
ll s, x;
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    cin >> s >> x;
    ll k = (s - x);
    if (k < 0 || k % 2 == 1)
    {
        printf("0\n");
        return 0;
    }
    ll ad = k / 2; // and
    ll ans = 1;
    int cnt = 2;
    while (x != 0 || ad != 0)
    {
        int p1 = x % 2;
        int p2 = ad % 2;
        x /= 2, ad /= 2;
        if (p1 == 1 && p2 == 1)
        {
            printf("0\n");
            return 0;
        }
        else if (p1 == 1 && p2 == 0)
        {
            ans = ans * 2;
        }
        else if (p1 == 0 && p2 == 1)
        {
            cnt = 0;
        }
    }
    printf("%lld\n", ans - cnt);
    return 0;
}
// a + b = (a xor b) + 2 * (a & b)
// given sum and xor of a , b, we have a & b
// given a & b and a ^ b, counting 4 different situations
// note 'positive' integer