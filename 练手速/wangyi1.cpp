#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int n;
int cnt1, cnt2;

int main() {
    freopen("data.in", "r", stdin);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        if (a[i] > 0) cnt1++; else cnt2++;
    }
    sort(a + 1, a + 1 + n);

    if (cnt1 == 0) {
        for (int i = n;i >= 1;i--) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else if (cnt2 == 0) {

        for (int i = 1;i <= n;i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else {
        if (cnt1 < cnt2) {
            //cout << " hre" << endl;
            int l = n - 2 * cnt1 + 1, r = n;
            for (int i = 1;i <= cnt1;i++) {
                printf("%d %d ", a[r], a[l]);
                r--, l++;
            }
            for (int i = n - 2 * cnt1;i > 0;i--) {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
        else if (cnt1 == cnt2) {
            for (int i = 1;i <= cnt1;i++) {
                printf("%d %d ", a[i], a[n + 1 - i]);
            }
            printf("\n");
        }
        else {
            for (int i = 1;i <= cnt1;i++) {
                printf("%d %d ", a[i], a[cnt2 * 2 + 1 - i]);
            }
            for (int i = cnt2 * 2 + 1;i <= n;i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
