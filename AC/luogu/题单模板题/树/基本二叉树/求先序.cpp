#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 10;
string pre, post;
int len;
void dfs(int l, int r, int ll, int rr)
{
    if (l > r || ll > rr)
    {
        return;
    }

    printf("%c", post[rr]);
    int i;
    for (i = l; i <= r; i++)
    {
        if (pre[i] == post[rr])
        {
            break;
        }
    }
    dfs(l, i - 1, ll, rr + i - r - 1); //细节还是很容易出错
    dfs(i + 1, r, rr + i - r, rr - 1);
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> pre;
    cin >> post;
    len = pre.length();
    dfs(0, len - 1, 0, len - 1);
    printf("\n");
    return 0;
}