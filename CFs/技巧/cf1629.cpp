#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

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
        string s;
        set<string> se2, se3, se3h;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (ans)
                continue;
            if (string{s.rbegin(), s.rend()} == s)
                ans = true;
            if (s.length() == 2)
            {

                if (se2.count({s.rbegin(), s.rend()}))
                {
                    ans = true;
                }
                if (se3h.count({s.rbegin(), s.rend()}))
                {
                    ans = true;
                }
                se2.insert(s);
            }
            else if (s.length() == 3)
            {

                if (se3.count({s.rbegin(), s.rend()}))
                    ans = true;
                if (se2.count({s.rbegin(), s.rbegin() + 2}))
                    ans = true;
                se3.insert(s);
                se3h.insert({s.begin(), s.end() - 1});
            }
        }
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}