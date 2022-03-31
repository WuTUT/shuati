#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int fa[N], a[N], b[N], sz[N];

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0)
            cout << 1 << endl;
        else
            cout << 2 * b + a + 1 << endl;
    }

    return 0;
}