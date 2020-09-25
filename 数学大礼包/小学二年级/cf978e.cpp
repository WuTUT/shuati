#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1005;
int a;
typedef long long ll;
ll sum;
ll w, n;
int main() {

    freopen("data.in", "r", stdin);
    cin >> n >> w;
    ll minw = 0;ll maxw = w;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a);
        sum += a;
        maxw = min(maxw, w - sum);
        minw = max(minw, -sum);
    }
    int ans = maxw - minw + 1;
    ans = max(ans, 0);
    printf("%d\n", ans);
    return 0;
}