#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 105;
int n, k;
int a[maxn], b[maxn];
int f[20050];
const int bias = 1000;
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        b[i] = a[i] - k * b[i];
    }
    int N = n * 1000;
    memset(f, 0x80, sizeof f);
    f[N] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = N * 2; j >= 0; j--)
        {
            f[j] = max(f[j], f[j - b[i]] + a[i]);
        }
    }
    if (f[N] >= 0)
    {
        printf("%d\n", f[N]);
    }
    else
    {
        printf("-1\n");
    }
}