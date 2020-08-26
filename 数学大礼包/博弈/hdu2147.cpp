#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n, m;
    //freopen("data.in", "r", stdin);

    while (scanf("%d %d", &n, &m) && (m || n)) {
        int ans = 0;
        if (m % 2 == 0) {
            ans = 1;
        }
        else {
            if (n % 2 == 0) {
                ans = 1;
            }
        }
        if (ans == 1) {
            printf("Wonderful!\n");
        }
        else {
            printf("What a pity!\n");
        }
    }
    return 0;
}