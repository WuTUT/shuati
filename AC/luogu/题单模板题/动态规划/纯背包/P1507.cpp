#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 52;
const int maxv = 402, maxw = 402;
int f[maxv][maxw];
int a[maxn], b[maxn], c[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    int n;
    int v, w;
    cin >> v >> w;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= a[i]; j--)
            for (int k = w; k >= b[i]; k--)
            {
                f[j][k] = max(f[j][k], f[j - a[i]][k - b[i]] + c[i]);
            }
    }
    cout << f[v][w] << endl;
    return 0;
}
//两个约束而已