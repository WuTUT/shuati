#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5e5 + 5;
int f[maxn], a[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n, k, d;
    cin >> n >> k >> d;
    f[0] = 1;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    int p = 1;
    for (int i = 0;i <= n;i++) {
        if (f[i]) {

            int j = max(p, i + k);
            while (j <= n && a[j] - a[i + 1] <= d) {
                f[j] = 1; j++;
            }
            p = j;
        }

    }
    if (f[n]) printf("YES\n");
    else printf("NO\n");
    return 0;
}