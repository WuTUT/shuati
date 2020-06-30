#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 28;
int lc[maxn], rc[maxn];
char tr[maxn];
int n;
void dfs(int ro)
{
    printf("%c", char(ro + 'a' - 1));
    if (lc[ro])
    {
        dfs(lc[ro]);
    }
    if (rc[ro])
    {
        dfs(rc[ro]);
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    char root, l, r;
    int ro;
    for (int i = 1; i <= n; i++)
    {
        scanf(" %c%c%c", &root, &l, &r);
        if (l != '*')
        {
            lc[root - 'a' + 1] = l - 'a' + 1;
        }
        if (r != '*')
        {
            rc[root - 'a' + 1] = r - 'a' + 1;
        }
        if (i == 1)
            ro = root - 'a' + 1;
    }
    dfs(ro);
    return 0;
}