#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2005;
int a[maxn];
int f[3][maxn];
int n, k;
int main()
{
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        memset(f, 0x3f, sizeof f);

        f[0][0] = f[1][0] = f[2][0] = 0;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * 2 <= i; j++)
            {
                f[i % 3][j] = min(f[(i + 1) % 3][j - 1] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]), f[(i + 2) % 3][j]);
            }
        }
        printf("%d\n", f[n % 3][k]);
    }
}