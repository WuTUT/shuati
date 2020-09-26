#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
struct node
{
    int ti, di;
}no[maxn];
typedef long long ll;
ll ans[maxn];
int n, b;
queue<int> q;
int main() {
    freopen("data.in", "r", stdin);
    cin >> n >> b;
    b++;
    ll now = 0;

    for (int i = 1;i <= n;i++) {
        scanf("%d %d", &no[i].ti, &no[i].di);
    }
    q.push(1);
    ans[1] = now = no[1].di + no[1].ti;
    for (int i = 2;i <= n;i++) {

        if (no[i].ti < now) {
            if (q.size() > b) {
                ans[i] = -1;
            }
            else
            {
                q.push(i);

            }
        }


    }
    for (int i = 1;i <= n;i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}