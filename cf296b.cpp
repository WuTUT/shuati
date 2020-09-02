#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll f[maxn][4];
char a[maxn], b[maxn];
const int mod = 1e9 + 7;
int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;

    scanf("%s %s", a + 1, b + 1);
    //printf("%s\n", a + 1);
    //printf("%s\n", b + 1);
    f[0][3] = 1;
    for (int i = 1;i <= n;i++) {
        if (a[i] == '?' && b[i] == '?') {
            f[i][0] = (f[i - 1][0] + f[i - 1][3]) * 55 % mod;
            f[i][1] = (f[i - 1][1] + f[i - 1][3]) * 55 % mod;
            f[i][2] = ((f[i - 1][0] + f[i - 1][1]) * 45 + f[i - 1][2]) % mod;
            f[i][3] = f[i - 1][3] * 10 % mod;
        }
        else if (a[i] == '?') {
            f[i][0] = (f[i - 1][0] + f[i - 1][3]) * (b[i] - '0' + 1) % mod;
            f[i][1] = (f[i - 1][1] + f[i - 1][3]) * (10 - (b[i] - '0')) % mod;
            f[i][2] = (f[i - 1][2] + f[i - 1][1] * (b[i] - '0') + f[i - 1][0] * (9 - (b[i] - '0'))) % mod;
            f[i][3] = f[i - 1][3];
        }
        else if (b[i] == '?') {
            f[i][0] = 1ll * (f[i - 1][0] + f[i - 1][3]) * (10 - (a[i] - '0')) % mod;
            f[i][1] = 1ll * (f[i - 1][1] + f[i - 1][3]) * (a[i] - '0' + 1) % mod;
            f[i][2] = (f[i - 1][2] + f[i - 1][1] * (9 - (a[i] - '0')) + f[i - 1][0] * (a[i] - '0')) % mod;
            f[i][3] = f[i - 1][3];
        }
        else if (a[i] == b[i]) {
            f[i][0] = f[i - 1][0];
            f[i][1] = f[i - 1][1];
            f[i][2] = f[i - 1][2];
            f[i][3] = f[i - 1][3];
        }
        else if (a[i] < b[i]) {
            f[i][0] = (f[i - 1][0] + f[i - 1][3]) % mod;
            f[i][1] = 0;
            f[i][2] = (f[i - 1][2] + f[i - 1][1]) % mod;
            f[i][3] = 0;
        }
        else if (a[i] > b[i]) {
            f[i][0] = 0;
            f[i][1] = (f[i - 1][1] + f[i - 1][3]) % mod;
            f[i][2] = (f[i - 1][2] + f[i - 1][0]) % mod;
            f[i][3] = 0;
        }
    }
    printf("%lld\n", f[n][2]);
    return 0;
}