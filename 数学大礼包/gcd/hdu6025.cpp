#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 100005;
typedef long long ll;
int n;
int a[maxn];
int g1[maxn], g2[maxn];
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int main() {
    freopen("data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        g1[0] = 0;g2[n + 1] = 0;

        for (int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
            g1[i] = gcd(g1[i - 1], a[i]);
        }
        for (int i = n;i >= 1;i--) {
            g2[i] = gcd(g2[i + 1], a[i]);
        }
        int ans = 1;
        for (int i = 1;i <= n;i++) {
            ans = max(ans, gcd(g1[i - 1], g2[i + 1]));
        }
        printf("%d\n", ans);
    }
    return 0;
}