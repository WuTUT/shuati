#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
string s;
string u, v;
void deal(string& s) {


    int i = s.length() - 1;
    if (s[i] == '0' && i == 0) {
        cout << 0;
        return;
    }
    else {
        while (s[i] == '0') {
            i--;
        }
        while (i >= 0) {
            printf("%c", s[i]);
            i--;
        }
        return;
    }
}
int main() {
    freopen("data.in", "r", stdin);
    cin >> s;
    int ty = 0;
    int di = 0;
    for (int i = 0;i < s.length();i++) {
        if (s[i] == '.') {
            ty = 1;
            u = s.substr(0, i);
            i++;
            while (s[i] == '0') i++;
            v = s.substr(i);
            break;

        }
        if (s[i] == '/') {
            u = s.substr(0, i);
            v = s.substr(i + 1);
            ty = 2;break;

        }
        if (s[i] == '%') {
            ty = 3;
            u = s.substr(0, s.length() - 1);
            break;
        }
    }
    if (ty == 0) {
        deal(s);
        printf("\n");
    }
    else if (ty == 3) {
        deal(u);
        cout << "%" << endl;
    }
    else if (ty == 2) {
        deal(u);
        printf("/");
        deal(v);
        printf("\n");
    }
    else if (ty == 1) {
        deal(u);
        printf(".");
        if (v.length() == 0) {
            cout << 0;
        }
        else {
            deal(v);
        }

        printf("\n");
    }
    return 0;
}
//数字反转