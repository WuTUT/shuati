#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int main()
{
    freopen("data.in", "r", stdin);
    set<int> s;
    int n;
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if (x == 1)
        {
            if (s.find(y) != s.end())
            {
                cout << "Already Exist" << endl;
            }
            else
            {
                s.insert(y);
            }
        }
        else if (x == 2)
        {

            if (s.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                auto it = s.lower_bound(y);
                if (it == s.end())
                {
                    it--;
                    cout << *it << endl;
                    s.erase(it);
                }
                else if (it == s.begin())
                {
                    cout << *it << endl;
                    s.erase(it);
                }
                else
                {
                    auto la = it;
                    la--;
                    if (abs(*it - y) < abs(*la - y))
                    {
                        cout << *it << endl;
                        s.erase(it);
                    }
                    else
                    {
                        cout << *la << endl;
                        s.erase(la);
                    }
                }
            }
        }
    }
    return 0;
}