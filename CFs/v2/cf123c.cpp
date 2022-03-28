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
const int N = 5000 + 10;
// [ty a b] && [ty b c] exist then [ty a c] not exist

int f[N];

int s[N];

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &s[i]);
            s[i] += s[i - 1];
        }
        memset(f, -0x3f, sizeof f);
        for (int len = 1; len <= n; len++)
        {
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int j = i + len - 1;
                f[len] = max(f[len], s[j] - s[i - 1]);
            }
        }
        for (int i = 0; i <= n; i++)
        {
            int ans = 0;
            for (int j = 1; j <= n; j++)
            {
                ans = max(ans, f[j] + x * min(j, i));
            }
            cout << ans << ' ';
        }
        cout << endl;
    }

    return 0;
}
// https://codeforces.com/contest/1644/problem/C
// C. Increase Subarray Sums
// todo