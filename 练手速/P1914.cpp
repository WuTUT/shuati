#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 55;
char s[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d %s", &n, s);
    for (int i = 0;s[i];i++) {
        s[i] = (s[i] - 'a' + n) % 26 + 'a';
    }
    printf("%s\n", s);
    return 0;
}