#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5005;
typedef long long ll;
int main() {
    freopen("data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {

        ll n;
        cin >> n;
        n--;
        ll K = n / 3;
        K++;
        int le = n % 3;
        le++;

        string s;
        while (K) {
            if (K & 1) {
                s.push_back((le & 1) + '0');
                s.push_back(((le >> 1) & 1) + '0');
            }
            else {
                s.push_back('0');
                s.push_back('0');
            }
            K /= 2;
        }
        reverse(s.begin(), s.end());
        // cout << s << endl;
        bitset<maxn> b(s);
        cout << b.to_ullong() << endl;
    }

    return 0;
}