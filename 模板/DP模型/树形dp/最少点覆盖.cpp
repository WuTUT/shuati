#include <bits/stdc++.h>
using namespace std;
const int maxn = 1510;
vector<int> v[maxn];

int n;
int f[maxn][2];

void dfs(int root, int fa)
{
    f[root][1] = 1;

    for (int i = 0; i < v[root].size(); i++)
    {
        int to = v[root][i];
        if (to == fa)
            continue;

        dfs(to, root);
        f[root][1] += min(f[to][0], f[to][1]);
        f[root][0] += f[to][1];
    }
}

int main()
{
#ifdef DEBUGIN
    freopen("data.in", "r", stdin);
#endif
    while (cin >> n)
    {

        for (int i = 0, ai, ni, x; i < n; i++)
        {
            scanf("%d:(%d)", &ai, &ni);

            for (int j = 0; j < ni; j++)
            {
                scanf("%d", &x);
                v[ai].push_back(x);
                v[x].push_back(ai);
            }
        }
        dfs(0, -1);
        cout << min(f[0][0], f[0][1]) << endl;
        memset(f, 0, sizeof f);
        //for_each(v, v + n, [](auto &x)
        //         { x.clear(); });
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
        }
    }

    return 0;
}
//大礼包的sp666 最少点覆盖和方案数