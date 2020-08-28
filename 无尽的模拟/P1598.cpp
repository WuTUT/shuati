#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int f[26];
string s[4];
char ans[500][26];
int ind[500];
int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    for (int i = 0;i < 4;i++) {
        getline(cin, s[i]);
    }
    int maxn = 0;
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < s[i].length();j++) {
            if (s[i][j] <= 'Z' && s[i][j] >= 'A') {
                f[s[i][j] - 'A']++;
            }
        }
    }
    for (int i = 0;i < 26;i++) {
        if (f[i] >= maxn) {
            maxn = f[i];
        }
    }

    for (int i = 0;i < 26;i++) {
        ans[maxn][i] = i + 'A';
        for (int j = 0;j < maxn - f[i];j++) {
            ans[j][i] = ' ';
        }
        for (int j = maxn - f[i];j < maxn;j++) {
            ans[j][i] = '*';
        }
    }

    for (int i = 0;i < maxn;i++) {
        ind[i] = 0;
        for (int j = 0;j < 26;j++) {
            if (f[j] >= maxn - i) {
                ind[i] = j;
            }
        }

    }
    ind[maxn] = 25;
    for (int i = 0;i <= maxn;i++) {
        for (int j = 0;j <= ind[i];j++) {
            printf("%c ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}