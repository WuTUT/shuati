#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 2005;
const int mod = 1e9 + 7;
int tao[maxn][maxn];
int cnt[maxn];
typedef long long ll;
ll f[maxn][maxn];
int main() {
    int n, K;
    cin >> n >> K;
    // for (int i = 1;i <= n;i++) {
    //     for (int j = 1;j <= floor(sqrt(i) + 0.5);j++) {
    //         if (i % j == 0) {
    //             tao[i][cnt[i]] = j;
    //             cnt[i]++;
    //             if (j * j != i) {
    //                 tao[i][cnt[i]] = i / j;
    //                 cnt[i]++;
    //             }
    //         }
    //     }
    // }



    for (int i = 1;i <= n;i++) {
        f[1][i] = 1;
    }
    // for (int i = 2;i <= K;i++) {
    //     for (int j = 2;j <= n;j++) {
    //         for (int k = 0;k < cnt[j];k++) {
    //             f[i][j] = (f[i][j] + f[i - 1][tao[j][k]]) % mod;
    //         }
    //     }
    // }
    for (int i = 2;i <= K;i++) {
        for (int j = 1;j <= n;j++) {
            for (int k = 1;k * j <= n;k++) {
                f[i][k * j] = (f[i][k * j] + f[i - 1][j]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        ans = (ans + f[K][i]) % mod;
    }
    printf("%d\n", ans);
    return 0;
}
//