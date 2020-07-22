#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
const int maxn = 4e5 + 10;
char s[maxn];
int match[maxn];
void getMatch(char *s, int slen)
{
    int j;
    match[0] = 0, match[1] = 0;
    for (int i = 2; i <= slen; i++)
    {
        j = match[i - 1];
        while (j && s[j] != s[i - 1])
            j = match[j];
        if (s[j] == s[i - 1])
            match[i] = j + 1;
        else
            match[i] = 0;
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    while (scanf("%s", s) != EOF)
    {
        vector<int> ans;
        int slen = strlen(s);
        getMatch(s, slen);
        int j = match[slen];
        while (j)
        {
            ans.push_back(j);
            j = match[j];
        }
        vector<int>::iterator it;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            printf("%d ", ans[i]);
        }
        printf("%d\n", slen);
    }
    return 0;
}
