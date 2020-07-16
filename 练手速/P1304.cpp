#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
int prime[int(1e4 + 5)];
void cal()
{
    for (int i = 2; i <= n; i++)
    {
        bool isprime = true;
        for (int j = 2; j <= floor(sqrt(i) + 0.5); j++)
        {
            if (i % j == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
        {
            prime[i] = 1;
        }
    }
}
int main()
{

    cin >> n;
    cal();
    for (int i = 4; i <= n; i += 2)
    {
        for (int j = 2; j < i; j++)
        {
            if (prime[j] && prime[i - j])
            {
                printf("%d=%d+%d\n", i, j, i - j);
                break;
            }
        }
    }
    return 0;
}