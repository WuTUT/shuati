#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int p, cnt;
struct SegmentTree {
    int l, r;
    ll v;
}tr[maxn << 2];
inline void push_up(int x) {
    tr[x].v = tr[x << 1].v * tr[x << 1 | 1].v % p;
}
inline void push_down(int x) {

}
void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r;
    tr[x].v = 1;
    if (l == r) {

    }
    else {
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);

    }
}
int qv;
void set_p(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (l == r) {
        tr[x].v = 1;
    }
    else {

        int mid = (l + r) / 2;
        if (qv <= mid) {
            set_p(x << 1);
        }
        if (qv > mid) {
            set_p(x << 1 | 1);
        }
        push_up(x);
    }
}
void add_p(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (l == r) {
        tr[x].v = qv;
    }
    else {

        int mid = (l + r) / 2;
        if (cnt <= mid) {
            add_p(x << 1);
        }
        if (cnt > mid) {
            add_p(x << 1 | 1);
        }
        push_up(x);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q >> p;
        build(1, 1, q);
        int op;
        cnt = 0;
        for (int i = 1;i <= q;i++) {
            scanf("%d %d", &op, &qv);
            cnt++;
            if (op == 1) {

                add_p(1);
                printf("%lld\n", tr[1].v);
            }
            else {
                set_p(1);
                printf("%lld\n", tr[1].v);
            }
        }
    }
    return 0;
}