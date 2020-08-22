#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {

    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        std::swap(a, b);
    ll t;
    if (b - a <= c) {
        c = c - (b - a);
        t = b + c / 2;
    }
    else {
        a += c;
        t = a;
    }



    t *= 2;
    ll r = (ll)sqrt(t) + 1;
    ll l = 0;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (mid * mid + mid > t) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (l * l + l > t) l--;
    printf("%lld\n", l);
    return 0;
}