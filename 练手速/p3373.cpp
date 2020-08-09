#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
int ql, qr;
int qsum;
int qval;
int p;
struct SegmentTree {
    int l, r;
    ll sumv, addv, mulv;
    void update_a(int val) {
        addv += val;
        sumv += 1ll * (r - l + 1) * val;
        sumv %= p;
    }
    void update_m(int val) {
        mulv *= val;
        sumv *= val;
        addv *= val;
        sumv %= p;
        mulv %= p;
        addv %= p;
    }
}tr[maxn << 2];
int a[maxn];
void push_down(int x) {
    if (tr[x].mulv != 1) {
        tr[x << 1].update_m(tr[x].mulv);
        tr[x << 1 | 1].update_m(tr[x].mulv);
        tr[x].mulv = 1;
    }
    if (tr[x].addv != 0) {
        tr[x << 1].update_a(tr[x].addv);
        tr[x << 1 | 1].update_a(tr[x].addv);
        tr[x].addv = 0;
    }

}
void push_up(int x) {
    tr[x].sumv = (tr[x << 1].sumv + tr[x << 1 | 1].sumv) % p;
}
void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r;
    tr[x].mulv = 1, tr[x].sumv = 0, tr[x].addv = 0;
    if (l == r) {
        tr[x].sumv = a[l];
    }
    else {
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        push_up(x);
    }
}
void query_i(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (qr >= r && ql <= l) {
        qsum += tr[x].sumv;
        qsum %= p;
    }
    else {
        push_down(x);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            query_i(x << 1);
        }
        if (qr > mid) {
            query_i(x << 1 | 1);
        }
        push_up(x);
    }
}
void add_i(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (qr >= r && ql <= l) {
        tr[x].update_a(qval);
    }
    else {
        push_down(x);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            add_i(x << 1);
        }
        if (qr > mid) {
            add_i(x << 1 | 1);
        }
        push_up(x);
    }
}
void mul_i(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (qr >= r && ql <= l) {
        tr[x].update_m(qval);
    }
    else {
        push_down(x);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            mul_i(x << 1);
        }
        if (qr > mid) {
            mul_i(x << 1 | 1);
        }
        push_up(x);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    int  n, m;
    cin >> n >> m >> p;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);

    }
    build(1, 1, n);
    int op;
    for (int i = 0;i < m;i++) {
        scanf("%d%d%d", &op, &ql, &qr);
        if (op == 1) {
            scanf("%d", &qval);
            mul_i(1);

        }
        else if (op == 2) {
            scanf("%d", &qval);
            add_i(1);

        }
        else {
            qsum = 0;
            query_i(1);
            printf("%d\n", qsum);
        }
        // for (int s = 1;s < 10;s++) {
        //     printf("%lld ", tr[s].sumv);
        // }
        printf("\n");
        printf("%lld %lld ", tr[8].sumv, tr[9].sumv);
        for (int s = 5;s < 8;s++) {
            printf("%lld ", tr[s].sumv);
        }
        printf("\n");
    }
    return 0;
}