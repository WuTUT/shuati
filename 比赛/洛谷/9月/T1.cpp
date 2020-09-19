#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 1e7 + 10;
char s[maxn];
int cnt[26];
int main() {
    freopen("data.in", "r", stdin);
    scanf("%s", s);
    for (int i = 0;s[i];i++) {
        cnt[s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0;i < 26;i++) {
        ans = max(ans, cnt[i]);
    }
    printf("%d\n", ans);
    return 0;
}