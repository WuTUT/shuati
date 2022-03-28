#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
string s;
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
        cin >> s;
        int ans = 0;
        int cnt = 0;
        int sts = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && sts == 0)
            {
                sts = 1;
                cnt += 2;
            }
            else if (s[i] == '0' && sts == 1)
            {
                ans += cnt;
                cnt = 2;
            }
            else if (s[i] == '1' && sts == 1)
            {
                cnt = max(cnt - 1, 0);
            }
        }
        // ans += cnt;
        printf("%d\n", ans);
    }
    return 0;
}