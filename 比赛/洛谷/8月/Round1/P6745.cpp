#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 555;
struct node {
    int a[maxn];
    int len;
    node() {
        len = 0;
        memset(a, 0, sizeof a);
    }
    node(ll x) {
        memset(a, 0, sizeof a);
        len = 0;
        while (x) {
            a[len++] = x % 10;
            x /= 10;
        }
    }
    void print() {
        for (int i = len - 1;i >= 0;i--) {
            printf("%d", a[i]);
        }
    }
};
node operator+(node& a, node& b) {
    node c;
    c.len = max(a.len, b.len);
    int x = 0;
    for (int i = 0;i < c.len;i++) {
        x = a.a[i] + b.a[i] + x;
        c.a[i] = x % 10;
        x /= 10;
    }
    if (x) {

        ++c.len;
        c.a[c.len - 1] = x;
    }
    //cout << c.len << endl;
    return c;
}
typedef long long ll;
ll x;
int k;
int main() {
    scanf("%d %lld", &k, &x);
    node a;
    a.len = k + 1;
    a.a[a.len - 1] = 1;
    // a.print();
    // cout << endl;
    node b(x);
    node c;
    c = a + b;
    c.print();
    cout << endl;
    return 0;
}