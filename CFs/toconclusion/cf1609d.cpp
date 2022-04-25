#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
int a[N];
int fa[N], sz[N];
int t[N];

int find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int n, d;
    cin >> n >> d;

    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }

    int cnt = 0;
    for (int i = 0, x, y; i < d; i++)
    {
        scanf("%d %d", &x, &y);
        int fx = find(x), fy = find(y);
        if (fx != fy)
        {
            fa[fx] = fy;
            sz[fy] += sz[fx];
            sz[fx] = 0;
        }
        else
        {
            cnt++;
        }
        for (int i = 1; i <= n; i++)
        {
            t[i] = sz[i];
        }
        int ans = 0;
        sort(t + 1, t + n + 1, greater<int>());
        ans = t[1];
        for (int j = 1; j <= cnt; j++)
        {
            ans += t[j + 1];
        }
        printf("%d\n", ans - 1);
    }

    return 0;
}