#include <iostream>
#include <cstdio>
using namespace std;
int f[5][7][6];
int n;
int step;
bool check(int nef[5][7])
{
    for (int i = 0; i < 5; i++)
    {
        if (nef[i][0] != 0)
        {
            return false;
        }
    }
    return true;
}
inline void copy(int nef[5][7])
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++)
            nef[i][j] = f[i][j][step];
}
inline void down(int nef[5][7], int x, int y)
{
    int yy = y - 1;
    while (yy >= 0 && nef[x][yy] == 0)
    {
        yy--;
    }
    if (yy != y - 1)
    {
        nef[x][yy + 1] = nef[x][y];
        nef[x][y] = 0;
    }
}
inline void change(int nef[5][7], int l, int x, int y)
{

    int tmp = nef[x][y];
    nef[x][y] = nef[x + l][y];
    nef[x + l][y] = tmp;
    if (nef[x][y] == 0)
    {
        for (int i = y + 1; i < 7; i++)
        {
            nef[x][i - 1] = nef[x][i];
        }
    }
    down(nef, x + l, y);
}
void dfs(int step)
{
    if (step >= n)
    {
        return;
    }
    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 7; j++)
        {
            if (f[i][j][step] == 0)
                break;
            for (int l = 1; l >= -1; l -= 2)
            {
                if (i + l >= 5 || i + l < 0)
                {
                    continue;
                }
                int nef[5][7];
                copy(nef);
                change(nef, l, i, j);
            }
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        int x, j = 0;
        while (cin >> x)
        {
            if (x == 0)
            {
                break;
            }
            f[i][j++][0] = x;
        }
    }
    dfs(step);
    return 0;
}

void printf(int step)
{
    for (int j = 6; j >= 0; j--)
    {
        for (int i = 0; i < 5; i++)
            cout << f[i][j][step];
        cout << endl;
    }
}