#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int f[32];
int n, ans;
int main() {
    freopen("data.in", "r", stdin);
    cin >> n;
    int a;

    for (int i = 1;i <= n;i++) {
        scanf("%d", &a);
        int k = 0;
        for (int j = 0;j < 32;j++) {
            if ((a >> j) & 1) {
                k = max(k, f[j] + 1);
            }
        }
        for (int j = 0;j < 32;j++) {
            if ((a >> j) & 1)
                f[j] = max(f[j], k);
        }
    }
    for (int i = 0;i < 32;i++) {
        ans = max(ans, f[i]);
    }
    (ans == 1) ? printf("%d\n", 0) : printf("%d\n", ans);
    return 0;
}