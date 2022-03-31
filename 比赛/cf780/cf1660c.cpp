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
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int len = s.length();
        int cnt = 0;
        unordered_set<char> se;
        se.insert(s[0]);
        for (int i = 1; i < len; i++)
        {
            if (se.count(s[i]))
            {
                cnt += se.size() - 1;
                se.clear();
            }
            else
            {
                se.insert(s[i]);
            }
        }
        cnt += se.size();
        printf("%d\n", cnt);
    }

    return 0;
}