#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> pq;
inline int gett(int a, int b, int c) {

}
int main() {
    int n, m;
    int a, b, c;
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        scanf("%d %d %d", &a, &b, &c);
        int t = gett(a, b, c);
        if (pq.size() < m) {
            pq.push(t);
        }
        else {
            pq.pop();
            pq.push(t);
        }
    }
    for (int i = 0;i < m;i++) {
        printf("%d ", pq.top());
        pq.pop();
    }
}