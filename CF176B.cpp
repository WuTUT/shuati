#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int k;
char s[int(1005 * 2 + 5)], t[1005];
int f[maxn][2];
int main()
{
    scanf("%s", s);
    scanf("%s", t);
    int slen = strlen(s);
    for (int i = 0; i < slen; i++)
    {
        s[i + slen] = s[i];
    }
    for (int i = 1; i <= 4; i++)
    {
        }
    return 0;
}