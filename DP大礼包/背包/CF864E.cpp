#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 2005;
vector<int> v[2002];
struct obj
{
    int t, d, p, id;
    bool operator<(const obj &rhs) const
    {
        return d < rhs.d;
    }
} a[105];
int n;
int f[maxn];
int main()
{

    cin >> n;
    int V = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].p);
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i].d - 1; j >= a[i].t; j--)
        {
            if (j - a[i].t < a[i].d)
            {
                if (f[j - a[i].t] + a[i].p > f[j])
                {
                    f[j] = f[j - a[i].t] + a[i].p;
                    v[j].clear();
                    v[j] = v[j - a[i].t];
                    v[j].push_back(a[i].id);
                }
            }
        }
    }
    int ans = 0, ansi = -1;
    for (int i = 0; i <= 2002; i++)
    {
        if (f[i] > ans)
        {
            ans = f[i];
            ansi = i;
        }
    }

    cout << ans << endl
         << v[ansi].size() << endl;

    for (int i = 0; i < v[ansi].size(); i++)
    {
        printf("%d ", v[ansi][i]);
    }

    return 0;
}