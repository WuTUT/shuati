#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 10;
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
    while (scanf("%s", s) && s[0] != '.')
    {
        int slen = strlen(s);
        getMatch(s, slen);
        if (slen % (slen - match[slen]) == 0)
        {
            printf("%d\n", slen / (slen - match[slen]));
        }
        else
        {
            printf("1\n");
        }
    }
    return 0;
}
//poj 2406