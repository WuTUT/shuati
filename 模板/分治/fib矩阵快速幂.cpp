#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
struct mat {
    ll p[2][2];
    mat() {
        memset(p, 0, sizeof p);
    }
    void print() {
        for (int i = 0;i < 2;i++) {
            for (int j = 0;j < 2;j++) {
                printf("%lld ", p[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
};
mat operator*(mat& a, mat& b) {
    mat c;
    for (int i = 0;i < 2;i++) {
        for (int j = 0;j < 2;j++) {
            for (int k = 0;k < 2;k++) {
                c.p[i][j] = (c.p[i][j] + a.p[i][k] * b.p[k][j] % mod) % mod;
            }
        }
    }
    return c;
}
mat quickpow(mat& a, ll n) {
    mat c;
    for (int i = 0;i < 2;i++) {
        c.p[i][i] = 1;
    }

    while (n) {
        if (n & 1) {
            c = c * a;
        }
        a = a * a;
        n /= 2;

    }

    return c;
}
int main() {
    ll n;
    cin >> n;
    if (n == 1 || n == 2) { printf("1\n"); return 0; }
    mat a;
    a.p[0][1] = a.p[1][0] = a.p[1][1] = 1;

    a = quickpow(a, n - 2);

    mat a0;
    a0.p[0][0] = a0.p[1][0] = 1;
    mat c = a * a0;
    printf("%lld\n", c.p[1][0]);
    return 0;
}