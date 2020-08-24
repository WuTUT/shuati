#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 103;
double f[maxn][maxn][maxn];
int main() {
    int r, s, p;
    cin >> r >> s >> p;
    f[r][s][p] = 1;
    for (int i = r;i >= 0;i--)
        for (int j = s;j >= 0;j--)
            for (int k = p;k >= 0;k--) {
                double tmp = 1.0 * (i * k + i * j + j * k);
                if (i && k) f[i - 1][j][k] += f[i][j][k] * i * k / tmp;
                if (i && j) f[i][j - 1][k] += f[i][j][k] * i * j / tmp;
                if (j && k) f[i][j][k - 1] += f[i][j][k] * j * k / tmp;
            }
    double ans[3] = { 0.0,0.0,0.0 };
    for (int i = 1;i <= r;i++) {
        ans[0] += f[i][0][0];
    }
    for (int i = 1;i <= s;i++) {
        ans[1] += f[0][i][0];
    }
    for (int i = 1;i <= p;i++) {
        ans[2] += f[0][0][i];
    }


    printf("%.12lf %.12lf %.12lf", ans[0], ans[1], ans[2]);
    return 0;
}