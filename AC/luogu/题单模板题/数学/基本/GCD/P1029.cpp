#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long gcd(long long x, long long y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}
int main()
{
    int x, y;
    cin >> x >> y;
    long long t = 1ll * x * y;
    long long cnt = 0;
    int sqt = sqrt(t);
    for (long long i = x; i <= sqt; i++)
    {
        if (t % i == 0 && gcd(i, t / i) == x)
        {
            cnt++;
        }
    }
    cnt *= 2;
    if (x == y)
        cnt--;
    cout << cnt << endl;
    return 0;
}