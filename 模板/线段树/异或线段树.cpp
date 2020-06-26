#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
int ql, qr, q_sum;
int k;
char a[maxn];
struct SgementTree
{
    int l, r;
    int sumv;
    int addv;
    void update()
    {
        //addv++;
        addv ^= 1;
        sumv = (r - l + 1) - sumv;
    }
} tr[maxn << 2];

inline void push_up(int x)
{
    tr[x].sumv = tr[x << 1].sumv + tr[x << 1 | 1].sumv;
}
inline void push_down(int x)
{
    if (tr[x].addv)
    {
        tr[x << 1].update();
        tr[x << 1 | 1].update();
        tr[x].addv = 0;
    }
}
void query_i(int x)
{
    int l = tr[x].l, r = tr[x].r;
    if (qr >= r && ql <= l)
    {
        q_sum += tr[x].sumv;
    }
    else
    {
        push_down(x);
        int mid = (l + r) / 2;
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
void add_i(int x)
{
    int l = tr[x].l, r = tr[x].r;
    if (qr >= r && ql <= l)
    {
        tr[x].update();
    }
    else
    {
        push_down(x);
        int mid = (l + r) / 2;
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
void build(int x, int l, int r)
{
    tr[x].l = l;
    tr[x].r = r;
    tr[x].sumv = 0;
    tr[x].addv = 0;
    if (l == r)
    {
        tr[x].sumv = a[l] - '0';
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
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        scanf(" %c", &a[i]);
    }

    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &k, &ql, &qr);
        if (k == 0)
        {
            add_i(1);
        }
        else
        {
            q_sum = 0;
            query_i(1);
            printf("%d\n", q_sum);
        }
    }
    return 0;
}

//又把 query_i(1);写错了！！！！！！！！！！！！！！
//第二次了！！！！！！！！！1
//XOR异或线段树  P2574