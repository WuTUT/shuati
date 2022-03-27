#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n;
const int maxn = 1010;
int fa[maxn * 2];
int find(int x)
{
    if (x != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}
void unionSet(int x, int y)
{
    fa[find(x)] = find(y);
}
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    cin >> n;
    cin >> m;
    char op;
    for (int i = 1; i <= 2 * n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1, p, q; i <= m; i++)
    {
        cin >> op >> p >> q;
        if (op == 'E')
        {
            //fa[find(q + n)] = find(p);
            //fa[find(p + n)] = find(q);
            //反集应该写这样，挂在中继节点上
            unionSet(q + n, p);
            unionSet(p + n, q);
        }
        else if (op == 'F')
        {
            unionSet(p, q);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}