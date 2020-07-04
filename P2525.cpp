#include <iostream>
#include <cstdio>
using namespace std;
int a[10];
int fac[10];
void cal()
{
    fac[0] = 1;
    for (int j = 1; j <= 9; j++)
    {
        fac[j] = fac[j - 1] * j;
    }
}
int main()
{
    int n;
    cin >> n;
    cal();
    a[0] = 0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int tmp = 0;
    for (int)
        return 0;
}