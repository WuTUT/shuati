#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 100020;
vector<int> v[maxn];
int f[maxn][2];
int m[maxn][2];
const int mod = 10007;
void dfs(int root, int fa) {
    f[root][1] = 1;
    f[root][0] = 0;
    m[root][1] = m[root][0] = 1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        dfs(to, root);

        f[root][0] += f[to][1];
        m[root][0] = m[root][0] * m[to][1] % mod;
        if (f[to][1] < f[to][0]) {
            f[root][1] += f[to][1];
            m[root][1] = m[root][1] * m[to][1] % mod;
        }
        else if (f[to][0] < f[to][1]) {
            f[root][1] += f[to][0];
            m[root][1] = m[root][1] * m[to][0] % mod;
        }
        else {
            f[root][1] += f[to][1];
            m[root][1] = m[root][1] * (m[to][0] + m[to][1]) % mod;
        }
    }
}
void dfs2(int root, int fa) {

}
int main() {
    freopen("data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            v[i].clear();
        }
        int xi, yi;
        for (int i = 1;i <= n - 1;i++) {
            scanf("%d %d", &xi, &yi);
            v[xi].push_back(yi);
            v[yi].push_back(xi);
        }
        dfs(1, 0);
        if (f[1][0] < f[1][1]) {
            printf("%d %d\n", f[1][0], m[1][0]);
        }
        else if (f[1][1] < f[1][0]) {
            printf("%d %d\n", f[1][1], m[1][1]);
        }
        else {
            printf("%d %d\n", f[1][0], (m[1][0] + m[1][1]) % mod);
        }

    }
    return 0;
}