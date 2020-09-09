#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5e4 + 5;
const int maxm = 103;
const int mod = 1e9 + 7;
int a[maxn];
typedef long long ll;
int n, B, K, x;
struct mat {
    ll p[maxm][maxm];

    mat() {

        memset(p, 0, sizeof p);
    }

};
mat operator*(const mat& a, const mat& b) {
    mat c;
    for (int i = 0;i < x;i++) {
        for (int j = 0;j < x;j++) {
            for (int k = 0;k < x;k++) {
                c.p[i][j] = (c.p[i][j] + a.p[i][k] * b.p[k][j] % mod) % mod;
            }
        }
    }
    return c;
}
mat quickpow(mat& a, ll n) {
    mat c;
    for (int i = 0;i < x;i++) {
        c.p[i][i] = 1;
    }
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
    cin >> n >> B >> K >> x;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    mat f0;
    for (int i = 1;i <= n;i++) {
        (f0.p[a[i] % x][0])++;
    }
    mat f;
    for (int i = 0;i < x;i++) {
        for (int j = 1;j <= n;j++) {
            f.p[(i * 10 + a[j]) % x][i]++;
        }
    }
    f = quickpow(f, B - 1);
    f = f * f0;
    printf("%lld\n", f.p[K][0]);
    return 0;
}