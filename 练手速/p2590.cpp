#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 3e4 + 5;
vector<int> v[maxn];
int a[maxn];
int sz[maxn], dep[maxn], son[maxn], fat[maxn];
void dfs1(int root, int fa) {
    dep[root] = dep[fa] + 1;
    fat[root] = fa;
    sz[root] = 1;
    int maxsz = -1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs1(to, root);
        sz[root] += sz[to];
        if (sz[to] > maxsz) {
            son[root] = to;
            maxsz = sz[to];
        }
    }
}
int dfn[maxn], dfntot, top[maxn], va[maxn];
void dfs2(int root, int t) {
    dfn[root] = ++dfntot;
    top[root] = t;
    va[dfntot] = a[root];
    if (!son[root]) return;
    dfs2(son[root], t);
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fat[root] || to == son[root]) continue;
        dfs2(to, to);
    }
}
int ql, qr, qs, qm, qval;
struct SegmentTree {
    int l, r;
    int maxv, sumv;

}tr[maxn << 2];
inline void push_up(int x) {
    tr[x].sumv = tr[x << 1].sumv + tr[x << 1 | 1].sumv;
    tr[x].maxv = max(tr[x << 1].maxv, tr[x << 1 | 1].maxv);
}
void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r;
    if (l == r) {
        tr[x].sumv = va[l];
        tr[x].maxv = va[l];
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
    if (ql <= l && qr >= r) {
        qs += tr[x].sumv;
        qm = max(qm, tr[x].maxv);
    }
    else {
        int mid = (l + r) / 2;
        if (ql <= mid) {
            query(x << 1);
        }
        if (qr > mid) {
            query(x << 1 | 1);
        }
    }
}
void modify(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (l == r) {
        tr[x].sumv = qval;
        tr[x].maxv = qval;
    }
    else {
        int mid = (l + r) / 2;
        if (ql <= mid) {
            modify(x << 1);
        }
        if (ql > mid) {
            modify(x << 1 | 1);
        }
        push_up(x);
    }
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
    ql = dfn[x];
    modify(1);
}
int n, m;
int main() {
    freopen("data.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1, ai, bi;i < n;i++) {
        scanf("%d %d", &ai, &bi);
        v[ai].push_back(bi);
        v[bi].push_back(ai);
    }

    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    dfntot = 0;
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    scanf("%d", &m);
    char s[12];
    for (int i = 0, ai, bi;i < m;i++) {
        scanf(" %s", s);
        if (s[0] == 'C') {
            scanf("%d %d", &ai, &qval);
            mson(ai);
        }
        else if (s[1] == 'M') {
            scanf("%d %d", &ai, &bi);

            qm = -0x7f7f7f7f;
            qchain(ai, bi);
            printf("%d\n", qm);
        }
        else if (s[1] == 'S') {
            scanf("%d %d", &ai, &bi);
            qs = 0;
            qchain(ai, bi);
            printf("%d\n", qs);
        }
    }
    return 0;
}