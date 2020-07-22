#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 7;
char s[maxn], t[maxn];
int match[maxn];
void getMatch(int len, char *s)
{
    int j;
    match[0] = 0, match[1] = 0;
    for (int i = 2; i <= len; i++)
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
void kmp(char *s, char *t, int tlen, int slen)
{
    int j = 0;
    for (int i = 0; i < tlen; i++)
    {
        while (j && s[j] != t[i])
            j = match[j];
        if (t[i] == s[j])
            j++;
        if (j == slen)
        {
            printf("%d\n", i - slen + 2);
            j = match[j];
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    scanf("%s%s", t, s);
    int slen = strlen(s);
    int tlen = strlen(t);
    getMatch(slen, s);
    kmp(s, t, tlen, slen);
    for (int i = 1; i <= slen; i++)
    {
        printf("%d ", match[i]);
    }
    return 0;
}