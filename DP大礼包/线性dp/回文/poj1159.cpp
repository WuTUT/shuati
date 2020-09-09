#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5005;
int f[2][maxn];
char s[maxn];
int n;
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    scanf("%s", s + 1);
    // for (int len = 2; len <= n; len++)
    // {
    //     for (int i = 1; i + len - 1 <= n; i++)
    //     {
    //         int j = i + len - 1;
    //         if (s[i] == s[j])
    //             f[i][j] = f[i + 1][j - 1];
    //         else
    //             f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
    //     }
    // }
    for (int i = n; i >= 1; i--)
    {
        int p = i & 1;
        memset(f[p], 0, sizeof f[p]);
        for (int j = i + 1; j <= n; j++)
        {
            if (s[i] == s[j])
                f[p][j] = f[p ^ 1][j - 1];
            else
                f[p][j] = min(f[p ^ 1][j], f[p][j - 1]) + 1;
        }
    }
    printf("%d\n", f[1][n]);
}