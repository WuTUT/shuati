#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 8000;
double f[2][maxn];
int ans[1005];
int main() {
    freopen("data.in", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);

    // for (int i = 1;i < maxn;i++) {
    //     f[1 & 1][i] = 1.0;
    // }
    f[0][0] = 1.0;
    for (int i = 1;i <= n;i++) {
        int p = i & 1;
        f[p][0] = 0;
        for (int j = 1;j < maxn;j++) {
            f[p][j] = f[p][j - 1] * i / n + f[p ^ 1][j - 1] * (n - i + 1) / n;
        }

        // for (int j = 0;j < 10;j++) {
        //     printf("%lf ", f[p][j]);
        // }
        // printf("\n");
    }

    for (int i = 1;i <= 1000;i++) {
        double tmp = i * 1.0 / 2000;
        int ptr = 0;
        while (f[n & 1][ptr] < tmp) {
            ptr++;
        }
        ans[i] = ptr;
    }
    int pi;
    while (k--) {
        scanf("%d", &pi);
        printf("%d\n", ans[pi]);
    }
    return 0;
}
