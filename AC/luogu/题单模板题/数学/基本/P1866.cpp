#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 1000000007;
int a[52];
int main()
{
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long ans = a[0];
    for (int i = 1; i < n; i++)
    {
        ans = (a[i] - i) * ans % mod;
    }
    cout << ans << endl;
}