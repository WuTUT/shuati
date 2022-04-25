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
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int a[N];
int h[N], e[N * 2], ne[N * 2], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int cnt;
int dfs(int root, int fa, int val)
{
    if (cnt == 2)
        return 0;
    int tot = a[root];
    for (int i = h[root]; ~i; i = ne[i])
    {
        int to = e[i];
        if (to == fa)
            continue;
        tot = tot ^ dfs(to, root, val);
    }

    if (val == tot)
    {
        cnt++;
        return 0;
    }
    return tot;
}
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        memset(h, -1, sizeof h);
        idx = 0;
        int n, K;
        cin >> n >> K;
        int val = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            val = val ^ a[i];
        }
        for (int i = 0, x, y; i < n - 1; i++)
        {
            scanf("%d %d", &x, &y);
            add(x, y), add(y, x);
        }
        if (val == 0)
        {
            printf("YES\n");
        }
        else
        {
            if (K < 3)
                printf("NO\n");
            else
            {

                cnt = 0;
                dfs(1, -1, val);
                if (cnt < 2)
                {
                    printf("NO\n");
                }
                else
                    printf("YES\n");
            }
        }
    }
    return 0;
}