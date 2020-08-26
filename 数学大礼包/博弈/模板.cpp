#include<iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 10005;
int main() {
    freopen("data.in", "r", stdin);
    int n, T;
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        int ans = 0, a;
        for (int i = 1;i <= n;i++) {
            scanf("%d", &a);
            ans ^= a;
        }
        if (ans != 0) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
//p2917