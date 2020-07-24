#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 65;
char s[maxn];
int g[maxn][maxn];
int T;

int main()
{
    freopen("data.in", "r", stdin);
    cin >> T;
    while (T--)
    {
        scanf("%s", s + 1);
        s[0] = '0';
        int n = strlen(s) - 1;
        long long ans = 0;

        memset(g, 0, sizeof g);
        for (int i = 1; i <= n; i++)
        {
            g[i][i] = 1;
            ans++;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int j = i + len - 1;
                if (s[i] != s[j])
                {
                    g[i][j] = 0;
                }
                else
                {
                    if (len == 2 || g[i + 1][j - 1] != 0)
                    {
                        g[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
        ans = (1 << n) - 1 - ans;
        cout << ans;
        if (T)
            printf("\n");
    }
}