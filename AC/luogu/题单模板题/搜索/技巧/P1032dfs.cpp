#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
using namespace std;
vector<string> a, b;
string fr, to;
int ans = 25;
set<string> isvis;
bool isfind;
int dep;
void dfs(int kt, string tmp)
{

    if (tmp == to)
    {
        ans = min(ans, kt);
        isfind = true;
    }
    if (kt >= dep)
    {
        return;
    }
    for (int i = 0; i < tmp.length(); i++)
    {
        for (int j = 1; i + j - 1 < tmp.length(); j++)
        {
            string tt = tmp.substr(i, j);
            for (int k = 1; k < a.size(); k++)
            {
                if (tt == a[k])
                {
                    string ne;
                    if (i != 0)
                    {
                        ne = tmp.substr(0, i);
                    }

                    ne = ne + b[k];
                    if (tmp.length() - (i + j) > 0)
                    {
                        ne = ne + tmp.substr(i + j, tmp.length() - (i + j));
                    }

                    if (isvis.count(ne) == 0)
                    {
                        isvis.insert(ne);
                        dfs(kt + 1, ne);
                        isvis.erase(ne);
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        a.push_back(s1);
        b.push_back(s2);
    }
    fr = a[0], to = b[0];

    for (dep = 1; dep < 11; dep++)
    {
        if (isfind)
        {
            break;
        }
        dfs(0, fr);
    }

    if (ans != 25)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "NO ANSWER!\n";
    }
    return 0;
}

//DFS + 迭代加深只拿到了80分，最后一个点很难不T