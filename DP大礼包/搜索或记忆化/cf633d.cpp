#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;
const int maxn = 1005;

int a[maxn];
int n;
int ans;
int f[maxn];
//map<int, int> ma;
unordered_map<int, int> ma;
int main() {
    freopen("data.in", "r", stdin);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        ma[a[i]]++;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (j != i) {
                if (a[i] == 0 && a[j] == 0) {
                    ans = max(ans, ma[0]);
                    continue;
                }
                int now = 2;
                int f1 = a[i], f2 = a[j];
                f[1] = f1, f[2] = f2;
                ma[a[i]]--, ma[a[j]]--;
                while (ma[f1 + f2] > 0) {
                    int tmp = f1;f1 = f2, f2 = tmp + f1;
                    ma[f2]--;
                    now++;
                    f[now] = f2;
                }
                ans = max(ans, now);
                for (int k = 1;k <= now;k++) {
                    ma[f[k]]++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}