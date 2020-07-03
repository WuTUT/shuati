#include <iostream>
#include <cstdio>
#include <algorithm>
//#include <unordered_map>
using namespace std;
int n, k;
const int maxn = 1e6 + 4;
int a[maxn], b[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n >> k;
    int r, c;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d %d ", &r, &c);
        a[i] = r, b[i] = c;
    }
    sort(a + 1, a + k + 1), sort(b + 1, b + k + 1);
    long long cnt1 = 1, cnt2 = 1;
    for (int i = 1; i < k; i++)
    {
        if (a[i] != a[i + 1])
            cnt1++;
        if (b[i] != b[i + 1])
            cnt2++;
    }
    cout << 1ll * n * n - (n - cnt1) * (n - cnt2) << endl;

    return 0;
}
// int main()
// {
//     cin >> n >> k;
//     unordered_map<int, int> ma;
//     unordered_map<int, int> mb;
//     int r, c;
//     for (int i = 1; i <= k; i++)
//     {
//         scanf("%d%d", &r, &c);
//         ma[r]++;
//         mb[c]++;
//     }
//     long long cnt1 = n - ma.size(), cnt2 = n - mb.size();

//     cout << 1ll * n * n - cnt2 * cnt1 << endl;

//     return 0;
// }

//卡常数