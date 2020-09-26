#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
const int maxn = 2e5 + 5;
int n;
unordered_map<string, int> ha;
bool cmp(const pair<string, int>& p1, const pair<string, int>& p2) {
    return p1.second < p2.second;

}
int main() {
    freopen("data.in", "r", stdin);
    cin >> n;
    string s;

    for (int i = 1;i <= n;i++) {
        cin >> s;

        ha[s] = n - i;

    }
    vector<pair<string, int>> v;
    for (auto x : ha) {
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto x : v) {
        cout << x.first << endl;
    }
    return 0;
}