#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    long long ans1 = 0, ans2 = 0;
    for (int i = 1; i <= min(n, m); i++)
    {

        ans1 += (n + 1 - i) * (m + 1 - i);
    }
    ans2 = 1LL * n * (n + 1) / 2 * (m + 1) * m / 2; //注意1LL
    cout << ans1 << " " << ans2 - ans1 << endl;
    return 0;
}