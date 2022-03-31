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

int cnt2[N], cntn2[N], cnt0[N];
int cntn1[N];
int arr[N];
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
        for (int i = 1, a; i <= n; i++)
        {
            scanf("%d", &a);
            arr[i] = a;
            cnt2[i] = cnt2[i - 1] + (a == 2);
            cntn2[i] = cntn2[i - 1] + (a == (-2));
            cnt0[i] = cnt0[i - 1] + (a == 0);
            cntn1[i] = cntn1[i - 1] + (a == -1);
        }
        int ans = 0;
        int l = 1, r = 0;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == 0 || arr[i] == 1)
            {
                continue;
            }
            int j = upper_bound(cnt0 + i, cnt0 + n, cnt0[i]) - cnt0;
            //  cout << "j is " << j << endl;
            for (j = min(j, n); j >= i; j--)
            {
                if (cnt0[j] - cnt0[i - 1] == 0 && ((cntn2[j] - cntn2[i - 1] + cntn1[j] - cntn1[i - 1]) % 2 == 0))
                {
                    int t = cnt2[j] - cnt2[i - 1] + cntn2[j] - cntn2[i - 1];
                    if (ans < t)
                    {
                        ans = t;
                        l = i, r = j;
                    }
                    break;
                }
            }
        }
        if (ans == 0)
        {
            printf("%d %d\n", n, 0);
        }
        else
            printf("%d %d\n", l - 1, n - r);
    }

    return 0;
}