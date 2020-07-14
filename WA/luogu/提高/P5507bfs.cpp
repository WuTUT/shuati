#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 13;
struct State
{
    int s[maxn];
    State() {}
    State(const State &rhs)
    {
        for (int i = 1; i <= 12; i++)
        {
            s[i] = rhs.s[i];
        }
    }
    const bool operator==(const State &rhs) const
    {
        for (int i = 1; i <= 12; i++)
        {
            if (rhs.s[i] != s[i])
            {
                return false;
            }
        }
        return true;
    }
} start, en;
int f[maxn][4];
struct MyHashFunc
{
    size_t operator()(const State &rhs) const
    {
        long long ind = 0;
        for (int i = 1; i <= 12; i++)
        {
            ind = ind * 10 + (rhs.s[i] + 1);
        }
        return std::hash<long long>()(ind);
    }
};
unordered_map<State, int, MyHashFunc> m1, m2;
int bfs()
{
    int step = 0;
    queue<State> q1, q2;
    q1.push(start), q2.push(en);
    if (start == en)
        return 0;
    m1[start] = 0, m2[en] = 0;

    while (1)
    {
        step++;
        int qsz = q1.size();
        for (int i = 0; i < qsz; i++)
        {
            State &sa = q1.front();

            q1.pop();

            for (int j = 1; j <= 12; j++)
            {

                State nes(sa);
                nes.s[j] = (sa.s[j] + 1) % 4;
                nes.s[f[j][nes.s[j]]] = (nes.s[f[j][nes.s[j]]] + 1) % 4;
                if (m1.count(nes) == 0)
                {
                    m1[nes] = j;
                    q1.push(nes);
                }
                if (nes == en)
                {
                    return step;
                }
            }
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    for (int i = 1; i <= 12; i++)
    {
        cin >> start.s[i] >> f[i][0] >> f[i][1] >> f[i][2] >> f[i][3];
        start.s[i]--;
        en.s[i] = 0;
    }

    int ans = bfs();
    cout << ans << endl;
}