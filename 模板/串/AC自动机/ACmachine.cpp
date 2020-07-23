#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
const int maxnode = 5e5 + 5, sigmasize = 26;
struct trieNode
{
    int son[sigmasize] = {0};
    int val = 0;
    int fail = 0;
} trie[maxnode];
int cnt;
inline int idx(char c)
{
    return c - 'a';
}
void insert(char *s)
{
    int u = 0, n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int c = idx(s[i]);
        if (!trie[u].son[c])
        {
            cnt++;
            trie[u].son[c] = cnt;
        }
        u = trie[u].son[c];
    }
    trie[u].val++;
}
void getFail()
{
    queue<int> q;
    for (int i = 0; i < sigmasize; i++)
    {
        int ne = trie[0].son[i];
        if (ne)
        {
            q.push(ne);
            trie[ne].fail = 0;
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < sigmasize; i++)
        {
            int &ne = trie[x].son[i];
            if (ne)
            {
                q.push(ne);
                trie[ne].fail = trie[trie[x].fail].son[i];
            }
            else
                ne = trie[trie[x].fail].son[i];
        }
    }
}

int search(char *txt)
{
    int ans = 0;
    int tlen = strlen(txt);
    int u = 0;
    for (int i = 0; i < tlen; i++)
    {
        int c = idx(txt[i]);
        u = trie[u].son[c];
        for (int t = u; t && trie[t].val != -1; t = trie[t].fail)
        {
            ans += trie[t].val;
            trie[t].val = -1;
        }
    }
    return ans;
}
int n;
const int maxn = 1e6 + 6;
char s[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        insert(s);
    }
    getFail();
    scanf("%s", s);
    cout << search(s) << endl;
    return 0;
}