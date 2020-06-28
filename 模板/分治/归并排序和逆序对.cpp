#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], t[maxn];
typedef long long ll;
int n;
ll cnt;
void mergesort(int l, int r)
{

    if (r - l >= 1)
    {
        int mid = l + (r - l) / 2;
        mergesort(l, mid);
        mergesort(mid + 1, r);
        int p = l, q = mid + 1;

        int i = l;
        while (p <= mid || q <= r)
        {
            // printf("%d %d %d %d\n", p, q, l, r);
            if (q > r || (p <= mid && a[p] <= a[q]))
            {
                t[i++] = a[p++];
            }
            else
            {
                t[i++] = a[q++];
                cnt += (mid - p + 1);
            }
        }

        for (int j = l; j <= r; j++)
        {
            a[j] = t[j];
        }
    }
}

int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    mergesort(1, n);
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    printf("%lld\n", cnt);
}

//P1908 可能有问题
