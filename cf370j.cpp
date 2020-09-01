#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct Bottle {
    int a, b;
    bool operator<(const Bottle& rhs) const {
        if (b == rhs.b) {
            return a > rhs.a;
        }
        return b > rhs.b;
    }
}bot[maxn];
int main() {
    int n;
    cin >> n;
    int suma = 0;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &(bot[i].a));
        suma += bot[i].a;
    }
    for (int i = 1;i <= n;i++) {
        scanf("%d", &(bot[i].b));
    }
    sort(bot + 1, bot + n + 1);
    int cnt = 1;
    int sumb = 0;
    for (int i = 1;i <= n;i++) {
        sumb += bot[i].b;
        if (sumb >= suma) {
            cnt = i;
            break;
        }
    }

}