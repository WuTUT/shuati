#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 105;
const ll mod = 1e9 + 7;
int n;
struct mat
{
    ll g[maxn][maxn];
    mat()
    {
        memset(g, 0, sizeof g);
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%lld ", g[i][j]);
            }
            printf("\n");
        }
    }
} x;

mat operator*(const mat &a, const mat &b)
{
    mat c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c.g[i][j] = (c.g[i][j] + a.g[i][k] * b.g[k][j] % mod) % mod;
            }
        }
    }
    return c;
}
mat quickPower(mat &x, ll k) //喜欢不开ll？？？？
{
    mat c;
    for (int i = 0; i < n; i++)
    {
        c.g[i][i] = 1;
    }
    while (k)
    {
        if (k & 1)
        {
            c = c * x;
        }
        x = x * x;
        k >>= 1;
    }
    return c;
}
int main()
{
    freopen("data.in", "r", stdin);
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &(x.g[i][j]));
        }
    }
    x = quickPower(x, k);
    x.print();
    return 0;
}