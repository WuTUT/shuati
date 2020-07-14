#include <cstdio>
int x, ans;
int n;
int main()
{
    freopen("data.in", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        ans ^= x;
    }
    printf("%d", ans);
}