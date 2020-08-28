#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int n;
const int maxn = 120;
string alpos[7] = { "BangZhu","FuBangZhu","HuFa","ZhangLao","TangZhu","JingYing","BangZhong" };
map<string, int> ma;
void init() {
    for (int i = 0;i < 7;i++) {
        ma.insert({ alpos[i],i });
    }
}

int idpos(string& s) {
    if (s == "BangZhu") return 0;
    if (s == "FuBangZhu") return 1;
    if (s == "HuFa") return 1;
    if (s == "ZhangLao") return 1;

}
struct node {
    string name;
    int pos;
    int id;
    int val, level;
    bool operator<(const node& rhs) const {
        if (pos < 2 || rhs.pos < 2) return pos < rhs.pos;
        if (val == rhs.val) return id < rhs.id;
        return val > rhs.val;
    }
}no[maxn];
bool cmp(const node& a, const node& b) {
    if (a.pos == b.pos) {
        if (a.level == b.level) {
            return a.id < b.id;
        }
        return a.level > b.level;
    }
    return a.pos < b.pos;
}
int main() {
    freopen("data.in", "r", stdin);
    init();
    cin >> n;
    string repos;
    for (int i = 0;i < n;i++) {
        cin >> no[i].name;
        cin >> repos;
        no[i].pos = ma[repos];
        cin >> no[i].val >> no[i].level;
        no[i].id = i;
    }
    sort(no, no + n);
    for (int i = 3;i < 5 && i < n;i++) {
        no[i].pos = 2;
    }
    for (int i = 5;i < 9 && i < n;i++) {
        no[i].pos = 3;
    }
    for (int i = 9;i < 16 && i < n;i++) {
        no[i].pos = 4;
    }
    for (int i = 16;i < 41 && i < n;i++) {
        no[i].pos = 5;
    }
    for (int i = 41;i < n;i++) {
        no[i].pos = 6;
    }
    sort(no, no + n, cmp);
    for (int i = 0;i < n;i++) {
        cout << no[i].name << " " << alpos[no[i].pos] << " " << no[i].level << endl;
    }
    return 0;
}