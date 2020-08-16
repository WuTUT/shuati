#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int f[2][3][3];
//int f[maxn][3][3];
int a[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    if (n == 1 || n == 2) {
        printf("0\n");
        return 0;
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            //f[0][i][j] = 0;
            //f[1][i][j] = (j != 1);
            f[2 & 1][i][j] = (i != 1) + (j != 1);
            //f[2][i][j] = (i != 1) + (j != 1);
        }
    }
    for (int i = 2;i < n;i++) {
        int p = i & 1;
        for (int t1 = -1;t1 < 2;t1++) {
            for (int t2 = -1;t2 < 2;t2++) {
                f[p ^ 1][t2 + 1][t1 + 1] = 0x3f3f3f3f;
                for (int t3 = -1;t3 < 2;t3++) {
                    if (a[i + 1] + t1 - (a[i] + t2) == a[i] + t2 - (a[i - 1] + t3)) {
                        f[p ^ 1][t2 + 1][t1 + 1] = f[p][t3 + 1][t2 + 1] + (t1 != 0);
                        //f[i + 1][t2 + 1][t1 + 1] = min(f[i + 1][t2 + 1][t1 + 1], f[i][t3 + 1][t2 + 1] + (t1 != 0));
                    }



                }
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            ans = min(ans, f[n & 1][i][j]);
            //ans = min(ans, f[n][i][j]);
        }

    }
    if (ans == 0x3f3f3f3f)
        ans = -1;
    printf("%d\n", ans);
}