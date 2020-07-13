#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 44;

int n, nn;
typedef long long ll;
ll w[1 << 21], v[1 << 21];
ll cntw, cntv;
ll c[maxn];
ll ans;
ll m;
int k;
int mid;
void dfs2(int ind, ll tmp)
{
    if (ind > n)
    {
        w[cntw++] = tmp;
        return;
    }
    dfs2(ind + 1, tmp);
    if (tmp + c[ind] <= m)
    {

        dfs2(ind + 1, tmp + c[ind]);
    }
}
void dfs(int ind, ll tmp)
{
    if (ind > mid)
    {
        v[cntv++] = tmp;
        return;
    }
    dfs(ind + 1, tmp);
    if (tmp + c[ind] <= m)
    {

        dfs(ind + 1, tmp + c[ind]);
    }
}

int main()
{
    freopen("data.in", "r", stdin);
    cin >> nn;
    cin >> m;
    ll x;
    for (int i = 1; i <= nn; i++)
    {
        cin >> x;
        if (x > m)
        {
            continue;
        }
        else
        {
            c[++n] = x;
        }
    }
    mid = n / 2;
    dfs(1, 0);
    dfs2(mid + 1, 0);
    sort(w, w + cntw);

    for (ll i = 0; i < cntv; i++)
    {
        ans += upper_bound(w, w + cntw, m - v[i]) - w;
    }
    cout << ans << endl;
}