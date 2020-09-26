#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;

struct card {
    int a;
    int id;
    bool operator< (const card& rhs) const {
        return a < rhs.a;
    }
}ca[maxn];
int n;
int main() {
    freopen("data.in", "r", stdin);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &ca[i].a);
        ca[i].id = i;
    }
    sort(ca + 1, ca + 1 + n);

    for (int i = 1;i <= n / 2;i++) {
        printf("%d %d\n", ca[i].id, ca[n - i + 1].id);
    }
    return 0;
}