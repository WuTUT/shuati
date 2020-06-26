#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;

typedef long long ll;
int a[maxn];
int p;
int n, m;
int qr, ql, qval;
ll q_sum;
struct SegmentTree
{
    int l, r;
    ll add_v, mul_v;
    ll sumv;
    void update(ll val) //必须是ll
    {
        sumv += val * (r - l + 1);
        sumv %= p;
        add_v += val;
        add_v %= p;
    }
    void update_mul(ll val) //必须是ll
    {
        sumv *= val;
        sumv %= p;
        mul_v *= val;
        add_v *= val;
        add_v %= p; //必须mod
        mul_v %= p; //必须mod
    }

} tr[maxn << 2];
inline void push_down(int x)
{
    if (tr[x].mul_v != 1)
    {
        tr[x << 1].update_mul(tr[x].mul_v);
        tr[x << 1 | 1].update_mul(tr[x].mul_v);
        tr[x].mul_v = 1;
    }
    if (tr[x].add_v)
    {
        tr[x << 1].update(tr[x].add_v);
        tr[x << 1 | 1].update(tr[x].add_v);
        tr[x].add_v = 0;
    }
}

inline void push_up(int x)
{
    tr[x].sumv = tr[x << 1].sumv + tr[x << 1 | 1].sumv;
    tr[x].sumv %= p;
}
void build(int x, int l, int r)
{
    tr[x].l = l, tr[x].r = r;
    tr[x].sumv = 0;
    tr[x].add_v = 0;
    tr[x].mul_v = 1;
    if (l == r)
    {
        tr[x].sumv = a[l];
    }
    else
    {
        int mid = l + (r - l) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        push_up(x);
    }
}
void add_i(int x)
{
    int l = tr[x].l, r = tr[x].r;
    if (ql <= l && qr >= r)
    {
        tr[x].update(qval);
    }
    else
    {
        push_down(x);
        int mid = l + (r - l) / 2;
        if (ql <= mid)
        {
            add_i(x << 1);
        }
        if (qr > mid)
        {
            add_i(x << 1 | 1);
        }
        push_up(x);
    }
}
void multiply_i(int x)
{
    int l = tr[x].l, r = tr[x].r;
    if (ql <= l && qr >= r)
    {
        tr[x].update_mul(qval);
    }
    else
    {
        push_down(x);
        int mid = l + (r - l) / 2;
        if (ql <= mid)
        {
            multiply_i(x << 1);
        }
        if (qr > mid)
        {
            multiply_i(x << 1 | 1);
        }
        push_up(x);
    }
}
void query_i(int x)
{
    int l = tr[x].l, r = tr[x].r;
    if (ql <= l && qr >= r)
    {
        q_sum += tr[x].sumv;
        q_sum %= p;
    }
    else //必须mod
    {
        push_down(x);
        int mid = l + (r - l) / 2;
        if (ql <= mid)
        {
            query_i(x << 1);
        }
        if (qr > mid)
        {
            query_i(x << 1 | 1);
        }
        push_up(x);
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    int k;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &k, &ql, &qr);
        if (k == 1)
        {
            scanf("%d", &qval);
            multiply_i(1);
        }
        else if (k == 2)
        {
            scanf("%d", &qval);
            add_i(1);
        }
        else
        {
            q_sum = 0;
            query_i(1);
            printf("%lld\n", q_sum);
        }
    }
    return 0;
}
//取mod要取全
//ll要ll全
//乘法线段树