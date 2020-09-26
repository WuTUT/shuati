#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int n;
    freopen("data.in", "r", stdin);
    cin >> n;

    for (int i = 0;i < 1000;i++) {
        if (i * 1234567 > n) {
            break;
        }
        else {
            int nn = n - i * 1234567;
            int bm = nn / 123456;
            for (int j = 0;j <= bm;j++) {
                int nnn = nn - 123456 * j;
                if (nnn % 1234 == 0) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}