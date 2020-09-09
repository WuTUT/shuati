#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m, p, q;
typedef long long ll;
struct mat {
    ll s[2][2];
    mat() {
        memset(s, 0, sizeof s);
    }
};
mat operator*(const mat& a, const mat& b) {
    mat c;
    for (int i = 0;i < 2;i++) {
        for (int j = 0;j < 2;j++) {
            for (int k = 0;k < 2;k++) {
                c.s[i][j] = (c.s[i][j] + a.s[i][k] * b.s[k][j] % m) % m;
            }
        }
    }
    return c;
}
mat quickpow(mat& a, ll n) {
    mat c;
    c.s[1][1] = c.s[0][0] = 1;
    while (n) {
        if (n & 1) {
            c = c * a;
        }
        a = a * a;
        n >>= 1;
    }
    return c;
}
int main() {
    freopen("data.in", "r", stdin);
    mat f0;
    cin >> p >> q >> f0.s[0][0] >> f0.s[1][0] >> n >> m;
    if (n == 1) {
        cout << f0.s[0][0];return 0;
    }
    else if (n == 2) {
        cout << f0.s[1][0];return 0;
    }
    mat f;
    f.s[0][1] = 1, f.s[1][0] = q, f.s[1][1] = p;
    f = quickpow(f, n - 2);
    f = f * f0;
    cout << f.s[1][0] << endl;return 0;
}