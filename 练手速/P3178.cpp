#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100005;
typedef long long ll;
vector<int> v[maxn];
int fat[maxn], dep[maxn], son[maxn], sz[maxn];ll a[maxn];
void dfs1(int root, int fa) {
    fat[root] = fa;
    dep[root] = dep[fa] + 1;
    sz[root] = 1;
    int maxz = -1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs1(to, root);
        sz[root] += sz[to];
        if (maxz < sz[to]) {
            maxz = sz[to];
            son[root] = to;
        }
    }
}

ll va[maxn];int dfn[maxn], dfntot, top[maxn];
void dfs2(int root, int t) {
    dfn[root] = ++dfntot;
    va[dfntot] = a[root];
    top[root] = t;
    if (!son[root]) return;
    dfs2(son[root], t);
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fat[root] || to == son[root]) continue;
        dfs2(to, to);
    }
}


struct SegmentTree {
    int l, r;
    ll sumv, addv;
    void update(ll val) {
        addv += val;
        sumv += 1ll * (r - l + 1) * val;
    }
}tr[maxn << 2];
void push_down(int x) {
    if (tr[x].addv) {
        tr[x << 1].update(tr[x].addv);
        tr[x << 1 | 1].update(tr[x].addv);
        tr[x].addv = 0;
    }
}
void push_up(int x) {
    tr[x].sumv = tr[x << 1].sumv + tr[x << 1 | 1].sumv;
}
void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r;
    tr[x].addv = tr[x].sumv = 0;
    if (l == r) {
        tr[x].sumv = va[l];
    }
    else {
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        push_up(x);
    }
}
int ql, qr;ll qval;
ll qsum;
void modify(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (ql <= l && qr >= r) {
        tr[x].update(qval);
    }
    else {
        push_down(x);
        int mid = (l + r) / 2;
        if (ql <= mid)
            modify(x << 1);
        if (qr > mid)
            modify(x << 1 | 1);
        push_up(x);
    }
}
void modify_p(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (l == r) {
        tr[x].update(qval);
    }
    else {
        push_down(x);
        int mid = (l + r) / 2;
        if (ql <= mid)
            modify_p(x << 1);
        if (ql > mid)
            modify_p(x << 1 | 1);
        push_up(x);
    }
}
void query(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (ql <= l && qr >= r) {
        qsum += tr[x].sumv;
    }
    else {
        push_down(x);
        int mid = (l + r) / 2;
        if (ql <= mid)
            query(x << 1);
        if (qr > mid)
            query(x << 1 | 1);
        push_up(x);
    }
}
inline void mson(int x) {
    ql = dfn[x], qr = dfn[x] + sz[x] - 1;
    modify(1);
}
inline void mp(int x) {
    ql = dfn[x];
    modify_p(1);
}
inline void qchain(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
        ql = dfn[top[x]], qr = dfn[x];
        query(1);
        x = fat[top[x]];
    }
    if (dep[x] > dep[y])
        std::swap(x, y);
    ql = dfn[x], qr = dfn[y];
    query(1);
}
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= n;i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1, ai, bi;i < n;i++) {
        scanf("%d %d", &ai, &bi);
        v[ai].push_back(bi);
        v[bi].push_back(ai);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    int op;
    for (int i = 1, xi;i <= m;i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %lld", &xi, &qval);
            mp(xi);
        }
        else if (op == 2) {
            scanf("%d %lld", &xi, &qval);
            mson(xi);
        }
        else if (op == 3) {
            qsum = 0;
            scanf("%d", &xi);
            qchain(xi, 1);
            printf("%lld\n", qsum);
        }
    }
    return 0;
}