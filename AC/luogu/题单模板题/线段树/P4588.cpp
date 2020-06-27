#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
int q, op, T, opi;
int p;
int k;
inline int re()
{
    int x = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * w;
}
struct SegmentTree
{
    int l, r;
    ll v;

} tr[maxn << 2];
inline void push_up(int x)
{
    tr[x].v = tr[x << 1].v * tr[x << 1 | 1].v % p;
}

void change_p(int x)
{

    if (tr[x].l == tr[x].r)
    {
        tr[x].v = k;
    }
    else
    {
        int mid = (tr[x].l + tr[x].r) / 2;
        if (mid >= opi)
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
void reset_p(int x)
{

    if (tr[x].l == tr[x].r)
    {
        tr[x].v = 1;
    }

    else
    {
        int mid = (tr[x].l + tr[x].r) / 2;
        if (mid >= k)
        {
            reset_p(x << 1);
        }
        else
        {
            reset_p(x << 1 | 1);
        }
        push_up(x);
    }
}
void build(int x, int l, int r)
{
    tr[x].l = l, tr[x].r = r, tr[x].v = 1;
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
int main()
{
    freopen("data.in", "r", stdin);
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {

        scanf("%d%d", &q, &p);
        build(1, 1, q);
        for (int i = 1; i <= q; i++)
        {
            op = re();
            k = re();
            if (op == 1)
            {

                opi = i;
                change_p(1);
                printf("%lld\n", tr[1].v);
            }
            else
            {
                reset_p(1);
                printf("%lld\n", tr[1].v);
            }
        }
    }
    return 0;
}

//纯乘法线段树，O(nlogn)解决了O(n)会产生的溢出问题