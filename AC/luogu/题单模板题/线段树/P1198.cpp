#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 5;
int p;
int ql, qr;
int len;
typedef long long ll;
const ll INF = 0x7fffffff;
int t;
int qc;
ll n;
int L;
int m;
struct SegmentTree
{
    int l, r;
    int maxv;
} tr[maxn << 2];

inline void push_up(int x)
{
    tr[x].maxv = max(tr[x << 1].maxv, tr[x << 1 | 1].maxv);
}
void build(int x, int l, int r)
{
    tr[x].l = l, tr[x].r = r;
    tr[x].maxv = -INF;
    if (l == r)
    {
    }
    else
    {
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        push_up(x);
    }
}
void change_p(int x)
{
    if (tr[x].l == tr[x].r)
    {
        tr[x].maxv = qc;
    }
    else
    {
        int mid = (tr[x].l + tr[x].r) / 2;
        if (len <= mid)
        {
            change_p(x << 1);
        }
        else
        {
            change_p(x << 1 | 1);
        }
        push_up(x);
    }
}
void query_i(int x)
{
    int l = tr[x].l, r = tr[x].r;
    if (ql <= l && qr >= r)
    {
        t = max(t, tr[x].maxv);
    }
    else
    {
        int mid = (l + r) / 2;
        if (ql <= mid)
        {
            query_i(x << 1);
        }
        if (qr > mid)
        {
            query_i(x << 1 | 1);
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> m >> p;
    char c;
    build(1, 1, m);
    for (int i = 1; i <= m; i++)
    {
        scanf(" %c", &c);

        if (c == 'Q')
        {
            scanf("%d", &L);
            ql = len - L + 1;
            qr = len;
            t = -INF;
            query_i(1);
            printf("%d\n", t);
        }
        else
        {
            scanf("%lld", &n);
            qc = (n + t) % p;

            len++;
            change_p(1);
        }
    }
}