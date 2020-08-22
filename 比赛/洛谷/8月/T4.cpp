#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e5 + 5;
typedef long long ll;
struct node {
    int a, x, id;
    bool operator<(const  node& rhs) const {
        return a < rhs.a;
    }
}no[maxn];
int a[maxn], x[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1;i <= n;i++) {
        scanf("%d", &x[i]);

    }
    for (int i = 1;i <= n;i++) {
        no[i].a = a[i], no[i].x = x[i], no[i].id = i;
    }
    sort(no + 1, no + 1 + n);
    ll ans = 0;
    int l = n / 2, r = n - l + 1;int cnt = 1;
    while (l != 1 || r != (n / 2 + 1)) {
        if (no[l].x != no[r].id) {
            ans += 1ll * a[l] * cnt;
        }
    }
    for (int i = n / 2;i >= 1;i--) {


    }

    return 0;
}