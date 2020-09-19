#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
// ll gcd(ll x, ll y) {
//     if (y == 0) return x;
//     return gcd(y, x % y);
// }
const int maxn = 3e5 + 5;
unordered_map<int, int> ma;
unordered_map<int, bool> use;
struct node {
    int a, sz;
    bool operator<(const node& rhs) const {
        return a < rhs.a;
    }
}no[maxn];
int main() {
    freopen("data.in", "r", stdin);
    // for (int i = 1;i <= 1000;i++) {
    //     for (int j = i + 1;j <= 3 * i;j++) {
    //         if (i + j + gcd(i, j) == i * j / gcd(i, j)) {
    //             printf("%d %d %d\n", i, j, i - j);
    //             //break;
    //         }
    //     }
    // }
    int n;
    scanf("%d", &n);
    for (int i = 1, ai;i <= n;i++) {
        scanf("%d", &ai);
        ma[ai]++;
        use[ai] = false;
    }
    int cnt = 0;
    for (auto it = ma.begin();it != ma.end();it++) {
        int fir = (*it).first, sec = (*it).second;
        no[cnt].a = fir, no[cnt].sz = sec;
        cnt++;
    }
    sort(no, no + cnt);
    ll ans = 0;
    for (int i = 0;i < cnt;i++) {
        int fir = no[i].a, sec = no[i].sz;

        if (use[fir] == false) {
            use[fir] = true;
            //printf("%d %d\n", fir, sec);
            if (fir % 2 == 0) {
                ll tmp = 1ll * fir * sec;//bu kai long long
                ll nxt = 1ll * fir + 1ll * fir / 2;
                while (ma.find(nxt) != ma.end()) {
                    tmp += 1ll * ma[nxt] * nxt;
                    use[nxt] = true;
                    if (nxt % 2 == 1) break;
                    nxt = nxt + nxt / 2;

                }
                ans = max(ans, tmp);
            }
            else {
                ans = max(ans, 1ll * fir * sec);
            }

        }
    }
    cout << ans << endl;
    return 0;
}