#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <algorithm>
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = n; i < 2 * n; i++)
        {
            a[i] = a[i - n];
        }

        int ind = find_if(a, a + n, [](int x)
                          { return x == 1; }) -
                  a;
        // cout << ind << endl;
        if (ind == n)
        {
            printf("NO\n");
            continue;
        }
        // for (int i = ind; i < ind + n; i++)
        // {
        //     cout << a[i] << ' ';
        // }
        // cout << endl;
        int cnt = 0;
        bool flag = true;
        for (int i = ind + 1; i < ind + n; i++)
        {
            if (a[i] - a[i - 1] > 1)
            {
                flag = false;
                break;
            }
            cnt = cnt + a[i] - a[i - 1];

            if (cnt <= 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}