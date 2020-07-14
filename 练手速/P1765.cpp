#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    freopen("data.in", "r", stdin);
    string s;
    int ans = 0;
    getline(cin, s);
    //cout << s << endl;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ans++;
        }
        else if (s[i] <= 'r')
        {
            ans += (s[i] - 'a') % 3 + 1;
        }
        else
        {
            if (s[i] == 's')
                ans += 4;
            else if (s[i] <= 'v')
            {
                ans += s[i] - 't' + 1;
            }
            else
            {
                ans += s[i] - 'w' + 1;
            }
        }
    }
    cout << ans - 1 << endl;
}