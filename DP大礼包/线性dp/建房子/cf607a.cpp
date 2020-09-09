#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int f[maxn];
struct node {
    int a, b;
    bool operator<(const node& rhs) const {
        return a < rhs.a;
    }
}be[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        scanf("%d %d", &be[i].a, &be[i].b);
    }
    sort(be + 1, be + 1 + n);
    for (int i = 1;i <= n;i++) {
        int j = lower_bound(be + 1, be + i, node{ be[i].a - be[i].b,0 }) - be;
        j = max(0, j - 1);
        f[i] = f[j] + 1;
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        ans = max(ans, f[i]);
    }
    printf("%d\n", n - ans);
    return 0;
}