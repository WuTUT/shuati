#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], d[maxn];
int cl[maxn], cr[maxn], v[maxn];
int n, m;
bool judge(int mid) {
    memset(d, 0, sizeof d);
    for (int i = 1;i <= mid;i++) {
        d[cl[i]] -= v[i], d[cr[i] + 1] += v[i];
    }
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        sum += d[i];
        if (a[i] + sum < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1;i <= m;i++) {
        scanf("%d %d %d", &v[i], &cl[i], &cr[i]);
    }
    int l = 1, r = m;
    while (l < r) {
        int mid = (l + r) / 2;
        if (!judge(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (judge(l) == false) l--;
    if (l == m) {
        printf("%d\n", 0);
    }
    else {
        printf("-1\n%d\n", l + 1);
    }
    return 0;
}