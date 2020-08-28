#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
string s;
int main() {
    freopen("data.in", "r", stdin);
    getline(cin, s);
    int cnt = 0;
    for (int i = 0;i < s.length();i++) {
        if (s[i] != ' ' && s[i] != '\n') {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}