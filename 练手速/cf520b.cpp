#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n, m;
int inf = 1e5;
bool isvis[int(1e5 + 5)];
int main() {
    scanf("%d %d", &n, &m);
    queue<int> q;
    q.push(n);
    isvis[n] = 1;
    int step = 0;
    while (1) {
        int qsz = q.size();
        for (int i = 0;i < qsz;i++) {
            int x = q.front();q.pop();
            if (x == m) {
                printf("%d\n", step);
                return 0;
            }
            int nxt = x * 2;
            if (nxt < 1e5 && !isvis[nxt]) {
                q.push(nxt);
                isvis[nxt] = 1;
            }
            nxt = x - 1;
            if (nxt > 0 && !isvis[nxt]) {
                q.push(nxt);
                isvis[nxt] = 1;
            }
        }
        step++;
    }
    return 0;
}