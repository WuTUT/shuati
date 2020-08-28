#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 258;
char s[maxn];
int main() {
    freopen("data.in", "r", stdin);
    int b = 0, g = 0;
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0;i < len;i++) {
        if (s[i] == 'b') {
            if (i + 1 < len && s[i + 1] == 'o') i++;
            if (i + 1 < len && s[i + 1] == 'y') i++;
            b++;
        }
        else if (s[i] == 'o') {
            if (i + 1 < len && s[i + 1] == 'y') i++;
            b++;
        }
        else if (s[i] == 'y') {
            b++;
        }
        else if (s[i] == 'g') {
            if (i + 1 < len && s[i + 1] == 'i') i++;
            if (i + 1 < len && s[i + 1] == 'r') i++;
            if (i + 1 < len && s[i + 1] == 'l') i++;
            g++;
        }
        else if (s[i] == 'i') {
            if (i + 1 < len && s[i + 1] == 'r') i++;
            if (i + 1 < len && s[i + 1] == 'l') i++;
            g++;
        }
        else if (s[i] == 'r') {
            if (i + 1 < len && s[i + 1] == 'l') i++;
            g++;
        }
        else if (s[i] == 'l') {
            g++;
        }
    }
    printf("%d\n%d\n", b, g);
    return 0;
}