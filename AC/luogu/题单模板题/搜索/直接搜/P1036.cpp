#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 22;
int n, k;
int a[maxn];
bool isprime(int n)
{
    if (n == 2)
        return true;
    for (int i = 2; i <= floor(sqrt(n) + 0.5); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int ans;
int sum;
void dfs(int ind, int kt)
{
    if (kt == k)
    {
        if (isprime(sum))
        {
            ans++;
        }
        return;
    }
    if (ind >= n)
    {
        return;
    }
    dfs(ind + 1, kt);
    sum += a[ind];
    dfs(ind + 1, kt + 1);
    sum -= a[ind];
}

int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0);
    cout << ans << endl;
}