#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 6005;
vector<int> v[maxn];
int n;

template<typename T>
inline T mymax(T x, T y, T z) {
    return max(max(x, y), z);
}
int f[maxn][2];
int in[maxn];
void dfs(int root) {
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        dfs(to);
        f[root][0] += mymax(f[to][0], f[to][1], 0);
        f[root][1] += max(f[to][0], 0);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &f[i][1]);
        f[i][1] = max(0, f[i][1]);
    }

    for (int i = 0, xi, yi;i < n - 1;i++) {
        scanf("%d %d", &xi, &yi);
        v[yi].push_back(xi);
        in[xi]++;
    }
    for (int i = 1;i <= n;i++) {
        if (!in[i]) {
            dfs(i);
            printf("%d\n", max(f[i][0], f[i][1]));
            break;
        }
    }
    return 0;
}