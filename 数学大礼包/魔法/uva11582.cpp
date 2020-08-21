#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef unsigned long long ll;
const int maxn = 1005;
int f[maxn * maxn];
int quickpow(ll a, ll n, int m) {
    ll x = 1;
    while (n) {
        if (n & 1) {
            x = x * a % m;
        }
        a = a * a % m;
        n /= 2;
    }
    return (int)x;
}
int main() {
    // freopen("data.in", "r", stdin);
    int T;
    cin >> T;

    while (T--) {
        ll a, b;
        int n;
        cin >> a >> b >> n;
        //无符号longlong cin 不要用scanf

        f[0] = 0;
        f[1] = 1 % n;
        int m = 1;
        for (int i = 2;1;i++) {
            f[i] = (f[i - 1] + f[i - 2]) % n;
            if (f[i] == f[1] && f[i - 1] == f[0]) {
                m = i - 1;
                break;
            }
        }

        // cout << a << endl;
        // cout << b << endl;
        // cout << m << endl;

        printf("%d\n", f[quickpow(a % m, b, m)]);
    }
    return 0;
}