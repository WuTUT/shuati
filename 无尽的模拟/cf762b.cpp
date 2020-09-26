#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 3e5 + 5;
int a, b, c;
int x[maxn], y[maxn];
int n;
int cntx, cnty;
char ch[10];
int main() {
    freopen("data.in", "r", stdin);
    cin >> a >> b >> c;
    cin >> n;
    for (int i = 0, mo;i < n;i++) {
        scanf("%d %s", &mo, ch);
        if (ch[0] == 'U') {
            x[cntx++] = mo;
        }
        else {
            y[cnty++] = mo;
        }
    }
    sort(x, cntx + x);
    sort(y, cnty + y);
    int ax = min(a, cntx);
    int ay = min(b, cnty);
    int az = min(max(cntx - ax, 0) + max(cnty - ay, 0), c);
    int l1, l2;
    long long tot = 0;
    for (l1 = 0;l1 < ax; l1++) {
        tot += x[l1];
    }
    for (l2 = 0;l2 < ay; l2++) {
        tot += y[l2];
    }


    if (az > 0) {
        int sa = 0;
        while (l1 < cntx || l2 < cnty) {
            if (sa == az) { break; }
            if (l2 >= cnty || (l1 < cntx && x[l1] < y[l2])) {
                tot += x[l1];
                l1++;
            }
            else {

                tot += y[l2];
                l2++;
            }
            sa++;
        }
    }

    printf("%d %lld\n", ax + ay + az, tot);
}