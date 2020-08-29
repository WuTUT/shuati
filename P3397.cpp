#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1005;
int a[maxn], b[maxn], da[maxn], db[maxn];
int main() {
    int n, m, x1, y1, x2, y2;
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= m;i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        da[x1]++, da[x2 + 1]--;
        db[y1]++, db[y2 + 1]--;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {

        }
    }

}