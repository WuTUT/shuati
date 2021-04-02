#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 15;
int col[maxn];
int ans[maxn];
int ls[maxn * 5], rs[maxn * 5];
int n;
int cnt;
bool check(int row, int co)
{
    if (col[co])
    {
        return false;
    }
    int lid = co + row;
    int rid = co - row;
    if (ls[lid] || rs[rid])
    {
        return false;
    }
    return true;
}
void dfs(int x)
{
    if (x > n)
    {
        cnt++;
        if (cnt <= 3)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }

        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (check(x, i))
        {
            ans[x] = i;
            ls[x + i] = 1;
            rs[i - x] = 1;
            col[i] = 1;
            dfs(x + 1);
            ls[x + i] = 0;
            rs[i - x] = 0;
            col[i] = 0;
        }
    }
}
int main()
{
    //freopen("data.in", "r", stdin);
    cin >> n;

    dfs(1);

    printf("%d\n", cnt);
    return 0;
}