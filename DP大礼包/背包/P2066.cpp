#include<cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 16;
int a[maxn][maxn];
int f[maxn][maxn];
int pa[maxn][maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = m;j > 0;j--) {
            for (int k = 0;k <= j;k++) {
                if (f[i - 1][j - k] + a[i][k] >= f[i][j]) {//有等于
                    f[i][j] = f[i - 1][j - k] + a[i][k];
                    pa[i][j] = k;
                }
            }
        }
    }
    printf("%d\n", f[n][m]);
    vector<int> ans;
    for (int i = n;i >= 1;i--) {
        ans.push_back(pa[i][m]);
        m = m - pa[i][m];
    }
    for (int i = ans.size() - 1;i >= 0;i--) {
        printf("%d %d\n", n - i, ans[i]);
    }
    return 0;
}