#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull mod = 212370440130137957LL;
ull lucky = 233317;
ull base = 131;
ull strhash(string &s)
{
    int slen = s.length();
    ull hashnum = 0;
    for (int i = 0; i < slen; i++)
    {
        hashnum = (hashnum * base + (ull)s[i]) % mod + lucky;
    }
    return hashnum;
}
const int maxn = 1e4 + 5;
ull ha[maxn];
int n;
int main()
{
    freopen("data.in", "r", stdin);
    scanf("%d\n", &n);
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        ha[i] = strhash(s);
    }
    sort(ha, ha + n);
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (ha[i] != ha[i - 1])
        {
            ans++;
        }
    }
    cout << ans;
}