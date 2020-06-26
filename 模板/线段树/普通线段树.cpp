#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const ll INF = 1ll << 60;
int n, m;
int a[maxn];
int ql, qr;
int qval;
ll q_sum, q_min, q_max;
struct Tree
{
    int l, r;
    ll sumv, addv;
    ll minv, maxv;
    void update(long long val)
    {
        sumv += 1ll * (r - l + 1) * val;
        minv += val;
        maxv += val;
        addv += val;
    }
} tr[maxn << 2];

inline void push_up(int x)
{
    tr[x].sumv = tr[x << 1].sumv + tr[x << 1 | 1].sumv;
    tr[x].minv = min(tr[x << 1].minv, tr[x << 1 | 1].minv);
    tr[x].maxv = max(tr[x << 1].maxv, tr[x << 1 | 1].maxv);
}
inline void push_down(int x)
{

    if (tr[x].addv)
    {
        tr[x << 1].update(tr[x].addv);
        tr[x << 1 | 1].update(tr[x].addv);
        tr[x].addv = 0;
    }
}
void build(int x, int l, int r)
{
    tr[x].l = l;
    tr[x].r = r;
    tr[x].sumv = tr[x].addv = 0;
    if (l == r)
    {
        tr[x].sumv = a[l]; //是l不是x
        tr[x].minv = tr[x].maxv = a[l];
    }
    else
    {
        int mid = (l + r) >> 1;

        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        push_up(x);
    }
}

void add_i(int x)
{
    int l = tr[x].l;
    int r = tr[x].r;
    if (qr >= r && ql <= l)
    {
        tr[x].update(qval);
    }
    else
    {
        push_down(x);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            add_i(x << 1);
        if (qr > mid)
            add_i(x << 1 | 1);
        push_up(x);
    }
}
void query_i(int x)
{

    int l = tr[x].l;
    int r = tr[x].r;
    if (qr >= r && ql <= l)
    {
        q_sum += tr[x].sumv;
        q_min = min(q_min, tr[x].minv);
        q_max = max(q_max, tr[x].maxv);
    }
    else
    {
        push_down(x);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            query_i(x << 1);
        if (qr > mid)
            query_i(x << 1 | 1);
        push_up(x);
    }
}

int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);

    int ks;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &ks, &ql, &qr);

        if (ks == 1)
        {
            scanf("%d", &qval);
            add_i(1);
        }
        else
        {

            q_sum = 0;
            q_min = INF;
            q_max = -INF;
            query_i(1);
            printf("sum = %lld min = %lld max = %lld\n", q_sum, q_min, q_max);
        }
    }
    return 0;
}

//线段树易错点
/*
    1. add_i(1);query_i(1);永远都是1！！！！！
    2. tr[x].addv=0;lazy_tag清0 以及有set功能是二者优先顺序
    3. 开4倍！！！！！！！！！！！！算一下有没有爆内存！
    4. push_up  和down内联
    5. push_up 注意没有+=而是=
    6. q_sum q_max q_min 赋值而且不要int 成局部变量
    7. tr[x].sum=a[l] 是l不是x
*/
