#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll p = 1e8;
struct mat {
    ll a[2][2];
    mat() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }

};
mat operator* (mat& a, mat& b) {
    mat c;
    for (int i = 0;i < 2;i++) {
        for (int j = 0;j < 2;j++) {
            for (int k = 0;k < 2;k++) {
                c.a[i][j] += a.a[i][k] * b.a[k][j] % p;
                c.a[i][j] %= p;
            }
        }
    }
}
mat quickpow(int n) {
    mat c; mat a;
    a.a[0][0] = a.a[0][1] = a.a[1][0] = 1;
    c.a[1][1] = c.a[0][0] = 1;
    while (n) {
        if (n & 1) {
            c = c * a;
        }
        a = a * a;
        n /= 2;
    }
}
ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int main() {
    mat a;
    a.a[0][0] = 0, a.a[1][0] = 1;
    int n, m;
    scanf("%d %d", &n, &m);
    mat x = quickpow(n);
    ll m1 = (x * a).a[0][0];
    x = quickpow(m);
    ll m2 = (x * a).a[0][0];
    cout << gcd(m1, m2);
    return 0;
}