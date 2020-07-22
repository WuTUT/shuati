#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5e4 + 5;
char s[maxn << 1], t[maxn];

int match[maxn << 1];
void getMatch(char *s, int slen)
{
    match[0] = 0, match[1] = 0;
    int j;
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
    int kase = 0;
    while (scanf("%s%s", s, t) != EOF)
    {

        int slen = strlen(s);
        int tmp = slen;

        for (int i = 0; t[i]; i++)
        {
            s[slen++] = t[i];
        }
        int tmp2 = slen - tmp;
        //cout << tmp << "  " << tmp2 << endl;
        getMatch(s, slen);
        int j = match[slen];
        while (j > tmp || j > tmp2)
        {
            j = match[j];
        }
        if (j == 0)
        {
            printf("0\n");
        }
        else
        {
            for (int k = 0; k < j; k++)
            {
                printf("%c", s[k]);
            }

            printf(" %d\n", j);
        }
    }
    return 0;
}