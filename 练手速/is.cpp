#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 28;
struct node {
    int a, b;
    bool operator < (const node& rhs) const {
        return a < rhs.a&& b < rhs.b;

    }
}no[maxn];
int has[maxn];
inline int id(char ch) {
    return ch - 'A';
}
int main() {
    freopen("data.in", "r", stdin);
    int n;
    char ch;
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf(" %c", &ch);
        no[id(ch)].a = i;
        has[id(ch)] = 1;
    }
    for (int i = 1;i <= n;i++) {
        scanf(" %c", &ch);
        no[id(ch)].b = i;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0;i < 26;i++) {
        if (i == ('X' - 'A') || !has[i]) continue;
        if (no[i] < no[id('X')]) {
            cnt1++;
        }
        if (no[id('X')] < no[i]) {
            cnt2++;
        }
    }
    printf("%d %d\n", cnt1 + 1, n - cnt2);
    return 0;
}