#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1e3 + 10;
typedef long long ll;
int f[maxn][maxn];
ll g[maxn][maxn], h[maxn][maxn], r[maxn][maxn];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, a, b, c;
bool vis[maxn][maxn];
struct node {

    int x, y;
    ll dis;
    node(int x, int y, ll dis) :x(x), y(y), dis(dis) {

    }
    bool operator < (const node& b)const {
        return dis > b.dis;
    }
};

int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> m >> a >> b >> c;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            scanf("%d", &f[i][j]);
        }
    }
    memset(g, 0x7f, sizeof g);

    priority_queue<node, vector<node> > pq;
    pq.push(node(1, a, f[1][a]));
    g[1][a] = f[1][a];

    while (!pq.empty())
    {

        int x = pq.top().x;
        int y = pq.top().y;
        ll dis = pq.top().dis;
        pq.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
                if (g[nx][ny] > dis + f[nx][ny]) {
                    g[nx][ny] = dis + f[nx][ny];
                    pq.push(node(nx, ny, g[nx][ny]));
                }

            }
        }
    }
    printf("%lld\n", g[n][b]);
    printf("%lld\n", g[n][c]);

    memset(h, 0x7f, sizeof h);
    memset(vis, 0, sizeof vis);
    pq.push(node(n, b, f[n][b]));
    h[n][b] = f[n][b];
    while (!pq.empty())
    {

        int x = pq.top().x;
        int y = pq.top().y;
        ll dis = pq.top().dis;
        pq.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
                if (h[nx][ny] > dis + f[nx][ny]) {
                    h[nx][ny] = dis + f[nx][ny];
                    pq.push(node(nx, ny, h[nx][ny]));
                }

            }
        }
    }

    memset(r, 0x7f, sizeof r);
    memset(vis, 0, sizeof vis);
    pq.push(node(n, c, f[n][c]));
    r[n][c] = f[n][c];
    while (!pq.empty())
    {

        int x = pq.top().x;
        int y = pq.top().y;
        ll dis = pq.top().dis;
        pq.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
                if (r[nx][ny] > dis + f[nx][ny]) {
                    r[nx][ny] = dis + f[nx][ny];
                    pq.push(node(nx, ny, r[nx][ny]));
                }

            }
        }
    }
    ll ans = 1000000000000;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {

            ans = min(ans, g[i][j] + h[i][j] + r[i][j] - 2 * f[i][j]);
        }
    }

    printf("%lld\n", ans);
    return 0;
}