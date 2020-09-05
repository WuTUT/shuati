#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 52;
const int mod = 1e9 + 7;
typedef long long ll;
ll n;
int m, k;
struct Matrix {
    ll f[maxn][maxn];
    Matrix() {
        memset(f, 0, sizeof f);
    }
    void print() {
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < m;j++) {
                printf("%lld ", f[i][j]);
            }
            printf("\n");
        }
    }
};
Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix c;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < m;j++) {
            for (int k = 0;k < m;k++) {
                c.f[i][j] = (c.f[i][j] + a.f[i][k] * b.f[k][j] % mod) % mod;
            }
        }
    }
    return c;
}
Matrix quickpow(Matrix& a, ll n) {//喜欢不开ll 喜欢不开ll？？？？？？？
    Matrix c;
    for (int i = 0;i < m;i++) {
        c.f[i][i] = 1;
    }
    while (n) {
        if (n & 1)
            c = c * a;
        a = a * a;
        n /= 2;
    }
    return c;
}
inline int toi(char ch) {
    if (ch <= 'z' && ch >= 'a') {
        return ch - 'a';
    }
    else return ch - 'A' + 26;
}
int main() {
    freopen("data.in", "r", stdin);
    scanf("%lld %d %d", &n, &m, &k);
    Matrix x;
    char ch1, ch2;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < m;j++) {
            x.f[i][j] = 1;
        }
    }
    for (int i = 1;i <= k;i++) {
        scanf(" %c%c", &ch1, &ch2);
        //printf("%c %c ", ch1, ch2);
        x.f[toi(ch2)][toi(ch1)] = 0;
    }

    x = quickpow(x, n - 1);

    Matrix st;
    for (int i = 0;i < m;i++) {
        st.f[i][0] = 1;
    }
    Matrix ans = x * st;
    int tot = 0;
    for (int i = 0;i < m;i++) {
        tot = (tot + ans.f[i][0]) % mod;
    }
    printf("%d\n", tot);
    return 0;
}