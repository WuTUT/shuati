#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 105;
int c[maxn];
double t[maxn];
double f[20010];
int main() {
    freopen("data.in", "r", stdin);
    int n;
    int f0;
    while (scanf("%d %d", &n, &f0) != EOF) {
        memset(f, 0, sizeof f);
        int maxc = 0;
        for (int i = 1;i <= n;i++) {
            scanf("%d", &c[i]);
            maxc = max(maxc, c[i]);
            t[i] = floor((1.0 + sqrt(5)) / 2.0 * 1.0 * c[i] * c[i]);
        }
        for (int j = 1;j <= n;j++) {
            f[maxc + 1] += 1.0 / n * t[j];
        }
        for (int i = maxc + 2;i <= 20009;i++) {
            f[i] = f[maxc + 1];
        }
        for (int i = maxc;i >= f0;i--) {
            for (int j = 1;j <= n;j++) {
                if (i > c[j])
                    f[i] += 1.0 * t[j];
                else
                    f[i] += 1.0 * (f[i + c[j]] + 1);
            }
            f[i] /= n;
        }
        printf("%.3lf\n", f[f0]);
    }



    return 0;
}