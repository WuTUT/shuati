#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N];

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            int x;
            cin >> x;
            if (x > 1)
                printf("NO\n");
            else
                printf("YES\n");
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &a[i]);
            }
            int ind = max_element(a, a + n) - a;
            int m1 = a[ind];
            a[ind] = -1;
            ind = max_element(a, a + n) - a;
            if (m1 - a[ind] >= 2)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
    }

    return 0;
}