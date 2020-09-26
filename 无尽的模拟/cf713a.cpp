#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
const int maxn = 18;
typedef long long ll;
unordered_map<string, ll> ha;
string convt(string& a) {

    string ss;
    ss.resize(18);
    for (int i = 0;i < 18 - a.size();i++) {
        ss[i] = '0';
    }
    for (int i = 18 - a.size(), j = 0;i < 18;i++, j++) {
        if ((a[j] - '0') % 2 == 0) {
            ss[i] = '0';
        }
        else
        {
            ss[i] = '1';
        }

    }
    //cout << ss << endl;
    return ss;
}
int main() {
    freopen("data.in", "r", stdin);
    int t;
    cin >> t;
    char ch;
    string a;

    for (int i = 0;i < t;i++) {
        scanf(" %c", &ch);

        if (ch == '+') {
            cin >> a;

            ha[convt(a)]++;

        }
        else if (ch == '-') {
            cin >> a;
            ha[convt(a)]--;
        }
        else {
            cin >> a;
            string ss;
            ss.resize(18);
            for (int i = 0;i < 18;i++) {
                ss[i] = '0';
            }
            for (int i = 0, j = 18 - a.size();i < a.size();i++, j++) {
                ss[j] = a[i];
            }
            // cout << ss << endl;
            cout << ha[ss] << endl;
        }
    }
}
