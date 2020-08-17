#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
map<int, int> ha;
int c[maxn];
int b[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1, ai;i <= n;i++) {
        scanf("%d", &ai);
        ha[ai]++;
    }
    int m;
    scanf("%d", &m);
    int maxai = 0;
    int ans = 1;
    for (int i = 1;i <= m;i++) {
        scanf("%d", &b[i]);
        if (ha[b[i]] > maxai) {
            maxai = ha[b[i]];
            ans = i;
        }
    }
    //printf("%d\n", maxai);
    for (int i = 1;i <= m;i++) {
        scanf("%d", &c[i]);
    }
    int maxci = -1;

    for (int i = 1;i <= m;i++) {
        if (ha[b[i]] == maxai) {
            if (ha[c[i]] >= maxci) {
                maxci = ha[c[i]];
                ans = i;
            }
        }
    }
    printf("%d", ans);
    return 0;
}