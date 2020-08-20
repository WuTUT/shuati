#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, ro, p;
int a[maxn];
vector<int> v[maxn];
int dfn[maxn], va[maxn], top[maxn], dep[maxn], fat[maxn], sz[maxn], son[maxn];
int dfntot;
void dfs1(int root, int fa) {
    dep[root] = dep[fa] + 1;
    sz[root] = 1;
    fat[root] = fa;
    int maxsz = -1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs1(to, root);
        sz[root] += sz[to];
        if (sz[to] > maxsz) {
            maxsz = sz[to];
            son[root] = to;
        }
    }

}
void dfs2(int root, int t) {
    dfn[root] = ++dfntot;
    va[dfntot] = a[root];
    top[root] = t;
    if (!son[root])
        return;
    dfs2(son[root], t);
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fat[root] || to == son[root]) continue;
        dfs2(to, to);
    }
}

int ql, qr, qval;
struct SegmentTree {
    int l, r;
    int addv, sumv;
    void update(int val) {
        addv = (addv + val) % p;
        sumv = (sumv + (r - l + 1) * val) % p;
    }
}tr[maxn << 2];
void push_up(int x) {
    tr[x].sumv = (tr[x << 1].sumv + tr[x << 1 | 1].sumv) % p;
}
void push_down(int x) {
    if (tr[x].addv) {
        tr[x << 1].update(tr[x].addv);
        tr[x << 1 | 1].update(tr[x].addv);
        tr[x].addv = 0;
    }
}
void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r, tr[x].sumv = 0, tr[x].addv = 0;
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
void query(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (qr >= r && ql <= l) {
        qval = (qval + tr[x].sumv) % p;
    }
    else {
        push_down(x);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            query(x << 1);
        }
        if (qr > mid) {
            query(x << 1 | 1);
        }
        push_up(x);
    }
}
void modify(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (qr >= r && ql <= l) {
        tr[x].update(qval);
    }
    else {
        push_down(x);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            modify(x << 1);
        }
        if (qr > mid) {
            modify(x << 1 | 1);
        }
        push_up(x);
    }
}
void mchain(int x, int y) {

    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
        ql = dfn[top[x]], qr = dfn[x];
        modify(1);
        x = fat[top[x]];
    }
    if (dep[x] > dep[y])
        std::swap(x, y);
    ql = dfn[x], qr = dfn[y];

    modify(1);
}

void qchain(int x, int y) {

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
inline void mson(int x) {
    ql = dfn[x], qr = dfn[x] + sz[x] - 1;
    modify(1);
}
inline void qson(int x) {
    ql = dfn[x], qr = dfn[x] + sz[x] - 1;
    query(1);
}


int main() {
    freopen("data.in", "r", stdin);
    scanf("%d %d %d %d", &n, &m, &ro, &p);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1, ai, bi;i < n;i++) {
        scanf("%d %d", &ai, &bi);
        v[ai].push_back(bi);
        v[bi].push_back(ai);
    }
    dfntot = 0;
    dep[0] = 0;
    dfs1(ro, 0);
    dfs2(ro, ro);
    build(1, 1, n);
    for (int i = 1, op, xi, yi, zi;i <= m;i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %d", &xi, &yi, &zi);
            qval = zi % p;
            mchain(xi, yi);
        }
        else if (op == 2) {
            scanf("%d %d", &xi, &yi);
            qval = 0;
            qchain(xi, yi);
            printf("%d\n", qval);
        }
        else if (op == 3) {
            scanf("%d %d", &xi, &zi);
            qval = zi % p;
            mson(xi);
        }
        else if (op == 4) {
            scanf("%d", &xi);
            qval = 0;
            qson(xi);
            printf("%d\n", qval);
        }
    }
    return 0;
}