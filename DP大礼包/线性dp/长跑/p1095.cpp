#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxt = 300005;
int f[maxt];
int main() {
    freopen("data.in", "r", stdin);
    int m, s, t;
    cin >> m >> s >> t;
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    int  ans = 0;
    bool flag = false;
    int mint;
    int nowm = m;
    for (int i = 1;i <= t;i++) {
        if (nowm >= 10) {
            f[i] = f[i - 1] + 60, nowm -= 10;
        }
        else {
            f[i] = f[i - 1];
            nowm += 4;
        }
    }
    for (int i = 1;i <= t;i++) {
        f[i] = max(f[i], f[i - 1] + 17);
        if (f[i] >= s) {
            printf("Yes\n");
            printf("%d\n", i);
            return 0;
        }
    }

    printf("No\n");
    printf("%d\n", f[t]);

    return 0;
}