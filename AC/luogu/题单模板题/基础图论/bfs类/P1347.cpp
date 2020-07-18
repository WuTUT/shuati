#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int maxn = 26;
vector<int> v[maxn];
int n, m;
int in[maxn], tmpin[maxn], cnt;
int g[maxn][maxn];
int ma[maxn], now;
string ans;
int main()
{
    freopen("data.in", "r", stdin);
    scanf("%d%d\n", &n, &m);
    string s;
    for (int step = 1; step <= m; step++)
    {
        getline(cin, s);
        //cout << s << endl;
        int fr = s[0] - 'A', to = s[2] - 'A';
        if (g[fr][to] == 1)
        {
            continue;
        }
        g[fr][to] = 1;
        v[fr].push_back(to);
        in[to]++;
        if (ma[fr] == 0)
        {
            ma[fr] = 1;
            now += 1;
        }
        if (ma[to] == 0)
        {
            ma[to] = 1;
            now += 1;
        }
        memcpy(tmpin, in, sizeof in);
        ans.clear();
        cnt = 0;
        bool isok = true;
        bool iscons = false;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (ma[i] == 1 && tmpin[i] == 0)
            {
                q.push(i);
                cnt++;
            }
        }
        if (q.empty())
        {
            printf("Inconsistency found after %d relations.", step);
            return 0;
        }

        while (!q.empty())
        {
            int qsz = q.size();
            if (qsz > 1)
            {
                isok = false;
            }
            int x = q.front();
            q.pop();
            ans.push_back(x + 'A');
            for (int i = 0; i < v[x].size(); i++)
            {
                int to = v[x][i];
                if (--tmpin[to] == 0)
                {
                    q.push(to);
                    cnt++;
                }
            }
        }
        if (cnt == n && isok)
        {
            printf("Sorted sequence determined after %d relations: ", step);
            cout << ans << "." << endl;
            return 0;
        }
        else if (cnt == now)
        {
            continue;
        }
        else
        {
            printf("Inconsistency found after %d relations.", step);
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.\n");
    return 0;
}