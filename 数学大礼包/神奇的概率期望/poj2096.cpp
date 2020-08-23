#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 1005;
double f[maxn][maxn];
int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = s - 1;i >= 0;i--) {
        f[i][n] = f[i + 1][n] + 1.0 * s / (s - i);
    }
    for (int j = n - 1;j >= 0;j--) {
        f[s][j] = f[s][j + 1] + 1.0 * n / (n - j);
    }
    for (int i = s - 1;i >= 0;i--) {
        for (int j = n - 1;j >= 0;j--) {
            f[i][j] = (1.0 * s * n + (s - i) * 1.0 * j * f[i + 1][j] + (s - i) * 1.0 * (n - j) * f[i + 1][j + 1] + i * 1.0 * (n - j) * f[i][j + 1]) / (1.0 * s * n - 1.0 * i * j);
        }
    }
    printf("%.4lf", f[0][0]);
    return 0;
}