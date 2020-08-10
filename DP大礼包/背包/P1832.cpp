#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 1005;
typedef long long ll;
ll f[maxn];
int a[maxn];
int cnt;
bool isprime(int x) {
    for (int i = 2;i <= floor(sqrt(x) + 0.5);i++) {
        if (x % i == 0) {

            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int i = 2;i <= n;i++) {
        if (isprime(i)) {
            a[cnt++] = i;
        }
    }
    f[0] = 1;
    for (int i = 0;i < cnt;i++) {
        for (int j = a[i];j <= n;j++) {
            f[j] += f[j - a[i]];
        }
    }
    printf("%lld", f[n]);
    return 0;
}