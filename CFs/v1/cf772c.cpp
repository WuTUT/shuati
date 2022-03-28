#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
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
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] <= a[i + 1])
                continue;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            printf("0\n");
            continue;
        }
        if (a[n] < 0 || a[n - 1] > a[n]) // I make mistake on a[n] <= 0, i considered this corner case but coding wrongly.
        {
            printf("-1\n");
            continue;
        }

        cout << n - 2 << endl;
        for (int i = n - 2; i >= 1; i--)
        {
            printf("%d %d %d\n", i, i + 1, n);
        }
    }
    return 0;
}