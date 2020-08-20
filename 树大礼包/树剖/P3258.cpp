#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 3e5 + 5;
int n;
int a[maxn];
vector<int> v[maxn];
int dfn[maxn], top[maxn], dep[maxn], fat[maxn], sz[maxn], son[maxn];
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
        addv = addv + val;
        sumv = sumv + (r - l + 1) * val;
    }
}tr[maxn << 2];
inline void push_up(int x) {
    tr[x].sumv = tr[x << 1].sumv + tr[x << 1 | 1].sumv;
}
inline void push_down(int x) {
    if (tr[x].addv) {
        tr[x << 1].update(tr[x].addv);
        tr[x << 1 | 1].update(tr[x].addv);
        tr[x].addv = 0;
    }
}
void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r, tr[x].addv = 0;
    if (l == r) {
        tr[x].sumv = 0;
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
    if (l == r) {
        qval = tr[x].sumv;
    }
    else {
        push_down(x);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            query(x << 1);
        }
        if (ql > mid) {
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
inline void mchain(int x, int y) {

    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
        ql = dfn[top[x]], qr = dfn[x];
        qval = 1;
        modify(1);
        x = fat[top[x]];
    }
    if (dep[x] > dep[y])
        std::swap(x, y);
    ql = dfn[x], qr = dfn[y];
    qval = 1;
    modify(1);
}
int main() {
    freopen("data.in", "r", stdin);
    scanf("%d", &n);
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
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 1;i < n;i++) {
        mchain(a[i], a[i + 1]);
    }
    for (int i = 2;i <= n;i++) {
        ql = qr = dfn[a[i]];
        qval = -1;
        modify(1);
    }
    for (int i = 1;i <= n;i++) {
        ql = dfn[i];
        qval = 0;
        query(1);
        printf("%d\n", qval);
    }

    return 0;
}