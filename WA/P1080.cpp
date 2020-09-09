#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1005;
struct node {
    int a, b;
    ll a_b;
    bool operator<(const node& rhs) const {
        return a_b < rhs.a_b;
    }
}no[maxn];

int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0;i <= n;i++) {
        scanf("%d %d", &no[i].a, &no[i].b);
        no[i].a_b = 1ll * no[i].a * no[i].b;
    }
    sort(no + 1, no + 1 + n);
    ll x = no[0].a; ll ans = 0;
    for (int i = 1;i < n;i++) {
        x *= no[i].a;
    }
    ans = x / no[n].b;
    printf("%lld\n", ans);
    return 0;
}