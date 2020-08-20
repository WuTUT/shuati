#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> v[maxn];
int n, m;
int dep[maxn], fat[maxn], son[maxn], sz[maxn];
void dfs1(int root, int fa) {

    sz[root] = 1;
    fat[root] = fa;
    int maxz = -1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        dep[to] = dep[root] + 1;
        dfs1(to, root);
        sz[root] += sz[to];
        if (sz[to] > maxz) {
            maxz = sz[to];
            son[root] = to;
        }
    }
}
int dfntot, dfn[maxn], top[maxn];
void dfs2(int root, int t) {
    dfn[root] = ++dfntot;
    top[root] = t;
    if (!son[root]) return;
    dfs2(son[root], t);
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == son[root]) continue;
        dfs2(to, to);
    }
}
int ql, qr, qval;
struct SegmentTree {
    int l, r;
    int sumv, addv;
    void update(int val) {
        addv = val;
        sumv = (r - l + 1) * val;
    }
}tr[maxn << 2];
void push_up(int x) {
    tr[x].sumv = tr[x << 1].sumv + tr[x << 1 | 1].sumv;
}
void push_down(int x) {
    if (tr[x].addv != -1) {
        tr[x << 1].update(tr[x].addv);
        tr[x << 1 | 1].update(tr[x].addv);
        tr[x].addv = -1;
    }
}
void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r;
    tr[x].addv = -1;
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
    if (ql <= l && qr >= r) {
        qval += tr[x].sumv;
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
    if (ql <= l && qr >= r) {
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
inline void qson(int x) {
    ql = dfn[x], qr = dfn[x] + sz[x] - 1;
    query(1);
}
inline void mson(int x) {
    ql = dfn[x], qr = dfn[x] + sz[x] - 1;
    qval = 0;
    modify(1);
}
inline void mchain(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            std::swap(x, y);
        }
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
inline void qchain(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            std::swap(x, y);
        }
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
    scanf("%d", &n);
    for (int i = 1, ai;i < n;i++) {
        scanf("%d", &ai);
        v[ai].push_back(i);
    }
    dep[0] = 1;
    dfs1(0, -1);
    dfs2(0, 0);
    build(1, 1, n);
    scanf("%d", &m);

    char qs[10];
    for (int i = 1, qi;i <= m;i++) {
        scanf(" %s %d", qs, &qi);
        //cout << qs << endl;
        if (qs[0] == 'i') {
            qval = 0;
            qchain(0, qi);
            printf("%d\n", dep[qi] - qval);
            mchain(0, qi);
        }
        else if (qs[0] == 'u') {
            qval = 0;
            qson(qi);
            printf("%d\n", qval);
            mson(qi);
        }
    }
    return 0;
}