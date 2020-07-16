#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
int prime[int(2e4 + 5)];
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
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            int tmp = n - i;
            for (int j = 2; j < n; j++)
            {
                if (prime[j] && prime[tmp - j])
                {
                    printf("%d %d %d", i, j, tmp - j);
                    return 0;
                }
            }
        }
    }
    return 0;
}