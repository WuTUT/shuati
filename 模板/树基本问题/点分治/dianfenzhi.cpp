#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
const int maxn = 5e5 + 5, maxk = 1e7 + 5;
vector<int> v[maxn], w[maxn];
int n, m;
int rt;
int cnt;
int sz[maxn], dis[maxn], maxp[maxn], vis[maxn], tmp[maxn];
//tmp 算出的距离
bool judge[maxk], ans[105];
int q[105];
int sum;
void getrt(int root, int fa) {
    sz[root] = 1;
    maxp[root] = 0;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa || vis[to]) continue;
        getrt(to, root);
        sz[root] += sz[to];
        if (sz[to] > maxp[root]) {
            maxp[root] = sz[to];
        }
    }
    maxp[root] = max(maxp[root], sum - sz[root]);
    if (maxp[root] < maxp[rt]) rt = root;
}
void getdis(int root, int fa) {
    tmp[cnt++] = dis[root];
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa || vis[to]) continue;
        dis[to] = dis[root] + w[root][i];
        getdis(to, root);
    }
}
void solve(int root) {
    stack<int> stk;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (vis[to]) continue;
        cnt = 0;
        dis[to] = w[root][i];
        getdis(to, root);
        for (int j = 0;j < cnt;j++) {
            for (int k = 0;k < m;k++) {
                if (q[k] >= tmp[j])
                    ans[k] |= judge[q[k] - tmp[j]];
            }
        }
        for (int j = 0;j < cnt;j++) {
            stk.push(tmp[j]);
            judge[tmp[j]] = true;
        }
    }
    while (!stk.empty()) {
        judge[stk.top()] = false;
        stk.pop();
    }
}
void divid(int root) {
    vis[root] = judge[0] = 1;
    solve(root);
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (vis[to]) continue;
        maxp[rt = 0] = sum = sz[to];
        getrt(to, 0);
        getrt(rt, 0);
        divid(rt);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1, ai, bi, wi;i < n;i++) {
        scanf("%d %d %d", &ai, &bi, &wi);
        v[ai].push_back(bi);
        w[ai].push_back(wi);
        v[bi].push_back(ai);
        w[bi].push_back(wi);
    }
    for (int i = 0;i < m;i++) {
        scanf("%d", &q[i]);
    }
    maxp[0] = sum = n;
    getrt(1, 0);
    getrt(rt, 0);
    divid(rt);
    for (int i = 0;i < m;i++) {
        if (ans[i]) printf("AYE\n");
        else printf("NAY\n");
    }

    return 0;
}