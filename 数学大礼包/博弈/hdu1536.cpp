#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
int acnt;
const int maxn = 10005;
int sg[maxn];
bool vis[205];
void getsg() {
    sg[0] = 0;
    for (int i = 1;i < maxn;i++) {
        memset(vis, 0, sizeof vis);
        for (int j = 0;j < acnt;j++) {
            if (i - a[j] >= 0) {
                vis[sg[i - a[j]]] = 1;
            }

        }
        for (int j = 0;j < 205;j++) {
            if (vis[j] == 0) {
                sg[i] = j;
                break;
            }
        }
    }
}
int main() {
    freopen("data.in", "r", stdin);
    int k;
    while (scanf("%d", &k) && k) {
        acnt = 0;
        for (int i = 0;i < k;i++) {
            scanf("%d", &a[acnt]);
            acnt++;
        }

        //memset(sg, 0, sizeof sg);
        getsg();
        int m;
        scanf("%d", &m);
        for (int i = 0;i < m;i++) {
            int ans = 0;
            int l;
            scanf("%d", &l);
            for (int j = 0, hi;j < l;j++) {
                scanf("%d", &hi);
                ans ^= sg[hi];
            }
            if (ans != 0)
                printf("W");
            else
                printf("L");
        }
        printf("\n");
    }

    return 0;
}