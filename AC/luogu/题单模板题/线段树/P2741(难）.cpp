#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n, m;
int yi, ri;
int ql, qr, q_max;
const int maxn = 50000 + 5;
unordered_map<int, int> ma;
int ha[maxn];
int a[maxn];
struct SegmentTree
{
    int l, r;
    int maxv;

} tr[maxn << 2];
void push_up(int x)
{
    tr[x].maxv = max(tr[x << 1].maxv, tr[x << 1 | 1].maxv);
}
void build(int x, int l, int r)
{
    tr[x].l = l, tr[x].r = r;
    tr[x].maxv = 0;
    if (l == r)
    {
        scanf("%d%d", &yi, &ri);
        ma[yi] = l;
        ha[l] = yi;
        a[l] = ri;
        tr[x].maxv = ri;
        //printf("%d %d %d\n", l, yi, ri);
    }
    else
    {
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        push_up(x);
    }
}
void query_i(int x)
{
    int l = tr[x].l, r = tr[x].r;
    if (ql <= l && qr >= r)
    {
        q_max = max(q_max, tr[x].maxv);
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
        push_up(x);
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    cin >> n;
    build(1, 1, n);

    cin >> m;
    int y1, y2;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &y1, &y2);

        if (y1 >= y2)
        {
            printf("false\n");
        }
        else
        {
            int st = lower_bound(ha + 1, ha + n + 1, y1) - ha;
            int ed = lower_bound(ha + 1, ha + n + 1, y2) - ha;
            int in_y1 = ma.count(y1);
            int in_y2 = ma.count(y2);
            if (in_y1 == 0 && in_y2 == 0)
            {
                printf("maybe\n");
                continue;
            }
            if (in_y1 != 0 && in_y2 == 0)
            {
                if (st == n)
                {
                    printf("maybe\n");
                    continue;
                }
                if (ed - st == 1)
                {
                    printf("maybe\n");
                    continue;
                }
                ql = st + 1;
                qr = ed - 1;
                q_max = 0;
                query_i(1);
                if (q_max >= a[st])
                {
                    printf("false\n");
                }
                else
                {
                    printf("maybe\n");
                }
                continue;
            }
            if (in_y1 == 0 && in_y2 != 0)
            {
                if (ed == 1)
                {
                    printf("maybe\n");
                    continue;
                }
                ql = st;
                qr = ed - 1;
                q_max = 0;
                query_i(1);
                if (q_max >= a[ed])
                {
                    printf("false\n");
                }
                else
                {
                    printf("maybe\n");
                }
                continue;
            }
            if (in_y1 != 0 && in_y2 != 0)
            {

                if (a[st] < a[ed])
                {
                    printf("false\n");
                    continue;
                }
                if (ed - st != 1)
                {

                    ql = st + 1;
                    qr = ed - 1;
                    q_max = 0;
                    query_i(1);
                    if (q_max >= a[ed])
                    {
                        printf("false\n");
                    }
                    else
                    {
                        // printf("%d %d %d %d\n", y1, y2, ha[qr], ha[ql]);
                        if (y2 - y1 - 1 == qr - ql + 1)
                        {
                            printf("true\n");
                        }
                        else
                        {
                            printf("maybe\n");
                        }
                    }
                    continue;
                }
                else
                {
                    if (y2 - y1 > 1)
                    {
                        printf("maybe\n");
                    }
                    else
                    {
                        printf("true\n");
                    }
                }
            }
        }
    }
    return 0;
}