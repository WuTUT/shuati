#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
string s, t;
const int N = 30;
const int INF = 0x3f3f3f3f;
int n, m;
int id(int x, int y)
{
    return x * m + y;
}
int f[N * N][N * N];
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    cin >> n >> m;
    cin >> s >> t;

    memset(f, 0x3f, sizeof f);

    int sz = n * m;
    for (int i = 0; i < sz; i++)
    {
        f[i][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '<')
        {
            for (int j = 1; j < m; j++)
            {
                int fr = id(i, j), to = id(i, j - 1);
                f[fr][to] = 1;
            }
        }
        else
        {
            for (int j = 0; j < m - 1; j++)
            {
                int fr = id(i, j), to = id(i, j + 1);
                f[fr][to] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (t[i] == '^')
        {
            for (int j = 1; j < n; j++)
            {
                int fr = id(j, i), to = id(j - 1, i);
                f[fr][to] = 1;
            }
        }
        else
        {
            for (int j = 0; j < n - 1; j++)
            {
                int fr = id(j, i), to = id(j + 1, i);
                f[fr][to] = 1;
            }
        }
    }

    //  for (int i = 0; i < sz; i++)
    //  {
    //      for (int j = 0; j < sz; j++)
    //      {
    //          if (f[i][j] == INF)
    //          {
    //              printf("-1 ");
    //          }
    //          else
    //          {
    //              printf("%2d ", f[i][j]);
    //              d_cnt--;
    //          }
    //      }
    //      printf("\n");
    //  }

    for (int k = 0; k < sz; k++)
    {
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (f[i][k] != INF && f[k][j] != INF)
                {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            if (f[i][j] == INF)
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}