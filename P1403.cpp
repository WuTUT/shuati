#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans += n / i;
    cout << ans;
}