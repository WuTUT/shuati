#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> v[maxn];
int lf[maxn];
int inq[maxn];
int islf[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);

        for (int i = 0;i <= n;i++) {
            v[i].clear();
            lf[i] = 0;
            islf[i] = 0;
            inq[i] = 0;
        }
        int x, y;
        int ans = 0;
        for (int i = 1;i < n;i++) {
            scanf("%d %d", &x, &y);
            v[x].push_back(y), v[y].push_back(x);
        }
        if (k == 1) {
            printf("%d\n", n - 1);
            continue;
        }
        for (int i = 1;i <= n;i++) {
            islf[i] = v[i].size();
            if (v[i].size() == 1) {
                lf[v[i][0]]++;
            }
        }
        queue<int> q;
        for (int i = 1;i <= n;i++) {
            if (lf[i] >= k) {
                q.push(i);
                inq[i] = 1;
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int m = lf[x] / k;
            ans += m;
            islf[x] -= m * k;
            lf[x] -= m * k;
            inq[x] = 0;
            if (islf[x] == 1) {
                for (int i = 0;i < v[x].size();i++) {
                    int to = v[x][i];
                    if (islf[to] != 1) {
                        lf[to]++;
                        if (lf[to] >= k && !inq[to]) {
                            q.push(to);
                            inq[to] = 1;
                        }
                    }

                }
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}