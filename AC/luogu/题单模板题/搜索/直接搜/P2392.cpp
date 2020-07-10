#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 22;
int s[4][maxn];
int slen[4];
int maxans;
int suml, sumr;
void dfs(int si, int ind)
{
    if (slen[si] <= ind)
    {
        maxans = min(maxans, max(suml, sumr));
        return;
    }
    suml += s[si][ind];
    dfs(si, ind + 1);
    suml -= s[si][ind];
    sumr += s[si][ind];
    dfs(si, ind + 1);
    sumr -= s[si][ind];
}
int main()
{
    freopen("data.in", "r", stdin);
    for (int i = 0; i < 4; i++)
    {
        cin >> slen[i];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < slen[i]; j++)
        {
            cin >> s[i][j];
        }
    }
    //cout << s[1][1] << endl;
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        maxans = 0x7f7f7f7f;
        sumr = suml = 0;
        dfs(i, 0);
        ans += maxans;
    }
    cout << ans << endl;
    return 0;
}
//最朴素的暴力 想着加优化反而很复杂