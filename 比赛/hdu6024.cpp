#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 3005;
int n;

typedef long long ll;
const ll INF = 0x7f7f7f7f7f7f7f7f;
ll f[maxn][2];
struct node {
    ll a, c;
    bool operator < (const node& rhs) const {
        return a < rhs.a;
    }
}node[maxn];
ll sum[maxn];
void init() {
    sum[0] = 0;
    memset(f, 0x7f, sizeof f);

}
int main() {
    freopen("data.in", "r", stdin);

    while (scanf("%d", &n) != EOF) {
        init();
        for (int i = 1;i <= n;i++) {
            scanf("%lld %lld", &(node[i].a), &(node[i].c));
        }
        sort(node + 1, node + n + 1);
        for (int i = 1;i <= n;i++)
            sum[i] = sum[i - 1] + node[i].a;
        f[1][1] = node[1].c;
        for (int i = 2;i <= n;i++) {
            for (int j = 1;j < i;j++) {
                f[i][0] = min(f[i][0], f[j][1] + sum[i] - sum[j] - (i - j) * node[j].a);
            }
            f[i][1] = min(f[i - 1][0], f[i - 1][1]) + node[i].c;
        }
        printf("%lld\n", min(f[n][0], f[n][1]));
    }
    return 0;
}