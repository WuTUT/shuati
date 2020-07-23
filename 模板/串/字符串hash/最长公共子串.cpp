#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100000 + 5;
typedef unsigned long long ull;
ull has[maxn], hat[maxn];
int base = 131;
char s[maxn], t[maxn];
int slen, tlen;
ull a[maxn], top;
ull P[maxn];
ull gethash(ull *ha, int l, int r)
{
    return ha[r] - ha[l] * P[r - l];
}
bool judge(int len)
{
    top = 0;
    for (int i = 0; i + len <= slen; i++)
    {
        a[top++] = gethash(has, i, i + len);
    }
    sort(a, a + top);
    for (int i = 0; i + len <= tlen; i++)
    {
        if (binary_search(a, a + top, gethash(hat, i, i + len)))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("data.in", "r", stdin);
    scanf("%s%s", s, t);
    slen = strlen(s);
    tlen = strlen(t);
    int len = min(slen, tlen);
    P[0] = 1;
    for (int i = 1; i <= slen; i++)
    {
        has[i] = (has[i - 1] * base + s[i - 1]);
    }
    for (int i = 1; i <= tlen; i++)
    {
        hat[i] = (hat[i - 1] * base + t[i - 1]);
    }
    for (int i = 1; i <= max(slen, tlen); i++)
    {
        P[i] = P[i - 1] * base;
    }
    int l = 1, r = len;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (!judge(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (judge(l))
        printf("%d\n", l);
    else
        printf("%d\n", l - 1);
    return 0;
}