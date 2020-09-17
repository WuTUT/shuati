#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
const int maxn = 3200, maxm = 63;
int f[maxm][maxn];
vector<int> v[maxn];
int val[maxm], wei[maxm];
void dfs(int root) {
    f[root][val[root]] = wei[root] * val[root];
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        dfs(to);
        for (int j = n;j >= val[root];j--) {
            for (int k = val[to];k <= j - val[root];k++) {
                f[root][j] = max(f[root][j], f[root][j - k] + f[to][k]);
            }
        }
    }

}
int main() {

    freopen("data.in", "r", stdin);
    cin >> n >> m;
    n /= 10;
    int q;
    for (int i = 1;i <= m;i++) {
        scanf("%d %d %d", &val[i], &wei[i], &q);
        val[i] /= 10;
        v[q].push_back(i);
    }
    dfs(0);
    int ans = 0;
    for (int i = 0;i <= n;i++) {
        ans = max(ans, f[0][i]);
    }
    printf("%d\n", ans * 10);
    return 0;
}

//P2014 对树形背包的枚举边界，确实有些难以想通