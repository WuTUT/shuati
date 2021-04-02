#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 10;
int ans[maxn];
int n;
void dfs(int left, int ind)
{
    if (left == 0)
    {
        if (ind > 1)
        {
            for (int i = 0; i < ind - 1; i++)
            {
                printf("%d+", ans[i]);
            }
            printf("%d", ans[ind - 1]);
            printf("\n");
        }
        return;
    }
    if (left < 0)
    {
        return;
    }

    for (int i = 1; i <= left; i++)
    {
        if (ind > 0 && i < ans[ind - 1])
            continue;
        ans[ind] = i;
        dfs(left - i, ind + 1);
    }
}
int main()
{
    cin >> n;
    dfs(n, 0);
    return 0;
}