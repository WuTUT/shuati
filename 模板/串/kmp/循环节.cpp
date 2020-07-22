#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 85;
char s[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        int slen = strlen(s);
        int j;
        for (j = 1; j <= slen; j++)
        {
            if (slen % j == 0)
            {
                if (strncmp(s + j, s, slen - j) == 0)
                {
                    break;
                }
            }
        }
        cout << j << endl;
        if (i != n - 1)
        {
            cout << endl;
        }
    }
    return 0;
}
//https://vjudge.net/problem/UVA-455