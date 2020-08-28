#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 258;
char s[maxn];
int a, b, c;
void func(int i, int& al) {
    if (s[i] == 'a') {
        al = a;
    }
    else if (s[i] == 'b') {
        al = b;
    }
    else if (s[i] == 'c') {
        al = c;
    }
    else {
        al = s[i] - '0';
    }
}
int main() {
    freopen("data.in", "r", stdin);
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0;i < len;i++) {
        if (s[i] == 'a') {
            i += 3;
            func(i, a);
            i++;
        }
        else if (s[i] == 'b') {
            i += 3;
            func(i, b);
            i++;
        }
        else if (s[i] == 'c') {
            i += 3;
            func(i, c);
            i++;
        }
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}