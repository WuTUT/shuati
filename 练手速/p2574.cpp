#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 2e5 + 5;
char a[maxn];
int qr, ql;
typedef long long ll;
int qsum;
struct SegmentTree {
    int sumv;
    int addv;
    int l, r;
    void update() {
        addv ^= 1;
        sumv = (r - l + 1) - sumv;
    }
}tr[maxn << 2];
inline void push_down(int x) {
    if (tr[x].addv) {
        tr[x].addv = 0;
        tr[x << 1].update();
        tr[x << 1 | 1].update();
    }

}
inline void push_up(int x) {
    tr[x].sumv = tr[x << 1].sumv + tr[x << 1 | 1].sumv;
}

void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r;
    tr[x].addv = 0;
    if (l == r) {
        tr[x].sumv = a[l] - '0';
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
    if (ql <= l && qr >= r) {
        qsum += tr[x].sumv;
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
void reverse_i(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (ql <= l && qr >= r) {
        tr[x].update();
    }
    else {
        push_down(x);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            reverse_i(x << 1);
        }
        if (qr > mid) {
            reverse_i(x << 1 | 1);
        }
        push_up(x);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    int m, n;
    cin >> n >> m;

    for (int i = 1;i <= n;i++) {
        scanf(" %c", &a[i]);
    }


    int op;
    build(1, 1, n);
    for (int i = 0;i < m;i++) {
        scanf("%d%d%d", &op, &ql, &qr);
        if (op == 1) {
            qsum = 0;
            query_i(1);
            printf("%d\n", qsum);
        }
        else {
            reverse_i(1);
        }
    }
    return 0;
}