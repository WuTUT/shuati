#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
int n, m;

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i];
    }
    int ind = 0;
    long long x;
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &x);

        while (x > a[ind])
        {
            ind++;
        }
        printf("%d %lld\n", ind, x - a[ind - 1]);
    }
    return 0;
}