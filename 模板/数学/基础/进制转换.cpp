#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int ans[1000];
int n, m;
string s;
typedef long long ll;
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    cin >> s;
    cin >> m;
    ll t = 0;
    int o;
    for (int i = 0; i < s.size(); i++)
    {

        if ('A' <= s[i] && s[i] <= 'F')
        {

            o = s[i] - 'A' + 10;
        }
        else
        {
            o = s[i] - '0';
        }
        t = t * n + o;
    }
    // cout << t << endl;
    if (t == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << t << endl;
    int top = 0;
    while (t)
    {
        ans[top++] = t % m;
        t /= m;
    }
    char ss;
    for (int i = top - 1; i >= 0; i--)
    {
        if (ans[i] <= 15 && ans[i] >= 10)
        {
            ss = ans[i] - 10 + 'A';
        }
        else
        {
            ss = ans[i] + '0';
        }
        cout << ss;
    }
    cout << endl;
    return 0;
}
//P1143 n 转m进制