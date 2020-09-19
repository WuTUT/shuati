#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
const int mod = 998244353;
int id, n, m;
double f[maxn][maxn];
vector<int> v[maxn];
int main() {
    freopen("data.in", "r", stdin);
    cin >> id >> n >> m;
    for (int i = 1, xi, yi;i <= m;i++) {
        scanf("%d %d", &xi, &yi);
        v[xi].push_back(yi);

    }

    if (id == 1) {
        printf("%d\n", 2 * n % mod);
    }
    return 0;
}