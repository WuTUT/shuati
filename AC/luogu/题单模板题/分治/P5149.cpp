// #include <iostream>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// using namespace std;
// const int maxnode = 5e5 + 10, sigmasize = 52;
// struct Trie
// {
//     int sz;
//     int val[maxnode];
//     int ch[maxnode][sigmasize];
//     Trie() : sz(1)
//     {
//         memset(ch[0], 0, sizeof ch[0]);
//     }
//     int idx(char c)
//     {
//         if (c <= 'Z')
//             return c - 'A';
//         else
//             return c - 'a' + 26;
//     }
//     void insert(char *s, int v)
//     {
//         int u = 0, n = strlen(s);
//         for (int i = 0; i < n; i++)
//         {
//             int c = idx(s[i]);
//             if (!ch[u][c])
//             {
//                 memset(ch[sz], 0, sizeof ch[sz]);
//                 val[sz] = 0;
//                 ch[u][c] = sz;
//                 sz++;
//             }
//             u = ch[u][c];
//         }
//         val[u] = v;
//     }
//     int search(char *s)
//     {
//         int u = 0, n = strlen(s);
//         for (int i = 0; i < n; i++)
//         {
//             int c = idx(s[i]);
//             u = ch[u][c];
//         }
//         return val[u];
//     }
// } trie;
// int n;
// const int maxn = 1e5 + 5;
// char ini[maxn][6], tmp[maxn][6];
// typedef long long ll;
// ll cnt;
// void merge(int l, int r)
// {
//     if (r - l >= 1)
//     {
//         int mid = (l + r) / 2;

//         merge(l, mid);
//         merge(mid + 1, r);
//         int t = l, p = mid + 1;
//         int tot = l;

//         while (t <= mid || p <= r)
//         {
//             if (p > r || (t <= mid && trie.search(ini[t]) < trie.search(ini[p])))
//             {
//                 memcpy(tmp[tot], ini[t], 6);
//                 tot++, t++;
//             }
//             else
//             {
//                 cnt += mid - t + 1;
//                 memcpy(tmp[tot], ini[p], 6);
//                 tot++, p++;
//             }
//         }
//         for (int i = l; i <= r; i++)
//         {
//             memcpy(ini[i], tmp[i], 6);
//         }
//     }
// }
// int main()
// {
//     freopen("data.in", "r", stdin);
//     cin >> n;
//     char s[10];
//     for (int i = 1; i <= n; i++)
//     {
//         scanf("%s", s);

//         trie.insert(s, i);
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         scanf("%s", s);
//         memcpy(ini[i], s, 6);
//     }

//     merge(1, n);
//     for (int i = 1; i <= n; i++)
//     {
//         cout << ini[i] << endl;
//     }
//     cout << cnt << endl;
//     return 0;
// }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int s[maxn], tmp[maxn];
unordered_map<string, int> ma;
typedef long long ll;
ll cnt;
void merge(int l, int r)
{
    if (r - l >= 1)
    {
        int mid = (l + r) / 2;

        merge(l, mid);
        merge(mid + 1, r);
        int t = l, p = mid + 1;
        int tot = l;

        while (t <= mid || p <= r)
        {
            if (p > r || (t <= mid && s[t] <= s[p]))
            {
                tmp[tot++] = s[t++];
            }
            else
            {
                cnt += mid - t + 1;
                tmp[tot++] = s[p++];
            }
        }
        for (int i = l; i <= r; i++)
        {
            s[i] = tmp[i];
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    string name;
    for (int i = 1; i <= n; i++)
    {
        cin >> name;
        ma[name] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> name;
        s[i] = ma[name];
    }

    merge(1, n);

    cout << cnt << endl;
    return 0;
}