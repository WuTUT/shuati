#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 60005;
int a[7];
int f[maxn], sum[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int T = 0;
    while (1) {
        T++;
        int tot = 0;
        for (int i = 1;i <= 6;i++) {
            scanf("%d", &a[i]);
            tot += i * a[i];
        }
        if (tot == 0) {
            break;
        }
        else {
            if (T != 1) {
                printf("\n");
            }
        }
        if (tot % 2 != 0) {
            printf("Collection #%d:\nCan't be divided.\n", T);
            continue;
        }
        tot /= 2;
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1;i <= 6;i++) {
            memset(sum, 0, sizeof sum);
            for (int j = i;j <= tot;j++) {
                if (!f[j] && f[j - i] && sum[j - i] < a[i]) {
                    f[j] = 1, sum[j] = sum[j - i] + 1;
                }
            }
        }
        if (f[tot] == 1) {
            printf("Collection #%d:\nCan be divided.\n", T);
        }
        else {
            printf("Collection #%d:\nCan't be divided.\n", T);
        }
    }
    return 0;
}