#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 3005;
int sg[maxn];
int vis[maxn];
void init(int n) {
    sg[0] = 0;
    sg[1] = 0;sg[2] = 1;
    for (int i = 3;i <= n;i++) {
        memset(vis, 0, sizeof vis);
        for (int j = 0;j < i - 1;j++) {
            vis[sg[j] ^ sg[i - j - 2]] = 1;
        }
        for (int j = 0;j < maxn;j++) {
            if (vis[j] == 0) {
                sg[i] = j;
                break;
            }
        }
    }
    //  for (int i = 1;i <= n;i++) {
     //     printf("%5d: %5d \n", i, sg[i]);
          //if (i % 10 == 0) { printf("\n"); }
     // }
}
int main() {
    freopen("data.in", "r", stdin);
    init(200);
    int T;
    cin >> T;
    while (T--) {
        int N;
        scanf("%d", &N);
        int ans = 0;
        for (int i = 1, hi;i <= N;i++) {
            scanf("%d", &hi);
            if (hi < 200)
                ans ^= sg[hi];
            else {
                ans ^= sg[86 + ((hi - 86) % 34)];
            }
        }
        if (ans == 0)
            printf("Dave\n");
        else
            printf("Carol\n");
    }
    return 0;
}