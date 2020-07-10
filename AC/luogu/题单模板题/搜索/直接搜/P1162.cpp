#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 35;
int n;
int a[maxn][maxn], b[maxn][maxn];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int row, int col)
{
    if (row < 0 || row > n + 1 || col < 0 || col > n + 1 || b[row][col] == 1 || b[row][col] == -1)
        return;
    b[row][col] = -1;
    for (int i = 0; i <= 3; i++)
    {
        dfs(row + dx[i], col + dy[i]);
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                b[i][j] = 1;
            }
            else
                b[i][j] = 2;
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (b[i][j] == 2)
            {
                cout << 2 << " ";
            }
            else
            {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

//!!!!!!!!!!!!!!