#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 1 << 4;

const int mod = 10007;
int T, n;
struct Matrix
{
    int g[maxn][maxn];
    Matrix()
    {
        memset(g, 0, sizeof g);
    }
    Matrix(int x)
    {
        memset(g, 0, sizeof g);
        for (int i = 0; i < maxn; i++)
        {

            g[i][i] = x;
        }
    }
    void print()
    {
        for (int i = 0; i < maxn; i++)
        {
            for (int j = 0; j < maxn; j++)
            {
                printf("%d ", g[i][j]);
            }
            printf("\n");
        }
    }
};
Matrix operator*(const Matrix &a, const Matrix &b)
{
    struct Matrix c;
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            for (int k = 0; k < maxn; k++)
            {
                c.g[i][j] = (c.g[i][j] + a.g[i][k] * b.g[k][j] % mod) % mod;
            }
        }
    }
    return c;
}
Matrix quickpow(Matrix &x, int k)
{
    struct Matrix c(1);
    while (k)
    {
        if (k & 1)
        {
            k--;
            c = c * x;
        }
        x = x * x;
        k >>= 1;
    }
    return c;
}
int main()
{
    // freopen("data.in", "r", stdin);
    cin >> T;
    while (T--)
    {
        cin >> n;
        Matrix f;
        f.g[0][0] = 1;
        Matrix x;
        for (int i = 0; i < maxn; i++)
        {
            for (int ind = 0; ind < 4; ind++)
            {
                int j = (i ^ (1 << ind));
                x.g[j][i] += 1;
            }
        }
        // for (int i = 0; i < 16; i++)
        // {
        //     printf("%x ", i);
        // }
        // printf("\n");

        f = quickpow(x, n) * f;
        //f.print();
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            ans += f.g[(i << 2)][0];
        }
        printf("%d\n", ans % mod);
    }
    return 0;
}