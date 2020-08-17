#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> v[maxn], w[maxn];
typedef long long ll;
ll maxwei;
ll allwei;
void dfs(int root, int fa, int dis) {
    if (v[root].size() == 1 && v[root][0] == fa) {
        maxwei = max(maxwei, (ll)dis);
    }
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;
        allwei += w[root][i];
        dfs(to, root, dis + w[root][i]);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1, xi, yi, wi;i < n;i++) {
        scanf("%d %d %d", &xi, &yi, &wi);
        v[xi].push_back(yi);
        v[yi].push_back(xi);
        w[xi].push_back(wi);
        w[yi].push_back(wi);
    }
    dfs(1, 0, 0);
    // printf("%d\n", allwei);
    // printf("%d\n", maxwei);
    cout << allwei * 2 - maxwei;
}
