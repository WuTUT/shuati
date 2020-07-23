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
    void clear()
    {
        memset(son, 0, sizeof son);
        val = 0;
        fail = 0;
    }
} trie[maxnode];
int n;
const int maxn = 1e6 + 6;
char s[maxn][155], t[maxn];
int vis[maxn];
int cnt;
inline int idx(char c)
{
    return c - 'a';
}
void insert(char *s, int v)
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
    trie[u].val = v;
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

void search(char *txt)
{

    int tlen = strlen(txt);
    int u = 0;
    for (int i = 0; i < tlen; i++)
    {
        int c = idx(txt[i]);
        u = trie[u].son[c];
        for (int t = u; t; t = trie[t].fail)
        {
            if (trie[t].val)
            {
                vis[trie[t].val]++;
            }
        }
    }
}
void clear()
{
    for (int i = 0; i <= cnt; i++)
    {
        vis[i] = 0;
        trie[i].clear();
    }
    cnt = 0;
}
int main()
{
    freopen("data.in", "r", stdin);
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        clear();
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", s[i]);
            insert(s[i], i);
        }
        getFail();
        scanf("%s", t);
        search(t);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = max(vis[i], ans);
        }
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++)
        {
            if (ans == vis[i])
            {
                printf("%s\n", s[i]);
            }
        }
    }

    return 0;
}