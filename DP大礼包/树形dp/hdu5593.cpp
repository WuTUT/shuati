#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 5e5 + 10;
int f[maxn][11], g[maxn][11];
int T;
int n;
int K;
vector<int> v[maxn];
void dfs(int root) {
    g[root][0] = 1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        dfs(to);
        for (int k = 1;k <= K;k++)
            g[root][k] += g[to][k - 1];
    }
}
void DFS(int root) {
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        f[to][0] = g[to][0];
        f[to][1] = g[root][0] + g[to][1];
        for (int k = 2;k <= K;k++) {
            f[to][k] = f[root][k - 1] - g[to][k - 2] + g[to][k];
        }
        DFS(to);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%d", &K);
        int A, B;
        scanf("%d %d", &A, &B);
        //memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        for (int i = 0;i <= n;i++) {
            v[i].clear();
        }
        for (int i = 2;i <= n;i++) {
            v[(1ll * A * i + B) % (i - 1) + 1].push_back(i);
        }
        dfs(1);
        // for (int i = 1;i <= n;i++) {
        //     printf("%d ", g[i][K]);
        // }
        // printf("\n");
        for (int i = 0;i <= K;i++) {
            f[1][i] = g[1][i];
        }
        DFS(1);
        // for (int i = 1;i <= n;i++) {
        //     printf("%d ", f[i][K]);
        // }
        // printf("\n");
        int ans = 0;

        for (int i = 1;i <= n;i++) {
            int tmp = 0;
            for (int k = 0;k <= K;k++) {
                tmp += f[i][k];
            }
            ans ^= tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}