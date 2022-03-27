#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n, m;
map<int, int> ma;
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    cin >> n;
    int hmax = 0;

    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        ma[x]++;
        hmax = max(hmax, ma[x]);
    }
    printf("%d %d\n", hmax, ma.size());

    return 0;
}