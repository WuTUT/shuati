#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> v[maxn], w[maxn];
int n, m;
int in[maxn], tmp[maxn];
double f[maxn];
int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    int xi, yi, wi;
    for (int i = 1;i <= m;i++) {
        scanf("%d %d %d", &xi, &yi, &wi);
        v[yi].push_back(xi);
        w[yi].push_back(wi);
        in[xi]++;

    }

    queue<int> q;
    for (int i = 1;i <= n;i++) {
        f[i] = 0.0;
        tmp[i] = in[i];
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0;i < v[x].size();i++) {
            int to = v[x][i];
            f[to] += 1.0 / in[to] * (f[x] + w[x][i]);
            tmp[to]--;
            if (tmp[to] == 0) {
                q.push(to);
            }
        }
    }
    printf("%.2lf\n", f[1]);
    return 0;
}
