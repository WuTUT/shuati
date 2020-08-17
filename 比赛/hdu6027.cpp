#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n, k;
ll f[10005][3];
void init() {
    for (int i = 1;i <= 10000;i++) {
        f[i][0] = 1ll * i * i * i % mod;
        for (int j = 1;j < 3;j++) {
            f[i][j] = f[i][j - 1] * i % mod;
        }
    }
    for (int i = 2;i <= 10000;i++) {
        for (int j = 0;j < 3;j++) {
            f[i][j] = (f[i - 1][j] + f[i][j]) % mod;
        }
    }
}
int main() {
    freopen("data.in", "r", stdin);
    int T;
    cin >> T;
    init();
    while (T--) {
        int ans = 0;
        scanf("%lld %lld", &n, &k);
        if (k == 0) {
            printf("%lld\n", n);
        }
        else if (k == 1) {
            printf("%lld\n", n * (n + 1) / 2 % mod);
        }
        else if (k == 2) {
            printf("%lld\n", n * (n + 1) * (2 * n + 1) / 6 % mod);
        }
        else {
            printf("%lld\n", f[n][k - 3]);
        }
    }
    return 0;
}