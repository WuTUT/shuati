#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
vector<int> v[maxn];

int dfs(int root, int fa) {
    int ret = 0;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (to == fa) continue;

        ret ^= 1 + dfs(to, root);
    }
    return ret;

}
int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1, xi, yi;i < n;i++) {
        scanf("%d %d", &xi, &yi);
        v[xi].push_back(yi);
        v[yi].push_back(xi);
    }
    if (dfs(1, 0) != 0) {
        printf("Alice\n");
    }
    else {
        printf("Bob\n");
    }
    return 0;
}