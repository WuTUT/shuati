#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
vector<string> a, b;
string fr, to;

unordered_map<string, int> m1, m2;
int bfs()
{
    queue<string> q1, q2;
    q1.push(fr), q2.push(to);
    m1[fr] = 0, m2[to] = 0;
    int dep = 0;
    while (++dep <= 5)
    {
        int qsz = q1.size();
        for (int i = 0; i < qsz; i++)
        {
            string tmp = q1.front();
            q1.pop();
            int dis = m1[tmp];
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

                            if (m1.count(ne) == 0)
                            {
                                m1[ne] = dis + 1;
                                q1.push(ne);
                            }
                            if (m2.count(ne) != 0)
                            {
                                return 2 * dep - 1;
                            }
                        }
                    }
                }
            }
        }
        qsz = q2.size();
        for (int i = 0; i < qsz; i++)
        {
            string tmp = q2.front();
            q2.pop();
            int dis = m2[tmp];
            for (int i = 0; i < tmp.length(); i++)
            {
                for (int j = 1; i + j - 1 < tmp.length(); j++)
                {
                    string tt = tmp.substr(i, j);
                    for (int k = 1; k < b.size(); k++)
                    {
                        if (tt == b[k])
                        {
                            string ne;
                            if (i != 0)
                            {
                                ne = tmp.substr(0, i);
                            }

                            ne = ne + a[k];
                            if (tmp.length() - (i + j) > 0)
                            {
                                ne = ne + tmp.substr(i + j, tmp.length() - (i + j));
                            }

                            if (m2.count(ne) == 0)
                            {
                                m2[ne] = dis + 1;
                                q2.push(ne);
                            }
                            if (m1.count(ne) != 0)
                            {
                                return 2 * dep;
                            }
                        }
                    }
                }
            }
        }
    }
    return -1;
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
    if (fr == to)
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = bfs();
    if (ans != -1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "NO ANSWER!\n";
    }
    return 0;
}
//BFS 16ms 双向bfs可以减半搜索树的深度！！！！！
//注意  一起搜！！！不能搜完一半搜另一半，那样还有屁用
//因为有两个queue，两个hashmap，两个vector<string>所以千万不要弄混，debug很难找出来 深度折半，且返回值可能差1  虽然可能无所谓但是还是特判一下fr==to