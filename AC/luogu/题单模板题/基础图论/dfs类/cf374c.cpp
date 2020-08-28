#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 1005;
char s[maxn][maxn];
int f[maxn][maxn];
int n, m;
bool inq[maxn][maxn];
char dima[5] = "DIMA";
inline int id(char c) {
    if (c == 'D') return 1;
    if (c == 'I') return 2;
    if (c == 'M') return 3;
    if (c == 'A') return 4;
}
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool huan = false;
void dfs(int x, int y) {
    if (f[x][y]) return;
    inq[x][y] = true;
    f[x][y] = 1;
    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
            if (id(s[nx][ny]) - id(s[x][y]) == 1 || id(s[nx][ny]) - id(s[x][y]) == -3) {
                if (inq[nx][ny] == true) {
                    huan = true;
                    inq[x][y] = false;
                    return;
                }
                else {
                    dfs(nx, ny);
                }
                f[x][y] = max(f[x][y], f[nx][ny] + 1);

            }
        }
    }
    inq[x][y] = false;
}
int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        s[i][0] = ' ';
        scanf("%s", s[i] + 1);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (s[i][j] == 'D') {
                dfs(i, j);
                if (huan) {
                    cout << "Poor Inna!" << endl;
                    return 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            ans = max(f[i][j] / 4, ans);
        }
    }
    if (ans == 0)
        cout << "Poor Dima!" << endl;
    else cout << ans << endl;
    return 0;
}
//判环同时最长路 如何清理vis和利用f 很有说法