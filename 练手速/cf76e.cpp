#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
ll sumx, sumy, sumsq;
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1, xi, yi;i <= n;i++) {
        scanf("%d %d", &xi, &yi);
        sumsq += xi * xi + yi * yi;
        sumx += xi;
        sumy += yi;
    }
    ll ans = sumsq * n - sumy * sumy - sumx * sumx;
    printf("%lld\n", ans);
    return 0;
}