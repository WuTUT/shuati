#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <array>
using namespace std;
int gc(char a)
{
    return a - '0';
}
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int t;
    cin >> t;
    array<string, 2> s;
    while (t--)
    {
        int n;
        cin >> n;
        cin >> s[0] >> s[1];
        int ans = 0;
        for (int i = 0; i < s[0].length(); i++)
        {
            if (gc(s[0][i]) + gc(s[1][i]) == 1)
            {
                ans += 2;
            }
            else if (s[0][i] == s[1][i] && s[0][i] == '1')
            {
                if (i + 1 < s[0].length() && s[0][i + 1] == s[1][i + 1] && s[0][i + 1] == '0')
                {
                    ans += 2, i++;
                }
            }
            else
            {
                if (i + 1 < s[0].length() && s[0][i + 1] == s[1][i + 1] && s[0][i + 1] == '1')
                {
                    ans += 2, i++;
                }
                else
                    ans += 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}