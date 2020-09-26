#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int x[maxn];
int main() {
    int ans = 0;

    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    int a;
    cin >> a;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &x[i]);

    }

    if (n == 1) {
        printf("0\n");
        return 0;
    }
    sort(x + 1, x + 1 + n);
    if (a >= x[n]) {
        ans = a - x[2];
    }
    else if (a <= x[1]) {
        ans = x[n - 1] - a;
    }
    else {
        ans = min(abs(a - x[2]) + x[n] - x[2], x[n] - a + x[n] - x[2]);

        ans = min(ans, abs(x[n - 1] - a) + x[n - 1] - x[1]);
        ans = min(ans, a - x[1] + x[n - 1] - x[1]);
    }

    printf("%d\n", ans);

    return 0;
}