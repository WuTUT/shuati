#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
typedef long long ll;
// const int N = 105;
int a;
int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            ans = ans | a;
        }
        cout << ans << endl;
    }
    return 0;
}