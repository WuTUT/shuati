#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm> 
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
int a[20];
const int maxh = 2e4 + 5;
int cnt;
ll f[14][39][26][15][15];
ll h[maxh], c[maxh];
ll n;

int k;
int fek[10][4] = {
    {0,0,0,0},//0
    {0,0,0,0},//1
    {1,0,0,0},//2
    {0,1,0,0},//3
    {2,0,0,0},//4
    {0,0,1,0},//5
    {1,1,0,0},//6
    {0,0,0,1},//7
    {3,0,0,0},//8
    {0,2,0,0}//9

};
struct node {
    int x, y;
    node(int x, int y) :x(x), y(y) {}
    bool operator < (const node& rhs) const {
        return c[x] * c[y] < c[rhs.x] * c[rhs.y];
    }
};
priority_queue<node> pq;
ll pred[4] = { 2,3,5,7 };
void pre(int ind, ll tmp) {
    if (tmp > n) return;
    h[++cnt] = tmp;
    for (int i = ind;i < 4;i++) {
        pre(i, tmp * pred[i]);
    }
    return;
}
ll dfs(int lead, int eq, int pos, int n2, int n3, int n5, int n7) {
    if (n2 < 0 || n3 < 0 || n5 < 0 || n7 < 0) return 0;
    if (pos == 0) {
        if (n2 == 0 && n3 == 0 && n5 == 0 && n7 == 0 && !lead) {
            return 1;
        }
        return 0;
    }
    if (!eq && !lead && ~f[pos][n2][n3][n5][n7]) return f[pos][n2][n3][n5][n7];
    int ed = eq ? a[pos] : 9;
    ll ret = 0;
    for (int i = 0;i <= ed;i++) {
        if (!lead && i == 0) continue; //中间状态出现了0；
        ret += dfs(lead && i == 0, eq && i == ed, pos - 1, n2 - fek[i][0], n3 - fek[i][1], n5 - fek[i][2], n7 - fek[i][3]);
    }
    if (!eq && !lead)  f[pos][n2][n3][n5][n7] = ret;
    return ret;
}
ll solve(ll x) {
    ll tx = x;
    int n2 = 0, n3 = 0, n5 = 0, n7 = 0;
    while (tx % 2 == 0) {
        tx /= 2, n2++;
    }
    while (tx % 3 == 0) {
        tx /= 3, n3++;
    }
    while (tx % 5 == 0) {
        tx /= 5, n5++;
    }
    while (tx % 7 == 0) {
        tx /= 7, n7++;
    }
    return dfs(true, true, a[0], n2, n3, n5, n7);
}

int main() {
    scanf("%lld %d", &n, &k);
    pre(0, 1);


    a[0] = 0;
    ll x = n;
    while (x) {
        a[++a[0]] = x % 10;
        x /= 10;
    }

    memset(f, -1, sizeof f);


    for (int i = 1;i <= cnt;i++) {


        c[i] = solve(h[i]);
    }

    // for (int i = 1;i <= cnt;++i)
    //     printf("%lld ", c[i]);
    // printf("\n");
    sort(c + 1, c + cnt + 1, greater<ll>());
    k = min(k, cnt * cnt);
    for (int i = 1;i <= cnt;i++) {
        pq.push(node(i, 1));
    }
    ll ans = 0;
    for (int i = 1;i <= k;i++) {
        node cur = pq.top();
        pq.pop();
        ans = (ans + c[cur.x] * c[cur.y]) % mod;
        if (cur.y == cnt)
            continue;
        pq.push(node(cur.x, cur.y + 1));

    }
    //TLE why???
    // for (int i = 1;i <= cnt;i++) {
    //     for (int j = 1;j <= cnt;j++) {
    //         pq.push(node(i, j));
    //     }
    // }
    // for (int i = 0;i < k;i++) {
    //     ans = (ans + c[pq.top().x] * c[pq.top().y] % mod) % mod;
    //     pq.pop();
    // }
    printf("%lld\n", ans);

    return 0;
}