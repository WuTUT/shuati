#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 3005;
int sg[maxn];
int vis[maxn];
void init(int n) {
    sg[0] = 0;
    sg[1] = 1;sg[2] = 2;
    for (int i = 3;i <= n;i++) {
        memset(vis, 0, sizeof vis);
        for (int j = 0;j < i;j++) {
            vis[sg[j]] = 1;
        }
        for (int k1 = 1;k1 < i;k1++) {
            for (int k2 = 1;k2 < i - k1;k2++) {
                int k3 = i - k1 - k2;
                vis[sg[k1] ^ sg[k2] ^ sg[k3]] = 1;

            }
        }
        for (int j = 0;j < maxn;j++) {
            if (vis[j] == 0) {
                sg[i] = j;
                break;
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        printf("%d: %d\n", i, sg[i]);
    }
}
int main() {
    freopen("data.in", "r", stdin);
    //init(33);
    int T;
    cin >> T;
    while (T--) {
        int N;
        scanf("%d", &N);
        int ans = 0;
        for (int i = 1, hi;i <= N;i++) {
            scanf("%d", &hi);

            if (hi % 8 == 7) {
                ans ^= hi + 1;
            }
            else if (hi % 8 == 0) {
                ans ^= hi - 1;
            }
            else {
                ans ^= hi;
            }

        }
        if (ans == 0)
            printf("Second player wins.\n");
        else
            printf("First player wins.\n");
    }
    return 0;
}