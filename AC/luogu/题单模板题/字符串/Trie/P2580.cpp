#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxnode = 5e5 + 5, sigmasize = 26;
struct Trie
{
    int ch[maxnode][sigmasize];
    int val[maxnode];
    int sz;
    Trie() : sz(1)
    {
        memset(ch[0], 0, sizeof ch[0]);
        //memset(val, 0, sizeof val);
    }
    int idx(char c) { return c - 'a'; }
    void insert(char *s)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
            {
                memset(ch[sz], 0, sizeof ch[sz]);
                val[sz] = 0;
                ch[u][c] = sz;
                sz++;
            }
            u = ch[u][c];
        }
        val[u] = 1;
    }
    int search(char *s)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
            {
                //printf("%c  ", c + 'a');
                //cout << "here" << endl;
                return 0;
            }

            u = ch[u][c];
        }
        if (val[u] == 0)
            return 0;
        else
        {
            if (val[u] == 1)
            {
                val[u]++;
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
} trie;
int n, m;
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    char name[57];
    for (int i = 0; i < n; i++)
    {
        scanf("%s\n", name);
        //printf("%s\n", name);
        trie.insert(name);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%s\n", name);
        int res = trie.search(name);
        if (res == 1)
        {
            printf("OK\n");
        }
        else if (res == 0)
        {
            printf("WRONG\n");
        }
        else
        {
            printf("REPEAT\n");
        }
    }
    return 0;
}
