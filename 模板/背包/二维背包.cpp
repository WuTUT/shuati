#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 22;
int n, m, t;
int a[maxn];
int f[maxn][maxn];

int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> t >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = m;j >= 1;j--) {
            for (int k = t;k >= a[i];k--) {
                f[j][k] = max(f[j][k], f[j - 1][t] + 1);
                f[j][k] = max(f[j][k], f[j][k - a[i]] + 1);
            }
        }
    }
    printf("%d\n", f[m][t]);
    return 0;
}
//n个物品放到m个背包，每个背包最大容量T，且必须按顺序装入
//当前用j个背包，最后一个背包用了k
//f[i][j][k]=max  f[i-1][j][k]  f[i-1][j-1][T]+1  f[i-1][j][k-a[i]]+1 