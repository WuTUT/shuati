#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 105;
int a, b, m;
int main() {
    freopen("data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        int bt = 0;
        scanf("%d %d", &n, &m);
        int mh, ml;
        bool ok = true;
        int t, l, h;
        scanf("%d %d %d", &t, &l, &h);
        mh = m + t, ml = m - t;
        if (mh<l || ml>h) {
            ok = false;
        }
        else {
            ml = max(ml, l);
            mh = min(mh, h);
            bt = t;
        }
        for (int i = 2;i <= n;i++) {
            scanf("%d %d %d", &t, &l, &h);

            if (ok == false) continue;
            ml = ml - (t - bt), mh = mh + (t - bt);
            if (mh<l || ml>h) ok = false;
            ml = max(ml, l);
            mh = min(mh, h);
            bt = t;
        }
        (ok) ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}