#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 18;
int nz[maxn][maxn];
int f[1 << maxn];
double zx[maxn], zy[maxn];
int n, m, T;
void init()
{
    memset(f, 0x3f, sizeof f);

    memset(nz, 0, sizeof nz);
}

int main()

{
    freopen("data.in", "r", stdin);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        init();
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &zx[i], &zy[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                double tmp1 = zy[i] * zx[j] - zx[i] * zy[j];

                tmp1 /= (zx[i] * zx[i] * zx[j] - zx[j] * zx[j] * zx[i]);
                if (tmp1 >= 0)
                    continue;

                double tmp2 = (zy[j] - tmp1 * zx[j] * zx[j]) / zx[j];
                nz[i][j] = (1 << i) | (1 << j);
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                        continue;
                    if (fabs(tmp1 * zx[k] * zx[k] + zx[k] * tmp2 - zy[k]) < 1e-6)
                    {
                        nz[i][j] |= (1 << k);
                    }
                }
            }
        }
        f[0] = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            if (f[i] == 0x3f3f3f3f)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (!((i >> j) & 1))
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (!((i >> k) & 1))
                        {
                            if (nz[j][k])
                                f[i | nz[j][k]] = min(f[i | nz[j][k]], f[i] + 1);
                        }
                    }
                }
            }
        }
        printf("%d\n", f[(1 << n) - 1]);
    }
    return 0;
}
//85