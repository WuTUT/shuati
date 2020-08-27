#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 3005;
int sg[maxn];
int vis[maxn];
// void init(int n) {
//     sg[0] = 0;
//     sg[1] = 1;
//     for (int i = 2;i <= n;i++) {
//         memset(vis, 0, sizeof vis);
//         for (int j = 0;j < i;j++) {
//             vis[sg[j]] = 1;
//         }
//         for (int k1 = 1;k1 < i;k1++) {
//             int k2 = i - k1;
//             vis[sg[k1] ^ sg[k2]] = 1;
//         }
//         for (int j = 0;j < maxn;j++) {
//             if (vis[j] == 0) {
//                 sg[i] = j;
//                 break;
//             }
//         }
//     }
//     for (int i = 1;i <= n;i++) {
//         printf("%d: %d\n", i, sg[i]);
//     }
// }
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
            if (hi % 4 == 0) {
                ans ^= hi - 1;
            }
            else if (hi % 4 == 3) {
                ans ^= hi + 1;
            }
            else ans ^= hi;

        }
        if (ans == 0)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
    return 0;
}