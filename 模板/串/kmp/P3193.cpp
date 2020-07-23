#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, k;
char s[40];
int match[40];
struct mat
{
    int g[40][40];

    mat()
    {
        memset(g, 0, sizeof g);
    }
    void print()
    {
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                printf("%d ", g[i][j]);
            }
            printf("\n");
        }
    }
} G, F;
mat operator*(const mat &a, const mat &b)
{
    mat c;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {

            for (int t = 0; t < m; t++)
            {
                c.g[i][j] = (c.g[i][j] + a.g[i][t] * b.g[t][j]) % k;
            }
        }
    }
    return c;
}
mat quickPower(mat x, int ind)
{
    mat ans;
    for (int i = 0; i < m; i++)
    {
        ans.g[i][i] = 1;
    }

    while (ind)
    {
        if (ind & 1)
        {
            ans = ans * x;
        }
        x = x * x;
        ind >>= 1;
    }

    return ans;
}
void getMatch(char *s, int slen)
{
    match[0] = 0, match[1] = 0;
    int j;
    for (int i = 2; i <= slen; i++)
    {
        j = match[i - 1];
        while (j && s[j] != s[i - 1])
            j = match[j];
        if (s[j] == s[i - 1])
            match[i] = j + 1;
        else
            match[i] = 0;
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    cin >> k;
    scanf("%s", s);

    getMatch(s, m);

    for (int i = 0; i < m; i++)
    {
        for (char ch = '0'; ch <= '9'; ch++)
        {
            if (s[i] == ch)
            {
                G.g[i][i + 1]++;
            }
            else
            {
                int j = match[i];
                while (j && s[j] != ch)
                    j = match[j];
                if (s[j] == ch)
                    j++;
                G.g[i][j]++;
            }
            // int j = i;
            // while (j && s[j] != ch)
            //     j = match[j];
            // if (s[j] == ch)
            // {
            //     j++;
            // }
            // G.g[i][j]++;
        }
    }

    //G.print();
    G = quickPower(G, n);
    //G.print();
    F.g[0][0] = 1;
    F = F * G;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans = (ans + F.g[0][i]) % k;
    }
    printf("%d", ans);
    return 0;
}