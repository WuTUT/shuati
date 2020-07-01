#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;
const int maxn = 110;
int f[maxn][maxn];
bool judge(string &x, string &y)
{
    int xsz = x.size();
    int ysz = y.size();
    int ha[26], hb[26];
    memset(ha, 0, sizeof ha);
    memset(hb, 0, sizeof hb);
    for (int i = 0; i < xsz; i++)
    {
        ha[x[i] - 'a']++;
    }
    for (int i = 0; i < ysz; i++)
    {
        hb[y[i] - 'a']++;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (ha[i] != 0)
        {
            cnt += min(ha[i], hb[i]);
        }
    }
    //cout << cnt;
    if (cnt * 2 > xsz)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    freopen("data.in", "r", stdin);

    string line;
    getline(cin, line);
    stringstream ss(line);
    string x;
    vector<string> a, b;
    while (ss >> x)
    {
        a.push_back(x);
    }
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << endl;
    // }
    getline(cin, line);
    stringstream sss(line);
    while (sss >> x)
    {
        b.push_back(x);
    }
    // for (int i = 0; i < b.size(); i++)
    // {
    //     cout << b[i] << endl;
    // }
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= a.size(); i++)
    {
        // f[i][0] = 2 * i;
        f[i][0] = i;
    }
    for (int j = 0; j <= b.size(); j++)
    {
        //f[0][j] = j;
        f[0][j] = 2 * j;
    }
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            //cout << a[i - 1] << "  " << b[j - 1] << endl;
            if (a[i - 1] == b[j - 1])
            {
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
            else
            {
                if (judge(a[i - 1], b[i - 1]))
                {
                    f[i][j] = min(f[i][j], f[i][j - 1] + 1);
                    f[i][j] = min(f[i][j], f[i - 1][j] + 2);
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                }
                else
                {
                    f[i][j] = min(f[i][j], f[i][j - 1] + 1);
                    f[i][j] = min(f[i][j], f[i - 1][j] + 2);
                    //f[i][j]=min(f[i][j],f[i-1][j-1]+3) //???
                }
            }
        }
    }

    cout << f[a.size()][b.size()] << endl;
    int ans = a.size() - f[a.size()][b.size()];
    cout << ans << endl;
    return 0;
}