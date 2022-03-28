#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N = 3005;
int a[N];
int n;
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        a[x] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        if (a[i] == 0)
        {
            printf("%d", i);
            break;
        }
    }

    return 0;
}