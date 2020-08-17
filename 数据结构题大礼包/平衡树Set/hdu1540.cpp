#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
int n, m;
const int maxn = 50005;
int stk[maxn], top;
int main() {
    freopen("data.in", "r", stdin);

    while (scanf("%d %d", &n, &m) != EOF) {
        char ch;
        top = 0;

        set<int> s;
        s.insert(0), s.insert(n + 1);
        int x;
        for (int i = 1;i <= m;i++) {
            scanf(" %c", &ch);
            if (ch == 'D') {
                scanf("%d", &x);


                stk[++top] = x;
                s.insert(x);

            }
            else if (ch == 'R') {
                s.erase(stk[top]);
                top--;

            }
            else {
                scanf("%d", &x);
                //printf("x:%d\n", x);
                set<int>::iterator l, r;
                l = r = s.lower_bound(x);
                if (*r == x) {
                    printf("0\n");
                }
                else {
                    l--;
                    int ans = *r - *l - 1;
                    printf("%d\n", ans);
                }

            }
        }
    }

    return 0;
}