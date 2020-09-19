#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 100;
typedef long long ll;
ll a[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1, ai, bi;i <= n;i++) {
        scanf("%d %d", &ai, &bi);
        a[ai] += bi;
    }
    ll p;
    ll ans = -1;

    if (k == 0) {
        for (int i = 0;i <= 1e6;i++) {
            if (a[i] > 1) {
                ans = max(ans, a[i] * i);
            }
        }
        if (ans == -1) {
            printf("NO\n");
        }
        else {
            printf("%lld", ans);
        }
        return 0;
    }
    for (int i = 0;i <= 1e6;i++) {
        if (a[i] > 0 && i - k >= 0 && a[i - k] > 0) {
            ans = max(ans, min(2 * a[i], 2 * a[i - k]) * (i + i - k) / 2);
        }
        if (a[i] > 0 && i + k <= 1e6 && a[i + k] > 0) {
            ans = max(ans, min(2 * a[i], 2 * a[i + k]) * (i + i + k) / 2);
        }
    }
    if (ans == -1) {
        printf("NO\n");

    }
    else {
        printf("%lld", ans);
    }
    return 0;
}