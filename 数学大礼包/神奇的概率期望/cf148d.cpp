#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1005;
double f[maxn][maxn][2];
int main() {
    int w, b;
    scanf("%d %d", &w, &b);
    for (int i = 1;i <= w;i++) {
        f[i][0][0] = 1;
    }
    for (int i = 1;i <= w;i++) {
        for (int j = 1;j <= b;j++) {
            f[i][j][0] = 1.0 * i / (i + j) + 1.0 * j / (i + j) * f[i][j - 1][1];
            f[i][j][1] = 1.0 * j / (i + j) * i / (i + j - 1) * f[i - 1][j - 1][0];
            if (j > 1) f[i][j][1] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * f[i][j - 2][0];
        }
    }
    printf("%.12lf\n", f[w][b][0]);
    return 0;
}
