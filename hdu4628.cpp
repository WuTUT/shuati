#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 16;
int f[1 << maxn];
int isp[1 << maxn];
char s[maxn];
int check(int x, int len)
{
    char tmp[20];
    int tot = 0;
    for (int i = 0; i < len; i++)
    {
        if ((x >> i) & 1)
            tmp[tot++] = s[i];
    }

    for (int i = 0; i < tot / 2; i++)
    {
        if (tmp[i] != tmp[tot - i - 1])
            return 0;
    }
    return 1;
}
int main()
{
    freopen("data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%s", s);
        int n = strlen(s);
        // for (int i = 1; i < n; i <<= 1)
        // {
        //     f[i] = 1;
        // }
        memset(isp, 0, sizeof isp);
        memset(f, 0x3f, sizeof f);
        for (int i = 1; i < (1 << n); i++)
        {
            isp[i] = check(i, n);
            if (isp[i])
            {
                f[i] = 1;
            }
        }
        f[0] = 0;
        for (int i = 1; i < (1 << n); i++)
        {
            for (int j = i; j; j = (j - 1) & i)
            {
                if (isp[j])
                {
                    f[i] = min(f[i], f[i ^ j] + 1);
                }
            }
        }
        printf("%d\n", f[(1 << n) - 1]);
    }
}