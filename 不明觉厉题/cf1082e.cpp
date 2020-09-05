#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5e5 + 5;
int sumc, a[maxn], suma[maxn], mind[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n, c;
    cin >> n >> c;

    int ans = 0;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        if (a[i] == c) {
            sumc++;
        }
        else {
            mind[a[i]] = min(mind[a[i]], suma[a[i]] - sumc);
            suma[a[i]]++;
            ans = max(ans, suma[a[i]] - sumc - mind[a[i]]);
        }
    }
    printf("%d\n", ans + sumc);
    return 0;
}