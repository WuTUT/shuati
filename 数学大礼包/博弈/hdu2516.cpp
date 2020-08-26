#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll a[80];
bool isfib(int n) {
    if (n == 1) return true;
    ll f1 = 1, f2 = 2, tmp;
    while (f2 <= n) {
        if (f2 == n) {
            return true;
        }
        tmp = f1, f1 = f2, f2 = tmp + f2;
    }
    return false;
}
int main() {
    int n;
    //freopen("data.in", "r", stdin);

    while (scanf("%d", &n) && n) {
        bool ans = isfib(n);
        if (!ans) {
            printf("First win\n");
        }
        else {
            printf("Second win\n");
        }
    }
    return 0;
}