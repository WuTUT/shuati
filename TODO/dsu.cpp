#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int fa[N], a[N], b[N], sz[N];
int find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        a[i] = b[i] = i;
        sz[i] = 1;
    }
    string s;
    for (int i = 1, x, y; i <= m; i++)
    {
        cin >> s;
        if (s[0] == 'u')
        {
            cin >> x >> y;
            int fax = find(x), fay = find(y);
            if (fax == fay)
                continue;
            sz[fax] += sz[fay];
            a[fax] = min(a[fax], a[fay]);
            b[fax] = max(b[fax], b[fay]);
            fa[fay] = fa[fax];
        }
        else
        {
            cin >> x;
            int fax = find(x);
            printf("%d %d %d\n", a[fax], b[fax], sz[fax]);
        }
    }
    return 0;
}