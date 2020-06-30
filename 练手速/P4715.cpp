#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1 << 9 - 1;
int tr[maxn];
int ind[maxn];
int main()
{
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1 << n; i < 1 << (n + 1); i++)
    {
        cin >> tr[i];
        ind[i] = i - (1 << n) + 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1 << i; j < 1 << (i + 1); j++)
        {
            if (tr[j << 1] > tr[j << 1 | 1])
            {
                tr[j] = tr[j << 1];
                ind[j] = ind[j << 1];
            }
            else
            {
                tr[j] = tr[j << 1 | 1];
                ind[j] = ind[j << 1 | 1];
            }
        }
    }
    cout << ind[1] << ind[2] << ind[3] << endl;
    if (tr[1] == tr[2])
        printf("%d\n", ind[3]);
    else
    {
        printf("%d\n", ind[2]);
    }

    return 0;
}