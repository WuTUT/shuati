#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a;
int main() {
    // freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0;i < n;i++) {
        scanf("%d", &a);
        ans ^= a;
    }


    printf("%d", ans);
    return 0;
}