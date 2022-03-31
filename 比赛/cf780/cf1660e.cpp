// failed
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
const int N = 2e3 + 10;
int a[N][N];
int ad[N], ac[N];
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
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                a[i][j] = s[j] - '0';
                cnt += a[i][j];
            }
        }
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++)
        {
            ad[i] = 0;
            for (int j = 0; j < n; j++)
            {
                ad[i] = ad[i] | a[i][j];
            }
            s1 += ad[i];
        }
        for (int j = 0; j < n; j++)
        {
            ac[j] = 0;
            for (int i = 0; i < n; i++)
            {
                ac[j] = ac[j] | a[i][j];
            }
            s2 += ac[j];
        }
        // cout << "debug " << s1 << " " << s2 << endl;
        // cout << "debug " << cnt << endl;

        cnt -= min(s1, s2);
        cnt += max(n - min(s1, s2), 0);
        cout << cnt << endl;
    }

    return 0;
}