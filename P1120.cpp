#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 67;
int n, a[maxn], nn, maxa;
int sum;
bool check;
int len, tot;
int isvis[67];
bool isfind;
bool dfs(int tmp, int totnow, int ind)
{
    if (tot == totnow)
    {
        printf("%d\n", len);
        isfind = true;
        return true;
    }
    if (tmp == len)
    {

        return dfs(0, totnow + 1, 0);
    }

    for (int i = ind; i < n; i++)
    {
        if (!isvis[i] && (tmp + a[i] <= len))
        {
            isvis[i] = 1;
            if (dfs(tmp + a[i], totnow, i + 1))
            {
                return true;
            }
            isvis[i] = 0;
            if (len - tmp == a[i] || tmp == 0) //????????????
                break;
            while (a[i + 1] == a[i])
                i++;
        }
    }
    return false;
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> nn;
    int x;
    for (int i = 0; i < nn; i++)
    {
        cin >> x;
        if (x <= 50)
        {
            a[n++] = x;
            sum += x;
            maxa = max(maxa, x);
        }
    }
    sort(a, a + n, greater<int>());
    for (len = maxa; len <= sum / 2; len++)
    {
        if (sum % len != 0)
            continue;
        else
            tot = sum / len;
        if (isfind)
        {
            break;
        }
        dfs(0, 0, 0);
    }
    if (!isfind)
    {
        cout << sum << endl;
    }
    return 0;
}