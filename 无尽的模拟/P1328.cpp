#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 205;
int a[maxn], b[maxn];
int f[5][5] = { {0,-1,1,1,-1},{0,0,-1,1,-1},{0,0,0,-1,1},{0,0,0,0,1},{0,0,0,0,0} };
int main() {
    freopen("data.in", "r", stdin);
    for (int i = 0;i < 5;i++) {
        for (int j = 0;j < i;j++) {
            f[i][j] = -f[j][i];
        }
    }
    // for (int i = 0;i < 5;i++) {
    //     for (int j = 0;j < 5;j++) {
    //         printf("%3d ", f[i][j]);
    //     }
    //     printf("\n");
    // }
    int n, na, nb;
    cin >> n >> na >> nb;
    for (int i = 0;i < na;i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0;i < nb;i++) {
        scanf("%d", &b[i]);
    }
    int cnta = 0, cntb = 0;
    for (int i = 0;i < n;i++) {
        int ans = f[a[i % na]][b[i % nb]];
        //cout << "node " << i << " " << a[i % na] << " " << b[i % nb] << " " << ans << endl;
        if (ans == 1) {
            cnta++;
        }
        else if (ans == -1) {
            cntb++;
        }
    }
    printf("%d %d\n", cnta, cntb);
    return 0;
}
