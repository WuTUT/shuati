#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
bool pro[14];
int pen[14];
int passn;
int penal;
int n, m;
void init() {
    memset(pro, 0, sizeof pro);
    memset(pen, 0, sizeof pen);
    passn = 0;
    penal = 0;
}
int main() {
    freopen("data.in", "r", stdin);
    int T;
    cin >> T;
    int pi;
    string ti, sta;
    while (T--) {
        init();
        cin >> n >> m;
        for (int i = 1;i <= m;i++) {
            cin >> pi >> ti >> sta;
            pi -= 1000;
            if (sta == "AC") {
                if (!pro[pi]) {
                    pen[pi] += ((ti[0] - '0') * 10 + (ti[1] - '0')) * 60 + (ti[3] - '0') * 10 + (ti[4] - '0');
                    penal += pen[pi];
                    passn++;
                    pro[pi] = true;
                }
            }
            else {
                if (!pro[pi]) {
                    pen[pi] += 20;
                }
            }
        }

        printf("%d %d\n", passn, penal);
    }
    return 0;
}