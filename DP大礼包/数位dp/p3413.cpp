#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
int a[1005];
ll f[1005][11][11][2];//开11 不然把错误的状态赋了进去
char l[1005], r[1005];
ll dfs(bool lead, bool eq, int pos, int pre, int prepre, bool has)
{
    if (pos == 0)
    {
        if (has && !lead)
            return 1;
        return 0;
    }
    if (!eq && !lead && ~f[pos][pre][prepre][has])
        return f[pos][pre][prepre][has];
    int ed = eq ? a[pos] : 9;
    ll ret = 0;
    for (int i = 0; i <= ed; i++)
    {
        if (lead && i == 0) {
            ret = ret + dfs(lead && i == 0, eq && i == ed, pos - 1, 10, pre, has);//如果有前导0，显然这个0不应该能和后面出现的0比较，所以传10进去
        }
        else {
            ret = ret + dfs(lead && i == 0, eq && i == ed, pos - 1, i, pre, has || (i == pre) || (i == prepre));
        }
        ret %= mod;
    }
    if (!eq && !lead)
        f[pos][pre][prepre][has] = ret;//开11 不然把错误的状态赋了进去

    return ret;
}
ll solve(char s[])
{
    a[0] = strlen(s);

    for (int i = 1; i < a[0]; i++)
    {
        a[i] = s[a[0] - i] - '0';
    }

    a[0]--;

    memset(f, -1, sizeof f);
    return dfs(true, true, a[0], 10, 10, false);
}
int ispa(char s[])
{
    int n = strlen(s);
    if (n == 2)
        return 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == s[i + 1]) return 1;
    }
    for (int i = 1;i < n - 2;i++) {
        if (s[i] == s[i + 2]) return 1;
    }
    return 0;
}
int main()
{
    scanf("%s %s", l + 1, r + 1);
    l[0] = '0', r[0] = '0';
    //printf("%s %s\n", l + 1, r + 1);
    printf("%lld\n", (solve(r) - solve(l) + ispa(l) + mod) % mod);
}