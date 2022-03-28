#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
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
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                ans++;
                if (i + 2 < n)
                    a[i + 1] = max(a[i], a[i + 2]);
                else
                    a[i + 1] = a[i];
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}