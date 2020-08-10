#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 3e6 + 5;
int n, f[maxn];
vector<int> a[maxn];
int main() {
    freopen("data.in", "r", stdin);
    cin >> n;
    int maxw = 0;
    for (int i = 1, xi, yi;i <= n;i++) {
        scanf("%d %d", &xi, &yi);
        a[xi].push_back(yi);
        maxw = max(maxw, yi);
    }
    f[0] = 0;
    for (int j = 0;j < a[0].size();j++) {
        f[a[0][j]] = max(f[a[0][j]], a[0][j] + 1);
    }
    for (int i = 1;i <= maxw;i++) {
        f[i] = max(f[i], f[i - 1]);
        for (int j = 0;j < a[i].size();j++) {
            f[a[i][j]] = max(f[a[i][j]], f[i - 1] + a[i][j] - i + 1);
        }

    }
    // for (int i = 0;i <= maxw;i++) {
    //     printf("%d ", f[i]);
    // }
    // printf("\n");
    printf("%d\n", f[maxw]);
}