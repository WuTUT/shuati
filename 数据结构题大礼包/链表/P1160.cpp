#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <list>
using namespace std;
const int maxn = 1e5 + 5;
int vis[maxn];
list<int>::iterator iters[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    list<int> l;
    l.push_back(1);
    iters[1] = l.begin();
    int p, k;
    for (int i = 2;i <= n;i++) {
        scanf("%d %d", &k, &p);
        if (p == 0) {
            iters[i] = l.insert(iters[k], i);
        }
        else {
            iters[i] = l.insert(next(iters[k]), i);//++it是智障行为

        }

    }
    int m;
    cin >> m;
    int x;
    for (int i = 1;i <= m;i++) {
        scanf("%d", &x);
        if (vis[x] == 0) {
            vis[x] = 1;
            l.erase(iters[x]);
        }
    }
    bool fir = true;
    for (auto it = l.begin();it != l.end();it++) {
        if (fir) {
            cout << *it;fir = false;
        }
        else cout << " " << *it;
    }
    cout << endl;
    // for (auto it : l) {
    //     if (fir) { cout << it; fir = false; }
    //     else cout << " " << it;
    // }
    // cout << endl;
    return 0;
}