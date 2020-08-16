#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ha[1005];

int main() {
    freopen("data.in", "r", stdin);
    int x;
    int maxx = 0;
    while (scanf("%d,", &x) != EOF) {
        ha[x] = 1;
        maxx = max(maxx, x);
    }
    // printf("%d\n", maxx);
    int l = 1, r = 1;
    while (l <= maxx) {
        if (ha[l] == 1) {
            r = l;
            while (ha[r] != 0) {
                r++;
            }
            r -= 1;
            if (r == l) {
                if (l == maxx)
                    printf("%d", l);
                else
                    printf("%d,", l);
                l++;
            }
            else {

                if (r == maxx) {
                    printf("%d-%d", l, r);
                }
                else {
                    printf("%d-%d,", l, r);
                }
                l = r + 1;
            }
        }
        else {
            l++;
        }
    }
    return 0;
}