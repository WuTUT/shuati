#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 17;
int f[maxn];
int sg[1005];

void init() {
    f[1] = 1;
    f[2] = 2;
    for (int i = 3;i < maxn;i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

}
int a[21];

void getsg() {
    sg[0] = 0;
    for (int i = 1;i <= 1000;i++) {
        memset(a, 0, sizeof a);
        for (int j = 1;f[j] <= i;j++) {
            a[sg[i - f[j]]] = 1;
        }
        int t = 0;
        for (int j = 0;j <= 20;j++) {
            if (a[j] == 0) {
                t = j;
                break;
            }
        }
        sg[i] = t;
    }

}
int main() {
    int m, n, p;
    init();
    getsg();
    while (scanf("%d %d %d", &m, &n, &p) && (m || n || p)) {
        int ans = 0 ^ sg[m] ^ sg[n] ^ sg[p];
        if (ans != 0) {
            printf("Fibo\n");
        }
        else {
            printf("Nacci\n");
        }
    }
    return 0;
}