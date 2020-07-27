#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;
const int maxn = 15;
int n, m, k;
int hi[maxn];
int v[maxn][maxn];
int ishi[35];
int lo[35];
int f[35][1 << maxn];

void makes(int j, int node)
{
    vector<int> tmp;
    int ti = 0;
    while (j)
    {
        if (j & 1)
            tmp.push_back(ti);
        ti++;
        j >>= 1;
    }
}
vector<pair<int, int>> trans[35];
void init()
{
    memset(f, 0, sizeof f);
    memset(ishi, 0, sizeof ishi);
    memset(lo, 0, sizeof lo);
    memset(v, 0, sizeof v);
}
int main()
{
    freopen("data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        init();
        int top = 0;
        for (int i = 1, xi, yi; i <= m; i++)
        {
            scanf("%d%d", &xi, &yi);
            v[xi][yi] = v[yi][xi] = 1;
        }
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &hi[i]);
            ishi[hi[i]] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!ishi[i])
            {
                lo[++top] = i;
            }
        }

        for (int i = 1; i <= top; i++)
        {
            trans[i].clear();
            for (int j = 0; j < k; j++)
            {
                if (!v[lo[i]][hi[j]])
                    continue;
                for (int p = j + 1; p < k; p++)
                {
                    if (v[lo[i]][hi[p]])
                    {
                        trans[i].push_back(make_pair(j, p));
                    }
                }
            }
        }
        // for (int i = 1; i <= top; i++)
        // {
        //     for (int j = 0; j < (1 << k); j++)
        //     {
        //         f[i][j] = f[i - 1][j];
        //         for (int t = 0; t < trans[i].size(); t++)
        //         {
        //             int p = trans[i][t].first, q = trans[i][t].second;
        //             if (((1 << p) & j) && ((1 << q) & j))
        //             {
        //                 f[i][j] = max(f[i][j], f[i - 1][j & (~(1 << p)) & (~(1 << q))] + 1);
        //             }
        //         }
        //     }
        // }
        for (int i = 0; i < top; i++)
        {
            for (int j = 0; j < (1 << k); j++)
            {
                f[i + 1][j] = max(f[i + 1][j], f[i][j]);
                for (int t = 0; t < trans[i].size(); t++)
                {
                    int p = trans[i][t].first, q = trans[i][t].second;
                    if (j >> (p)&1)
                        continue;
                    if (j >> (q)&1)
                        continue;
                    f[i + 1][j | (1 << (p)) | (1 << (q))] = max(f[i + 1][j | (1 << (p)) | (1 << (q))], f[i][j] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << k); i++)
        {
            ans = max(ans, f[top][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}