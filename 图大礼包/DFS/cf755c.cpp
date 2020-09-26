#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1e4 + 5;
vector<int> v[maxn];
int n;
bool vis[maxn];
void dfs(int root) {
    vis[root] = 1;
    for (int i = 0;i < v[root].size();i++) {
        int to = v[root][i];
        if (!vis[to]) {
            dfs(to);
        }
    }
}
int cnt = 0;
int main() {
    freopen("data.in", "r", stdin);
    cin >> n;
    for (int i = 1, ai;i <= n;i++) {
        scanf("%d", &ai);
        v[i].push_back(ai);
        v[ai].push_back(i);
    }
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    printf("%d\n", cnt);
}
