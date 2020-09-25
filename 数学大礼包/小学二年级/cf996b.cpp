#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;

    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);

        a[i] = (a[i] - i + n) / n;
    }

    int midn = 1e9 + 10;
    int id = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] < midn) {
            midn = a[i];
            id = i;
        }
    }
    cout << id << endl;
    return 0;
}