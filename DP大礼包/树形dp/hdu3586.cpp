#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e3 + 5;
int n, m;
const int inf = 1000000;
vector<int> v[maxn];
vector<int> w[maxn];
int f[maxn];
void dfs(int root, int fa, int mid) {
    if (v[root].size() == 1 && v[root][0] == fa) {
        f[root] = inf;
        return;
    }
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs(to, root, mid);
        //f[root] += min(f[to], w[root][i]);
        if (w[root][i] > mid) {

            f[root] += f[to];

        }
        else f[root] += min(f[to], w[root][i]);

    }

}
bool judge(int mid) {
    memset(f, 0, sizeof f);
    dfs(1, 0, mid);
    // for (int i = 1;i <= n;i++) {
    //     cout << i << " " << f[i] << endl;
    // }
    return f[1] <= m;

}
int main() {
    freopen("data.in", "r", stdin);
    while (scanf("%d%d", &n, &m)) {
        if (!n && !m) break;
        for (int i = 0;i <= n;i++) {
            v[i].clear();
            w[i].clear();
        }
        memset(f, 0, sizeof f);
        int ub = 0;
        for (int i = 1, ai, bi, wi;i < n;i++) {
            scanf("%d%d%d", &ai, &bi, &wi);
            v[ai].push_back(bi);
            v[bi].push_back(ai);
            w[ai].push_back(wi);
            w[bi].push_back(wi);
            ub = max(ub, wi);
        }
        int l = 1, r = ub;
        while (l < r) {

            int mid = (l + r) / 2;
            if (judge(mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
            // cout << l << r << endl;
        }
        if (!judge(l)) l++;
        if (l == ub + 1) l = -1;
        printf("%d\n", l);
    }
    return 0;
}