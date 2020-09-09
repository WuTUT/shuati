#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> v[maxn];
vector<int> ans;
bool ins[maxn];
int vis[maxn][2];
bool ok = false;
bool has = false;
void dfs(int now, int ji) {
    if (vis[now][ji]) return;
    if (has == false)
        ans.push_back(now);
    if (v[now].size() == 0 && ji) {
        has = true;
    }
    vis[now][ji] = 1;
    ins[now] = true;
    for (auto to : v[now]) {
        if (ins[to]) ok = true;
        if (!vis[to][ji ^ 1])
            dfs(to, ji ^ 1);

    }
    ins[now] = false;
    if (has == false) ans.pop_back();
    return;
}
void print() {

}
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1, mi;i <= n;i++) {
        scanf("%d", &mi);
        for (int j = 0, toi;j < mi;j++) {
            scanf("%d", &toi);
            v[i].push_back(toi);

        }
    }
    int s;
    scanf("%d", &s);
    dfs(s, 0);
    if (has) {
        printf("Win\n");
        for (int i = 0;i < ans.size();i++) {
            printf("%d ", ans[i]);
        }
    }
    else if (ok) {
        printf("Draw\n");
    }
    else {
        printf("Lose\n");
    }
    return 0;
}