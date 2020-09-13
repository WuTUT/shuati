#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1005;
int p, n, s;
int a[maxn], b[maxn];
int f[maxn];
bool judge(int mid) {
    memset(f, 0, sizeof f);
    for (int i = 1;i <= n;i++) {
        for (int j = s;j >= a[i];j--) {
            if (a[i] <= mid) {
                f[j] = max(f[j], f[j - a[i]] + b[i]);
            }
        }
        if (f[s] >= p) return true;
    }
    return f[s] >= p;
}
int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> p >> s;
    for (int i = 1;i <= n;i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    int l = 1, r = s;
    while (l < r) {
        int mid = (l + r) / 2;
        if (judge(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (!judge(l)) l++;
    if (l > s) printf("No Solution!\n");
    else printf("%d\n", l);
    return 0;
}