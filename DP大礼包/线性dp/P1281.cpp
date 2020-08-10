#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 505;
int a[maxn];
int suma[maxn];
int f[maxn][maxn];
int main() {
    freopen("data.in", "r", stdin);
    int m, k;
    cin >> m >> k;
    for (int i = 1;i <= m;i++) {
        scanf("%d", &a[i]);
        suma[i] = suma[i - 1] + a[i];
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 1;i <= m;i++) {
        f[1][i] = suma[i];
    }

    for (int i = 2;i <= k;i++) {
        for (int j = 1;j <= m;j++) {
            for (int l = 2;l <= j;l++) {
                f[i][j] = min(f[i][j], max(f[i - 1][l - 1], suma[j] - suma[l - 1]));
            }
        }
    }
    //printf("%d\n", f[k][m]);
    int ans = f[k][m];
    int tmp = 0;
    vector<int> v;
    for (int i = m;i >= 1;i--) {
        if (tmp + a[i] > ans) {
            v.push_back(i);
            tmp = a[i];
        }
        else {
            tmp += a[i];
        }
    }
    printf("1 ");
    for (int i = v.size() - 1;i >= 0;i--) {
        printf("%d\n%d ", v[i], v[i] + 1);
    }
    printf("%d\n", m);
    return 0;
}