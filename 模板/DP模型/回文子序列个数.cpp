#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 65;
char s[maxn];
long long f[maxn][maxn];
int T;

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        scanf("%s", s + 1);
        s[0] = '0';
        int n = strlen(s) - 1;
        long long ans = 0;

        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++)
        {
            f[i][i] = 1;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                {
                    f[i][j] = f[i][j - 1] + f[i + 1][j] + 1;
                }
                else
                {
                    f[i][j] = f[i][j - 1] + f[i + 1][j] - f[i + 1][j - 1];
                }
            }
        }
        printf("%lld\n", f[1][n]);
    }
}
//uva10617.cpp
