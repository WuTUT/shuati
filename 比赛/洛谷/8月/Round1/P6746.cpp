#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
long long c, d;
int a, b;
int main() {
    freopen("data.in", "r", stdin);
    cin >> a >> b >> c >> d;

    if (a == 0 && b == 0) {
        printf("%d\n", 0);
    }
    else if (a == 0 || b == 0) {

        printf("%lld\n", d);
    }
    else {
        // if (a < b) {
        //     std::swap(a, b);
        // }
        if (a == b) {
            printf("%lld\n", min(c, d + d));
        }
        else {
            printf("%lld\n", min(d + d, c + d));
        }
    }
    return 0;
}