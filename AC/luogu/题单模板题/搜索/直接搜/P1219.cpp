#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 15;
int ans[3][maxn];
int ansn;
int anss;
int n;
int a[maxn][maxn];
bool c1[maxn];
bool cu[maxn * 6], cd[maxn * 6];
int tmp[maxn];
void dfs(int knum, int row)
{
    if (knum == n)
    {
        anss++;
        if (ansn <= 2)
        {
            for (int i = 0; i < n; i++)
            {
                ans[ansn][i] = tmp[i];
            }
            ansn++;
        }
        return;
    }
    if (row >= n)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!c1[i] && !cu[i - row + n] && !cd[i + row])
        {

            tmp[row] = i + 1;
            c1[i] = true;
            cu[i - row + n] = cd[i + row] = true;
            dfs(knum + 1, row + 1);
            c1[i] = false;
            cu[i - row + n] = cd[i + row] = false;
        }
    }
}

int main()
{
    cin >> n;

    dfs(0, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    cout << anss << endl;
}