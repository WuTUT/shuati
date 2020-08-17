#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 100005;
typedef long long ll;
int n;
int a[maxn];
ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int main() {
    freopen("data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
        }
    }
    return 0;
}