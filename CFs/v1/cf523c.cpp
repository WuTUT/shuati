#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
string s, t;
int ls, lt;
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    cin >> s >> t;
    ls = s.length(), lt = t.length();
    int la = 0, lb = lt - 1;
    if (ls >= lt)
    {
        printf("0\n");
        return 0;
    }

    int i;
    for (i = 0; i < ls && la < lt;)
    {
        if (s[i] == t[la])
        {
            i++, la++;
        }
        else
        {
            la++;
        }
    }
    if (i != ls)
    {
        printf("0\n");
        return 0;
    }
    la--;
    for (i = ls - 1; i >= 0 && lb >= 0;)
    {
        if (s[i] == t[lb])
        {
            i--, lb--;
        }
        else
        {
            lb--;
        }
    }
    lb++;
    if (i != -1)
    {
        printf("0\n");
        return 0;
    }
#ifdef FDEBUG
    cout << t.substr(0, la) << " " << t.substr(lb) << endl;
#endif
    int ans = lb - la;
    ans = max(ans, 0);
    printf("%d\n", ans);

    return 0;
}