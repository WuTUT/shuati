#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 26, maxm = 1e3 + 5;
vector<int> v[maxn];
struct Edge
{
    string s;
    int fr, to;
} edges[maxm];
int n;
bool cmp(const int &a, const int &b)
{
    if (edges[a].s < edges[b].s)
    {
        return true;
    }
    return false;
}
int cnt = 0;
bool connected;
int isvis[maxn];
int in[maxn], out[maxn];
int startal = -1, endal = -1;
int tmp;
void dfs(int ind)
{
    //cout << ind << endl;
    //cout << cnt << endl;
    isvis[ind] = 1;
    tmp++;
    if (tmp == cnt)
    {
        connected = true;
        return;
    }

    for (int i = 1; i <= n; i++)
    {

        int fr = edges[i].fr, to = edges[i].to;
        // cout << fr << to << endl;
        if (fr != to)
        {
            if (fr == ind)
            {
                if (!isvis[to])
                {
                    dfs(to);
                }
            }
            else if (ind == to)
            {
                if (!isvis[fr])
                {
                    dfs(fr);
                }
            }
        }
    }
}
bool isvisedge[maxm];
vector<int> ans;
int ttmp;
bool isfind;
void eula(int ind)
{
    if (isfind)
    {
        return;
    }
    if (ttmp == n)
    {
        for (int i = 0; i < ans.size() - 1; i++)
        {
            cout << edges[ans[i]].s << ".";
        }
        cout << edges[ans[ans.size() - 1]].s << endl;
        isfind = true;
        return;
    }

    for (int i = 0; i < v[ind].size(); i++)
    {
        int ei = v[ind][i];
        if (!isvisedge[ei])
        {
            isvisedge[ei] = true;
            ans.push_back(ei);
            ttmp++;
            eula(edges[ei].to);
            ttmp--;
            ans.pop_back();
            isvisedge[ei] = false;
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);

    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int fr = s[0] - 'a', to = s[s.length() - 1] - 'a';
        v[fr].push_back(i);
        edges[i].fr = fr, edges[i].to = to, edges[i].s = s;
        in[to]++, out[fr]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (in[i] != 0 || out[i] != 0)
        {
            cnt++;
        }
        if (v[i].size() != 0)
        {
            sort(v[i].begin(), v[i].end(), cmp);
        }
    }

    // for (int i = 0; i < 26; i++)
    // {
    //     if (v[i].size())
    //     {
    //         for (int j = 0; j < v[i].size(); j++)
    //         {
    //             cout << edges[v[i][j]].s << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    //cout << edges[1].fr << endl;

    bool isok = true;

    int cntalin = 0, cntalout = 0;
    for (int i = 0; i < 26; i++)
    {
        if (in[i] != out[i])
        {
            if (in[i] - out[i] == -1)
            {
                cntalin++;
                startal = i;
            }
            else if (in[i] - out[i] == 1)
            {
                cntalout++;
                endal = i;
            }
            else
            {
                isok = false;
                break;
            }
        }
    }
    int casea = -1;
    if (cntalout == cntalin && cntalin == 0)
    {
        casea = 1;
    }
    else if (cntalin == cntalout && cntalout == 1)
    {
        casea = 2;
    }
    //cout << isok << " " << casea << endl;
    if (!isok || casea == -1)
    {
        cout << "***" << endl;
        return 0;
    }
    dfs(edges[1].fr);
    if (!connected)
    {
        // cout << "here" << endl;
        cout << "***" << endl;
        return 0;
    }
    if (casea == 2)
    {
        eula(startal);
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (v[i].size() != 0)
            {
                eula(i);
                break;
            }
        }
    }

    return 0;
}
//some case

/*
4
ba
abc
cb
aaz
字典序最小欧拉路径必须回溯，否则找的可能不是欧拉路径
欧拉回路似乎无所谓

*/