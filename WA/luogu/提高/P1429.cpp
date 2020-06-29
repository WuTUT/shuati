#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 200000 + 5;
const double INF = 0x7fffffffffffffff;
int n;
struct Point
{
    int x, y;
    bool operator<(const Point &rhs) const
    {
        return x < rhs.x;
    }
} po[maxn];
int t[maxn];
inline double getdis(Point &p1, Point &p2)
{
    return 1.0 * (p1.x - p2.x) * (p1.x - p2.x) + 1.0 * (p1.y - p2.y) * (p1.y - p2.y);
}
bool cmp2(const int p1, const int p2)
{
    return po[p1].y < po[p2].y;
}
double merge(int l, int r)
{
    //printf("%d %d \n", l, r);
    double dis = INF;
    if (r == l)
        return dis;
    if (r - l > 1)
    {
        int mid = (r - l) / 2 + l;
        double d1 = merge(l, mid);
        double d2 = merge(mid + 1, r);

        dis = min(d1, d2);
        // int p = l, q = mid + 1, i = l;

        // while (p <= mid || q <= r)
        // {
        //     if (q > r || (p <= mid && (po[p].y <= po[q].y)))
        //     {
        //         t[i++] = po[p++];
        //     }
        //     else
        //     {
        //         t[i++] = po[q++];
        //     }
        // }
        // for (int j = l; j <= r; j++)
        // {
        //     po[j] = t[j];
        // }
        // for (int j = 0; j < i; j++)
        // {
        //     for (int k = j + 1; k < i; k++)
        //     {
        //         if (po[j].y - po[k].y >= dis)
        //         {
        //             break;
        //         }
        //         dis = min(dis, getdis(po[j], po[k]));
        //     }
        // }

        int p = l;
        int i = 0;
        while (p <= r)
        {
            if (fabs(po[mid].x - po[p].x) < dis)
                t[i++] = p;
            p++;
        }
        sort(t, t + i, cmp2);
        for (int j = 0; j < i; j++)
        {
            for (int k = j + 1; k < i; k++)
            {
                if (po[t[k]].y - po[t[j]].y >= dis)
                {
                    break;
                }
                dis = min(dis, getdis(po[t[j]], po[t[k]]));
            }
        }
    }
    else
    {
        dis = getdis(po[l], po[r]);
    }

    return dis;
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &po[i].x, &po[i].y);
    }

    //sort(t + 1, t + 1 + n, cmp2);
    sort(po + 1, po + 1 + n);
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%lf %lf\n", po[i].x, po[i].y);
    // }
    double dis = merge(1, n);
    dis = sqrt(dis);
    printf("%.4lf\n", dis);
    return 0;
}