#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 32770;
int f[maxn];
int main() {
    int up = floor(sqrt(32768) + 0.5);
    for (int i = 1;i <= up;i++) {
        int sum = i * i;
        f[sum] += 1;
        for (int j = i;j <= up;j++) {
            int sum1 = sum + j * j;
            if (sum1 >= 32768) break;
            f[sum1] += 1;
            for (int k = j;k <= up;k++) {
                int sum2 = sum1 + k * k;
                if (sum2 >= 32768) break;
                f[sum2] += 1;
                for (int l = k;l <= up;l++) {
                    int sum3 = sum2 + l * l;
                    if (sum3 >= 32768) break;
                    f[sum3] += 1;
                }
            }

        }
    }
    int T;
    int n;
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", f[n]);
    }
    return 0;
}
